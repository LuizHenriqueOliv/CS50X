#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("X: ");
    int y = get_int("Y: ");

    double z = (double) x / (double) y;
    printf("%.20f\n", z);
}

