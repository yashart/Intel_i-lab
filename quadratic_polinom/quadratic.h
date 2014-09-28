//{========================================================================
//solves quadratic equation ax^2 + bx + c = 0 .
//@param events             events is type of equation for message function
//@param POLINOM_DEGREE     it is a degree of polinom (Now i can solve only linear and quadratic equation).
//
//@param[out] radicals      radicals is struct, which has radicals
//
//https://github.com/yashart/Intel_i-lab/tree/master/quadratic_polinom
//yashart@mail.ru
//Yashukhin Artem 413 group, 2014
//}========================================================================


#ifndef GLOBALCONSTANTS_H_INCLUDED
#define GLOBALCONSTANTS_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include<math.h>


enum events { ALL_NUMBERS, NO_RADICALS, ONE_RADICAL, TWO_RADICALS, TWO_RADICALS_2};


const int POLINOM_DEGREE = 2;

struct radicals
{
    double x1,x2;
};

void radicals_construction(struct radicals* r);

double discrim_counting(double* coefficients);

radicals radicals_counting(events event, double* coefficients, radicals* r);

void message (events event, radicals r);

void logic(double* coefficients, radicals* r);
void scan(double* coefficients);

#endif // GLOBALCONSTANTS_H_INCLUDED
