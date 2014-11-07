#include "runner.h"
int main()
{
    runner proc;
    runnerConstruction(&proc);
    runnerInterpretetator(&proc);

    stackDump(&proc.programStk);

    return 0;
}