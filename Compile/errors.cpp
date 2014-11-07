#include "errors.h"
#include <stdio.h>
#include <assert.h>

void dump(const errors ERROR, const char* FUNCTION_NAME, const int LINE, const char* FILE, const bool kill)
{
    const char* ERROR_NAME = "0";
    #define errorsdata(name,value)\
     if(value == ERROR){\
        ERROR_NAME = #name;\
     }
    #include "errors_data.h"
    #undef errorsdata
    printf("ERROR!!! %s in %s file in %s line: %d", ERROR_NAME, FILE, FUNCTION_NAME, LINE);
    if(kill)
        assert(0);
}