#include <cs50.h>
#include <stdio.h>

void printCol(int height);

int main(void)
{
    int h = get_int("Height: ");
    printCol(h);
}

void printCol(int height)
{
    for (int i = 0; i < height; i++)
    {
        printf("#\n");
    }
}
