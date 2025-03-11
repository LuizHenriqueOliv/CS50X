#include <stdio.h>

const int size = 5;

int main(void)
{
    // declare an array
    int numbers[size];

    // populate an array
    numbers[0] = 1;
    for (int i = 1; i < size; i++)
    {
        numbers[i] = numbers[i - 1] * 2;
    }

    // int numbers[5] = {1, 2, 4, 8, 16}

    // print ou the values one by one
    for (int i = 0; i < size; i++)
    {
        printf("%i\n", numbers[i]);
    }
}
