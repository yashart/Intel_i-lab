#include "../errors.h"
#include "asm.h"
#include "../fileworking.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    char* textBuffer = NULL;
    long length = 0;
    MY_ERRNO = read_file("asm.txt", &textBuffer, &length);
    MY_ERRNO = preassembler(&textBuffer, &length);
    MY_ERRNO = assembler(&textBuffer, &length);
    MY_ERRNO = write_file("disasm.txt", &textBuffer, length);
    return 0;
}

char* labelToStr(long **labels, int number) {
    long* localLabel = *labels;
    long label = localLabel[number];
    char* labelStr = (char*) calloc(1, sizeof(*labelStr));
    if(!labelStr)
    {
        MY_ERRNO = BAD_MALLOC;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }
    int strLength = 0;
    for (strLength; label != 0; strLength++)
    {
        labelStr[strLength] = char('0' + (int)label % 10);
        label /= 10;
        labelStr = (char*) realloc(labelStr, (strLength + 2)* sizeof(*labelStr));
    }
    char *transponStr = NULL;
    transponStr = (char*) calloc(strLength + 1, sizeof(*transponStr));
    for(int i = 0; i < strLength; i++)
    {
        transponStr[i] = labelStr[strLength - 1 - i];
    }
    return transponStr;
}

errors preassembler(char **textBuffer, long *length)
{
    long pointerPosition = 0;
    long preasmLength = 0;

    char *localBuffer = *textBuffer;
    if (!localBuffer)
    {
        MY_ERRNO = BAD_MALLOC;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }

    char *preasmFile = NULL;
    preasmFile = (char *) calloc(*length, sizeof(*preasmFile));
    if (!preasmFile)
    {
        MY_ERRNO = BAD_MALLOC;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }
    char symbol[2] = {};
    long* labels = (long*) calloc(10, sizeof(*labels));
    long commandNumber = 0; //label point
    bool isCommand = true;
    for(pointerPosition; pointerPosition < *length; pointerPosition++) {
        if (strstr(&localBuffer[pointerPosition], "label") == &localBuffer[pointerPosition]) {
            pointerPosition += strlen("label");
            while (((localBuffer[pointerPosition]) < '0') || ((localBuffer[pointerPosition]) > '9')) {
                pointerPosition++;
            }
            labels[localBuffer[pointerPosition] - '0'] = commandNumber;
            continue;
        }
        #define command_list(name,value) \
        if(strstr(&localBuffer[pointerPosition], #name) == &localBuffer[pointerPosition]) \
            {\
                isCommand = true;\
                commandNumber++; \
                pointerPosition += strlen(#name); \
                continue; \
            }
        #include "../command_list.h"
        if(isCommand)
            commandNumber++;
        isCommand = false;
        #undef command_list
    }
    printf("%s\n%d\n", localBuffer, labels[1]);

    for(pointerPosition = 0; pointerPosition < *length; pointerPosition++) {
        if(strstr(&localBuffer[pointerPosition], ":") == &localBuffer[pointerPosition])
        {
            pointerPosition++;
            preasmFile = strcat(preasmFile, labelToStr(&labels, localBuffer[pointerPosition] - '0'));
            preasmLength += strlen(labelToStr(&labels, localBuffer[pointerPosition] - '0'));
            continue;
        }
        symbol[0] = localBuffer[pointerPosition];
        preasmFile = strcat(preasmFile, symbol);
        preasmLength ++;
    }
    free(*textBuffer);
    *textBuffer = preasmFile;
    *length = preasmLength;

    return MY_ERRNO;
}

errors assembler(char **textBuffer, long *length)
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
    disasmFile = (char*) calloc(*length, sizeof(*disasmFile));
    if(!disasmFile)
    {
        MY_ERRNO = BAD_MALLOC;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }

    #define command_list(name,value) \
    if(strstr(&localBuffer[pointerPosition], #name) == &localBuffer[pointerPosition]) \
    {\
        disasmFile = strcat(disasmFile, #value); \
        pointerPosition += strlen(#name) - 1; \
        disasmLength += strlen(#value); \
        continue; \
    }
    char symbol[2] = {};
    for(pointerPosition; pointerPosition < *length; pointerPosition++)
    {
        #include "../command_list.h"
        if(strstr(&localBuffer[pointerPosition], "label") == &localBuffer[pointerPosition])
            {
                while (((localBuffer[pointerPosition]) < '0') || ((localBuffer[pointerPosition]) > '9')) {
                    pointerPosition++;
                }
                continue;
            }
        symbol[0] = localBuffer[pointerPosition];
        disasmFile = strcat(disasmFile, symbol);
        disasmLength++;
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
