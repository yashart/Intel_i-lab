#include "runner.h"
#include "../commands.h"
#include <string.h>

const char* INPUT_FILE_NAME = "input.txt";

errors runnerConstruction(runner *proc)
{
    STACK_ERRNO      = stackConstructor(&(proc->programStk));
    if(STACK_ERRNO != OK)
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    STACK_ERRNO      = stackConstructor(&(proc->functionStk));
    proc->program    = NULL;
    proc->programLen = 0;
    proc->pointer    = 0;
    proc->program    = scanFile(&(proc->programLen));
    return OK;
}

stackData *scanFile(long *length) {
    FILE* file = NULL;
    file = fopen(INPUT_FILE_NAME, "r");
    if(!file)
    {
        MY_ERRNO = FILE_NO_OPEN;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }
    stackData* command = NULL;
    command = (stackData*) realloc(command, sizeof(*command));
    long fileLength = 0;

    for (fileLength = 0; fscanf (file, "%lg", &command[fileLength]) != EOF; fileLength++)
    {
        command = (stackData*) realloc(command, (fileLength + 2) * sizeof (*command));
    }
    *length = fileLength;

    *length = fileLength;
    fclose(file);
    return command;
}

errors runnerInterpretetator(runner *proc)
{
    procCommand asmbler;
    procCommandCtor(&asmbler);
    scanAllCommands(&asmbler);
    int commandNumber = 0;
    for (; proc->pointer < proc->programLen; proc->pointer++)
    {
        for(commandNumber = 0; ((commandNumber < asmbler.commandQuantity) &&(asmbler.value[commandNumber] != proc->program[proc->pointer])); commandNumber++);
            if(strstr(asmbler.name[commandNumber], "push_ax"))
            {
                stackPush(&(proc->programStk), proc->AX);
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "push_bx"))
            {
                stackPush(&(proc->programStk), proc->BX);
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "push_cx"))
            {
                stackPush(&(proc->programStk), proc->CX);
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "push_dx"))
            {
                stackPush(&(proc->programStk), proc->DX);
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "push_ex"))
            {
                stackPush(&(proc->programStk), proc->EX);
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "push"))
            {
                proc->pointer++;
                stackPush(&(proc->programStk), proc->program[proc->pointer]);
                continue;
            }

            if(strstr(asmbler.name[commandNumber], "pop_ax"))
            {
                proc->AX = stackPop(&(proc->programStk));
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "pop_bx"))
            {
                proc->BX = stackPop(&(proc->programStk));
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "pop_cx"))
            {
                proc->CX = stackPop(&(proc->programStk));
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "pop_dx"))
            {
                proc->DX = stackPop(&(proc->programStk));
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "pop_ex"))
            {
                proc->EX = stackPop(&(proc->programStk));
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "pop"))
            {
                stackPop(&(proc->programStk));
                continue;
            }

            if(strstr(asmbler.name[commandNumber], "add"))
            {
                stackAdd(&(proc->programStk));
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "sub"))
            {
                stackSub(&(proc->programStk));
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "mul"))
            {
                stackMul(&(proc->programStk));
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "del"))
            {
                stackDel(&(proc->programStk));
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "Sqrt"))
            {
                stackSqrt(&(proc->programStk));
                continue;
            }

            if(strstr(asmbler.name[commandNumber], "ja"))
            {
                proc->pointer++;
                if(stackPop(&(proc->programStk)) > stackPop(&(proc->programStk)))
                {
                    proc->pointer = (int)proc->program[(long)proc->pointer] - 1;
                }
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "jae"))
            {
                proc->pointer++;
                if(stackPop(&(proc->programStk)) >= stackPop(&(proc->programStk)))
                {
                    proc->pointer = (int)proc->program[(long)proc->pointer] - 1;
                }
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "jb"))
            {
                proc->pointer++;
                if(stackPop(&(proc->programStk)) < stackPop(&(proc->programStk)))
                {
                    proc->pointer = (int)proc->program[(long)proc->pointer] - 1;
                }
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "jbe"))
            {
                proc->pointer++;
                if(stackPop(&(proc->programStk)) <= stackPop(&(proc->programStk)))
                {
                    proc->pointer = (int)proc->program[(long)proc->pointer] - 1;
                }
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "je"))
            {
                proc->pointer++;
                if(stackPop(&(proc->programStk)) == stackPop(&(proc->programStk)))
                {
                    proc->pointer = (int)proc->program[(long)proc->pointer] - 1;
                }
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "jne"))
            {
                proc->pointer++;
                if(stackPop(&(proc->programStk)) != stackPop(&(proc->programStk)))
                {
                    proc->pointer = (int)proc->program[(long)proc->pointer] - 1;
                }
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "jmp"))
            {
                proc->pointer++;
                proc->pointer = (int)proc->program[(long)proc->pointer] - 1;
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "call"))
            {
                proc->pointer++;
                stackPush(&proc->functionStk, proc->pointer+1);
                proc->pointer = (int)proc->program[(long)proc->pointer] - 1;
                continue;
            }

            if(strstr(asmbler.name[commandNumber], "out"))
            {
                printf("%lg\n", stackPop(&(proc->programStk)));
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "ret"))
            {
                proc->pointer = stackPop(&proc->functionStk);
                continue;
            }
            if(strstr(asmbler.name[commandNumber], "end"))
            {
                proc->pointer = proc->programLen;
                continue;
            }
    }
    return OK;
}
