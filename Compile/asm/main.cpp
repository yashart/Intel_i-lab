#include "asm.h"

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
