#include <stdlib.h>
#include <stdio.h>
#include "commands.h"


errors procCommandCtor(procCommand* command)
{

    command->value = (int*) calloc(command->commandQuantity, sizeof(*(command->value)));
    for (int i = 0; i < command->commandQuantity; i++)
    {
        command->name[i] = (char*) calloc(10, sizeof(char));
    }
}

errors scanAllCommands(procCommand *command)
{

    FILE* file = NULL;
    file = fopen("Commands.txt", "r");
    if (!file)
    {
        MY_ERRNO = FILE_NO_OPEN;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }
    if(command == NULL)
    {
        MY_ERRNO = BAD_MALLOC;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }
    int number = 0;
    for (int i = 0; i < command->commandQuantity; i++)
    {
        fscanf (file, "%s", command->name[i]);
        if(fscanf (file, "%d", &number) == 0)
        {
            MY_ERRNO = BAD_FILE;
            PLEASE_KILL_MY_VERY_BAD_FUNCTION
        }
        command->value[i] = number;
    }
    fclose(file);
    return MY_ERRNO;
}