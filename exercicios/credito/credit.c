#include <cs50.h>
#include <math.h>
#include <stdio.h>

int num_digits(long num_card);
int first_digits(long num_card, int number_of_digits);
int multiply(long num_card);
int add(long num_card);
int verification(int result, int two_first_digits, int number_of_digits);

int main(void)
{
    long num_card = get_long("Number: ");
    int number_of_digits = num_digits(num_card);
    int two_first_digits = first_digits(num_card, number_of_digits);
    int multiplication = multiply(num_card);
    int sum = add(num_card);

    int result = multiplication + sum;

    verification(result, two_first_digits, number_of_digits);
}

// funções
// conta dígitos do cartão
int num_digits(long num_card)
{
    int num_digits = 0;
    while (num_card > 0)
    {
        num_card /= 10;
        num_digits++;
    }
    return num_digits;
}

int first_digits(long num_card, int number_of_digits)
{
    int first_digits = num_card / pow(10, number_of_digits - 2);

    return first_digits;
}

int multiply(long num_card)
{
    int multiplication = 0;
    int operation;
    while (num_card > 0)
    {
        num_card /= 10;
        operation = (num_card % 10) * 2;
        if (operation > 9)
        {
            operation = (operation % 10) + (operation / 10);
        }
        multiplication = operation + multiplication;
        num_card /= 10;
    }
    return multiplication;
}

int add(long num_card)
{
    int sum = 0;
    while (num_card > 0)
    {
        sum = (num_card % 10) + sum;
        num_card /= 100;
    }
    return sum;
}

int verification(int result, int two_first_digits, int number_of_digits)
{
    if (result % 10 == 0)
    {
        if ((two_first_digits == 34 || two_first_digits == 37) && (number_of_digits == 15))
        {
            return printf("AMEX\n");
        }
        else if ((two_first_digits >= 51 && two_first_digits <= 55) && (number_of_digits == 16))
        {
            return printf("MASTERCARD\n");
        }
        else if ((two_first_digits >= 40 && two_first_digits <= 49) &&
                 (number_of_digits == 16 || number_of_digits == 13))
        {
            return printf("VISA\n");
        }
        else
        {
            return printf("INVALID\n");
        }
    }
    else
    {
        return printf("INVALID\n");
    }
}
