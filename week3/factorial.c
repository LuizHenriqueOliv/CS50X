#include <cs50.h>
#include <stdio.h>

int factorial(int n);

int main(void)
{
    // peça a entrada ao usuário
    int number;
    do
    {
        number = get_int("Number: ");
    }
    while (number <= 0);

    // chame a função fatorial
    int result = factorial(number);
    printf("The factorial of %i is %i.\n", number, result);
}

int factorial(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }

    // recursive case
    return n * factorial(n - 1);
}
