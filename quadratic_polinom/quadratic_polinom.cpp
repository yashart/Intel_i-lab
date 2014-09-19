#include <stdio.h>
#include <math.h>
#include <locale.h>
#include "GlobalConstants.h"

#define POISON NAN


#define POLINOM_DEGREE 2

double discrim_counting(double* coefficients)
{
    return coefficients[1] * coefficients[1] - 4 * coefficients[0] * coefficients[2];
}

double radicals_counting(events event, double* coefficients)
{
    if(event == ONE_RADICAL)
    {
        return -coefficients[2] / coefficients[1];
    }

    if(event == TWO_RADICALS)
    {
        return (-coefficients[1] - sqrt(discrim_counting(coefficients)) )/ 2/coefficients[0];
    }

    if(event == TWO_RADICALS_2)
    {
        return (-coefficients[1] + sqrt(discrim_counting(coefficients)) )/ 2/coefficients[0];
    }
    return POISON;
}



void message (events event, double x1, double x2)
{
    if( event == ALL_NUMBERS)
        printf( "Any number is radical");

    if( event ==  NO_RADICALS)
        printf( "No radicals");

    if( event == ONE_RADICAL)
        printf( "One radical %lg", x1);

    if( event == TWO_RADICALS)
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
                    message (ALL_NUMBERS, POISON, POISON);
                }
                else
                {
                    message (NO_RADICALS, POISON, POISON);
                }
            }
            else
            {

                message (ONE_RADICAL, radicals_counting(ONE_RADICAL,coefficients), POISON);
            }
        }
        else
        {
            discrim = discrim_counting(coefficients);
            if( discrim < 0)
            {
                message (NO_RADICALS, POISON, POISON);
            }
            else
            {

                if( discrim == 0)
                {
                    message (ONE_RADICAL, radicals_counting (TWO_RADICALS, coefficients ),
                             POISON );
                }
                else
                {
                    message (TWO_RADICALS, radicals_counting (TWO_RADICALS, coefficients ),
                             radicals_counting(TWO_RADICALS_2, coefficients ) );
                }
            }
        }


    }
}

void scan(double* coefficients)
{
    double right_scan = POISON;
    for(int i = 0; i < POLINOM_DEGREE+1; i++)
    {
        printf( "Write the %d-st polinomal coefficients of %d polinom by a space \n",i+1 ,POLINOM_DEGREE + 1);

        right_scan = scanf("%lg[0-9]", &coefficients[i]);
        fflush(stdin);
        while(getchar() != 10);
        if(right_scan == 0)
        {
            i--;

        }

        right_scan = POISON;
    }

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

