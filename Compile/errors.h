#ifndef ERRORS_H_INCLUDED
#define ERRORS_H_INCLUDED
enum errors
{
#define errorsdata(name, value) name = value,
#include "errors_data.h"
#undef errorsdata
        MAXERROR
};
extern errors MY_ERRNO;
void dump(const errors ERROR, const char *FUNCTION_NAME, const int LINE, const char *FILE, const bool kill);

#define PLEASE_KILL_MY_VERY_BAD_FUNCTION dump(MY_ERRNO, __PRETTY_FUNCTION__, __LINE__, __FILE__, true);
#define PLEASE_DONT_KILL_MY_VERY_BAD_FUNCTION dump(MY_ERRNO, __PRETTY_FUNCTION__, __LINE__, __FILE__, false);
#endif