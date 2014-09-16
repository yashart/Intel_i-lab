#include <stdio.h>
#include <math.h>
#include <locale.h>
#include "GlobalConstants.h"

#define POISON -11.3456


#define POLINOM_DEGREE 2

double discrim_counting(double* coefficients)
{
    return coefficients[1] * coefficients[1] - 4 * coefficients[0] * coefficients[2];
}

double radicals_counting(const int event, double* coefficients)
{
    if(event == evnt::ONE_RADICAL)
    {
        return -coefficients[2] / coefficients[1];
    }

    if(event == 1*evnt::TWO_RADICALS)
    {
        return (-coefficients[1] - sqrt(discrim_counting(coefficients)) )/ 2/coefficients[0];
    }

    if(event == 2*evnt::TWO_RADICALS)
    {
        return (-coefficients[1] + sqrt(discrim_counting(coefficients)) )/ 2/coefficients[0];
    }
    return POISON;
}



void message (const int event, double x1, double x2)
{
    if( event == evnt::ALL_NUMBERS)
        printf( "Any number is radical");

    if( event ==  evnt::NO_RADICALS)
        printf( "No radicals");

    if( event == evnt::ONE_RADICAL)
        printf( "One radical %lg", x1);

    if( event == evnt::TWO_RADICALS)
        printf( "Two radicals %lg и %lg", x1, x2);
}

void logic(double* coefficients)
{
    double discrim = POISON;

    if(POLINOM_DEGREE == 2)
    {
        if( coefficients[0] == 0)
        {
            if( coefficients[1] == 0)
            {
                if( coefficients[2] == 0)
                {
                    message (evnt::ALL_NUMBERS, POISON, POISON);
                }
                else
                {
                    message (evnt::NO_RADICALS, POISON, POISON);
                }
            }
            else
            {

                message (evnt::ONE_RADICAL, radicals_counting(evnt::ONE_RADICAL,coefficients), POISON);
            }
        }
        else
        {
            discrim = discrim_counting(coefficients);
            if( discrim < 0)
            {
                message (evnt::NO_RADICALS, POISON, POISON);
            }
            else
            {

                if( discrim == 0)
                {
                    message (evnt::ONE_RADICAL, radicals_counting (evnt::TWO_RADICALS, coefficients ),
                             POISON );
                }
                else
                {
                    message (evnt::TWO_RADICALS, radicals_counting (evnt::TWO_RADICALS, coefficients ),
                             radicals_counting(2 * evnt::TWO_RADICALS, coefficients ) );
                }
            }
        }


    }
}

void scan(double* coefficients)
{
    printf( "Write a %d polinomal coefficients by a space \n", POLINOM_DEGREE + 1);
    for(int i = 0; i < POLINOM_DEGREE+1; i++)
        scanf("%lg", &coefficients[i]);
    logic(coefficients);
}

int main()
{
    double polinomal_coefficiens[POLINOM_DEGREE+1];


    for (int i = 0; i < POLINOM_DEGREE + 1; i++ )
    {
        polinomal_coefficiens[i] = POISON;
    }

    scan(polinomal_coefficiens);
    return 0;
}

