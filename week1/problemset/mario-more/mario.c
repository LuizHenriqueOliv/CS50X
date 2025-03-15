#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Qual a altura da pirâmide? ");
    }
    while (height < 1);

    int qtd_vazios = height - 1;
    int qtd_hashes = height - qtd_vazios;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < qtd_vazios; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < qtd_hashes; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int j = 0; j < qtd_hashes; j++)
        {
            printf("#");
        }

        printf("\n");
        qtd_vazios--;
        qtd_hashes++;
    }
}


