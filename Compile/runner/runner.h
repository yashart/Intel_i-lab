#include "../errors.h"
#include "../fileworking.h"
#include "../stack/My_calk.h"
#include "command_proc_t.h"

struct runner
{
    stack programStk;
    stackData AX;
    stackData BX;
    stackData CX;
    stackData DX;
    stackData EX;
    long pointer;
    long programLen;
    stackData* program;
};

extern const char* INPUT_FILE_NAME;

stackData * scanFile(long *length);

errors runnerConstruction(runner *proc);

errors runnerInterpretetator(runner *proc);