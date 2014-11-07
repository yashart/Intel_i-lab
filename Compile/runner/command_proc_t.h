#ifndef COMMAND_PROC_T_H_INCLUDED
#define COMMAND_PROC_T_H_ICLUDED
enum command_proc_t
{
#define command_list(name,number) \
    name = number,
#include "../command_list.h"
#undef command_list
    maxelem
};
#endif