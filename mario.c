#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // promp user for positive integer
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);
    
    // print for
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
