#include "disasm.h"

int main()
{
    char* textBuffer = NULL;
    long length = 0;
    MY_ERRNO = read_file("input.txt", &textBuffer, &length);
    MY_ERRNO = disassembler(&textBuffer, &length);
    MY_ERRNO = write_file("output.txt", &textBuffer, length);
    return 0;
}
