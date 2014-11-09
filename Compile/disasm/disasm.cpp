#include "disasm.h"
#include "../commands.h"

errors disassembler(char **textBuffer, long *length)
{
    long pointerPosition = 0;
    long disasmLength    = 0;

    char* localBuffer = (*textBuffer);

    if(!localBuffer)
    {
        MY_ERRNO = BAD_MALLOC;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }

    char* disasmFile = NULL;
    disasmFile = (char*) calloc(*length  * 10, sizeof(*disasmFile));
    if(!disasmFile)
    {
        MY_ERRNO = BAD_MALLOC;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }
    bool isFunction = true;
    procCommand asmbler;
    procCommandCtor(&asmbler);
    scanAllCommands(&asmbler);
    bool findFuncktion = false;
    char symbol[2] = {};
    int uses_command = -1;
    for(pointerPosition; pointerPosition < *length; pointerPosition++)
    {
        if(!isFunction)
        {
            while(((symbol[0] != ' ')&&(symbol[0] != '\n'))&&(pointerPosition < *length))
            {
                symbol[0] = localBuffer[pointerPosition];
                disasmFile = strcat(disasmFile, symbol);
                disasmLength++;
                pointerPosition++;
            }
            isFunction = true;
        }
        findFuncktion = false;
        for(int i = 0; i < asmbler.commandQuantity; i++)
        {
            sscanf(&localBuffer[pointerPosition], "%d", &uses_command);
            printf("%d", uses_command);

            if(uses_command == asmbler.value[i])
            {
                uses_command = 0;
                disasmFile = strcat(disasmFile, asmbler.name[i]);
                disasmFile = strcat(disasmFile, " ");
                pointerPosition += 2;
                disasmLength += strlen(asmbler.name[i]);
                if((asmbler.value[i] / 10 == 4)||(strstr(asmbler.name[i] , "push")))
                {
                    isFunction = false;
                }
                findFuncktion = true;
                break;
            }
        }
        if(isFunction)
            continue;
        symbol[0] = localBuffer[pointerPosition];
        disasmFile = strcat(disasmFile, symbol);
        disasmLength++;
        symbol[0] = 0;
    }
    *length = disasmLength;
    free(*textBuffer);
    *textBuffer = disasmFile;
    if(!*textBuffer)
    {
        MY_ERRNO = BAD_MALLOC;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }
    return MY_ERRNO;
}
