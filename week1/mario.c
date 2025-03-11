#include <stdio.h>

void print_row(int n);

int main(void)
{
    int n = 5;
    // escreve n linhas 
    for (int i = 0; i < n; i++)
    {
        print_row(n);
    }
}

// escreve uma linha com n colunas
void print_row(int n)
{
    for (int j = 0; j < n; j++)
    {
        printf("#");
    }
    printf("\n");
}
