#include <cs50.h>
#include <stdio.h>

int collatz(int n);
int contador = 0;

int main(void)
{
    int n = get_int("Number: ");
    int steps = collatz(n);
    printf("N = %i\nSteps: %i\n", n, steps);
}

int collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0) // se n for par
    {
        collatz(n/2);
    }
    else if (n % 2 == 1) // se n for ímpar
    {
        collatz(3*n + 1);
    }
    contador++;
    return contador;
}
