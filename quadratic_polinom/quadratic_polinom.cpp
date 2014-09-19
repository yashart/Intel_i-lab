#include <stdio.h>
#include <math.h>
#include <locale.h>
#include "quadratic.h"



struct radicals;

void radicals_destruction(struct radicals* r);

double discrim_counting(double* coefficients);

radicals radicals_counting(events event, double* coefficients, radicals* r);

void message (events event, radicals r);

void logic(double* coefficients, radicals* r);

void scan(double* coefficients);

int main()
{
    double polinomal_coefficiens[POLINOM_DEGREE+1];
    radicals r;
    radicals_destruction(&r);

    for (int i = 0; i < POLINOM_DEGREE + 1; i++ )
    {
        polinomal_coefficiens[i] = POISON;
    }

    scan(polinomal_coefficiens);
    logic(polinomal_coefficiens, &r);
    return 0;
}
