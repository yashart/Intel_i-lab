#include "errors.h"
struct procCommand
{
    static const int commandQuantity = 29;
    char* name[commandQuantity];
    int* value;
};
errors procCommandCtor(procCommand* command);

errors scanAllCommands(procCommand *command);