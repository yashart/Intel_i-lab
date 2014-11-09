#include "../errors.h"
#include "../fileworking.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../commands.h"

char* labelToStr(long **labels, int number);

errors preassembler(char **textBuffer, long *length);

errors assembler(char **textBuffer, long *length);
