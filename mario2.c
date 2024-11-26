#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Size: ");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("#");
        }
    }

}
