#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main()
{
    char *name = NULL;
    *name = get_int("Name: ");
    printf("%s\n", name);
}
