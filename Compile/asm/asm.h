#include "../errors.h"

char* labelToStr(long **labels, int number);

errors preassembler(char **textBuffer, long *length);

errors assembler(char **textBuffer, long *length);
