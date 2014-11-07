#include "disasm.h"

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
#define command_list(name,value) \
    if(strstr(&localBuffer[pointerPosition], #value) == &localBuffer[pointerPosition]) \
    {\
        disasmFile = strcat(disasmFile, #name); \
        disasmFile = strcat(disasmFile, " ");\
        pointerPosition += strlen(#value); \
        disasmLength += strlen(#name); \
        printf("%c ", #value[0]); \
        if((value / 10 == 4)||(#name == "push")) \
        { \
            isFunction = false; \
        } \
        continue; \
    }
    char symbol[2] = {};
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
    #include "../command_list.h"
        symbol[0] = localBuffer[pointerPosition];
        disasmFile = strcat(disasmFile, symbol);
        disasmLength++;
        symbol[0] = 0;
    }
#undef command_list
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
