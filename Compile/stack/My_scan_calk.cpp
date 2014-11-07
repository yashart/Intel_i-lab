#include "My_scan_calk.h"


FILE *createFile() {
    return fopen("book.txt", "rb");

}

void readFile(stack *stk, FILE* program) {
    char command = '0';
    errors STACK_ERRNO = OK;

    while (fscanf(program, "%c", &command))
    {

        switch (command)
        {
            case 'c':
            {
                stackConstructor(stk);
                break;
            }
            case 'd':
            {
                stackDestruct(stk);
                break;
            }
            case 'p':
            {
                if(!fscanf(program,"%d", &command))
                {

                    stackDump(stk);
                    break;
                }
                stackPush(stk, command);
                break;
            }
            case 'm':
            {
                stackPop(stk);
                break;
            }
            case 'u':
            {
                stackDump(stk);
                break;
            }
            case '+':
            {
                stackAdd(stk);
                break;
            }
            default: break;
        }
    }

}

void deleteFile(FILE* text) {
    free(text);
    text = NULL;
}
