#include <stdio.h>
#include <math.h>
#include <locale>

const double POISON = -11.3456;
const int POLINOM_DEGREE = 2;
const int ALL_NUMBERS = 12124215;
const int NO_RADICALS = 12788394;
const int ONE_RADICAL = 12341251;
const int TWO_RADICALS = 9876543;




void message (const int event, double x1, double x2)
{
   if( event == ALL_NUMBERS)
        printf( "Любое число является корнем");

    if( event ==  NO_RADICALS)
        printf( "Корней нет");

    if( event == ONE_RADICAL)
        printf( "Один корень %lg", x1);

    if( event == TWO_RADICALS)
        printf( "Два корня %lg и %lg", x1, x2);
}


void logic(double* coefficients)
{
    double discrim = POISON;
    double x1 = POISON, x2 = POISON;

    if(POLINOM_DEGREE == 2)
    {
        if( coefficients[0] == 0)
        {
            if( coefficients[1] == 0)
            {
                if( coefficients[2] == 0)
                {
                    message (ALL_NUMBERS, x1, x2);
                }else
                {
                    message (NO_RADICALS, x1, x2);
                }
            }else{
            	x1 = -coefficients[2]/coefficients[1];
            	message (ONE_RADICAL, x1, x2);
            }
    	}else{
            discrim = coefficients[1] * coefficients[1] 
			- 4 * coefficients[0] * coefficients[2];
           if( discrim < 0)
        	{
                message (NO_RADICALS, x1, x2);
            }
            else
            {
                x1 = (-coefficients[1] + sqrt(discrim) )/ 2/coefficients[0];
                x2 = (-coefficients[1] - sqrt(discrim) )/ 2/coefficients[0];
                if( discrim == 0)
                {
                    message (ONE_RADICAL, x1, x2);
                }else
                {

                    message (TWO_RADICALS, x1, x2);
                }
            }
        }


    }
}

void scan(double* coefficients)
{
    for(int i = 0; i < POLINOM_DEGREE+1; i++)
        scanf("%lg", &coefficients[i]);
    logic(coefficients);
}

int main()
{
    setlocale(LC_ALL,"Russian");
    double polinomal_coefficiens[POLINOM_DEGREE+1];


    for (int i = 0; i < POLINOM_DEGREE + 1; i++ )
    {
        polinomal_coefficiens[i] = POISON;
    }

    scan(polinomal_coefficiens);
    return 0;
}
