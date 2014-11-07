#include "disasm.h"

int main()
{
    char* textBuffer = NULL;
    long length = 0;
    MY_ERRNO = read_file("disasm.txt", &textBuffer, &length);
    MY_ERRNO = disassembler(&textBuffer, &length);
    MY_ERRNO = write_file("asm.txt", &textBuffer, length);
    return 0;
}
