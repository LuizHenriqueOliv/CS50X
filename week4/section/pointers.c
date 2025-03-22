#include <stdio.h>

int main(void)
{
    int number = 50; 
    int *pointer = &number;
    printf("%i\n", *pointer);
}
