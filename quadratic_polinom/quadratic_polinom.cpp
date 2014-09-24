#include <stdio.h>
#include <math.h>
<<<<<<< HEAD
#include "quadratic.h"

=======
#include <locale.h>
#include "quadratic.h"



struct radicals;

void radicals_destruction(struct radicals* r);

double discrim_counting(double* coefficients);

radicals radicals_counting(events event, double* coefficients, radicals* r);

void message (events event, radicals r);

void logic(double* coefficients, radicals* r);

void scan(double* coefficients);
>>>>>>> origin/master

int main()
{
    double polinomal_coefficiens[POLINOM_DEGREE+1];
    radicals r;
<<<<<<< HEAD
    radicals_construction(&r);
=======
    radicals_destruction(&r);
>>>>>>> origin/master

    for (int i = 0; i < POLINOM_DEGREE + 1; i++ )
    {
        polinomal_coefficiens[i] = NAN;
    }

    scan(polinomal_coefficiens);
    logic(polinomal_coefficiens, &r);
    return 0;
}
