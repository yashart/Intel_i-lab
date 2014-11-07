#include "fileworking.h"
#include <stdio.h>
#include <stdlib.h>

errors MY_ERRNO = OK;

errors read_file(const char *filename, char **outputBuffer, long *length)
{
    FILE* file = NULL;
    file = fopen(filename, "rb");
    if (!file)
    {
        MY_ERRNO = FILE_NO_OPEN;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }
    fseek (file, 0, SEEK_SET);
    *length = 0;
    fseek (file, 0, SEEK_END);
    *length = ftell(file);
    fseek (file, 0, SEEK_SET);
    if (!*length)
    {
        MY_ERRNO = NULL_LENGTH;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }
    *outputBuffer = (char*) calloc(*length, sizeof(*outputBuffer));
    if (!*outputBuffer)
    {
        MY_ERRNO = BAD_MALLOC;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }
    if(fread (*outputBuffer, 1, *length, file) != *length)
    {
        MY_ERRNO = BAD_FILE;
        PLEASE_DONT_KILL_MY_VERY_BAD_FUNCTION
    }
    fclose(file);
    return MY_ERRNO;
}

errors write_file(const char *filename, char **outputBuffer, long const length)
{
    FILE* file = NULL;
    file = fopen(filename, "w");
    if (!file)
    {
        MY_ERRNO = FILE_NO_OPEN;
        PLEASE_KILL_MY_VERY_BAD_FUNCTION
    }

    if(fwrite (*outputBuffer, 1, length, file) != length)
    {
        MY_ERRNO = BAD_FILE;
        PLEASE_DONT_KILL_MY_VERY_BAD_FUNCTION
    }

    fclose(file);
    return MY_ERRNO;
}