//{=================================================================================
//!         @file    main.cpp
//!         @date    2014 - 2015 year
//!         @author  Yashukhin Artem
//!
//!         Example of work calculator and stack
//!
//}=================================================================================

#include "My_calk.h"
int main()
{
    stack st;;
    stackConstructor(&st);
    long long int i = 0;
    for(i = 0; i<500000000 ;i++)
    {
        stackPush(&st, 5);
        if (i%1000 == 0)
        {
            //printf("%Ld ",i);
        }
        if(i > 10239)
        {
            //stackDump(&st);
        }
    }
    printf("%Ld /n 2 гб",i);
    return 0;
}