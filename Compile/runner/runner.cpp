#include "runner.h"

const char* INPUT_FILE_NAME = "disasm.txt";

errors runnerConstruction(runner *proc)
{
    STACK_ERRNO      = stackConstructor(&(proc->programStk));
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

    for (fileLength = 0; fscanf (file, "%d", &command[fileLength]) != EOF; fileLength++)
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
    command_proc_t command = maxelem;
    for (; proc->pointer < proc->programLen; proc->pointer++)
    {
        command = (command_proc_t) proc->program[proc->pointer];
        switch (command)
        {
            case push_ax:
            {
                stackPush(&(proc->programStk), proc->AX);
                break;
            }
            case push_bx:
            {
                stackPush(&(proc->programStk), proc->BX);
                break;
            }
            case push_cx:
            {
                stackPush(&(proc->programStk), proc->CX);
                break;
            }
            case push_dx:
            {
                stackPush(&(proc->programStk), proc->DX);
                break;
            }
            case push_ex:
            {
                stackPush(&(proc->programStk), proc->EX);
                break;
            }
            case push:
            {
                proc->pointer++;
                stackPush(&(proc->programStk), proc->program[proc->pointer]);
                break;
            }

            case pop_ax:
            {
                proc->AX = stackPop(&(proc->programStk));
                break;
            }
            case pop_bx:
            {
                proc->BX = stackPop(&(proc->programStk));
                break;
            }
            case pop_cx:
            {
                proc->CX = stackPop(&(proc->programStk));
                break;
            }
            case pop_dx:
            {
                proc->DX = stackPop(&(proc->programStk));
                break;
            }
            case pop_ex:
            {
                proc->EX = stackPop(&(proc->programStk));
                break;
            }
            case pop:
            {
                stackPop(&(proc->programStk));
                break;
            }

            case add:
            {
                stackAdd(&(proc->programStk));
                break;
            }
            case sub:
            {
                stackSub(&(proc->programStk));
                break;
            }
            case mul:
            {
                stackMul(&(proc->programStk));
                break;
            }
            case del:
            {
                stackDel(&(proc->programStk));
                break;
            }

            case ja:
            {
                proc->pointer++;
                if(stackPop(&(proc->programStk)) > stackPop(&(proc->programStk)))
                {
                    proc->pointer = proc->program[proc->pointer];
                }
                break;
            }
            case jae:
            {
                proc->pointer++;
                if(stackPop(&(proc->programStk)) >= stackPop(&(proc->programStk)))
                {
                    proc->pointer = proc->program[proc->pointer];
                }
                break;
            }
            case jb:
            {
                proc->pointer++;
                if(stackPop(&(proc->programStk)) < stackPop(&(proc->programStk)))
                {
                    proc->pointer = proc->program[proc->pointer];
                }
                break;
            }
            case jbe:
            {
                proc->pointer++;
                if(stackPop(&(proc->programStk)) <= stackPop(&(proc->programStk)))
                {
                    proc->pointer = proc->program[proc->pointer];
                }
                break;
            }
            case je:
            {
                proc->pointer++;
                if(stackPop(&(proc->programStk)) == stackPop(&(proc->programStk)))
                {
                    proc->pointer = proc->program[proc->pointer];
                }
                break;
            }
            case jne:
            {
                proc->pointer++;
                if(stackPop(&(proc->programStk)) != stackPop(&(proc->programStk)))
                {
                    proc->pointer = proc->program[proc->pointer];
                }
                break;
            }
            case jmp:
            {
                proc->pointer++;
                proc->pointer = proc->program[proc->pointer];
                break;
            }
            case out:
            {
                printf("%d\n", stackPop(&(proc->programStk)));
                break;
            }
        }
    }
}