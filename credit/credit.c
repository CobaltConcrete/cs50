// check what kind of credit card (AMEX/MASTERCARD/VISA) given a credit card number

#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

long sum1(long x);
long sum2(long x);
bool luhn(long x);

int main(void)
{
    long x, z;


    x = get_long("Number: ");

    if (luhn(x))
    {
        if ((x >= 34*pow(10, 13) && x < 35*pow(10, 13)) || (x >= 37*pow(10, 13) && x < 38*pow(10, 13)))
        {
             printf("AMEX\n");
        }
        else if (x >= 51*pow(10, 14) && x < 56*pow(10, 14))
        {
            printf("MASTERCARD\n");
        }
        else if ((x >= 4*pow(10, 12) && x < 5*pow(10, 12)) || (x >= 4*pow(10, 15) && x < 5*pow(10, 15)))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}

long sum1(long x)
{
    int i = 0;
    long y, z;

    if (x < 10)
    {
        return 0;
    }

    else
    {
        z = 2 * ((x / 10) % 10);
        return z/10 + z%10 + sum1(x / 100);
    }
}

long sum2(long x)
{
    if (x == 0)
    {
        return x;
    }
    else
    {
        long y = x % 10;
        return y + sum2(x / 100);
    }
}

bool luhn(long x)
{
    if ((sum1(x) + sum2(x)) % 10 == 0)
    {
        return true;
    }
    return false;
}
