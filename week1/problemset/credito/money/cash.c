#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // valor do troco
    int troco;
    do
    {
        troco = get_int("Digite o valor do troco: ");
    }
    while (troco < 1);

    // quantidade de moedas de 25c
    int qtd_25 = troco / 25;
    troco = troco - (25 * qtd_25);

    // quantidade de moedas de 10c
    int qtd_10 = troco / 10;
    troco = troco - (10 * qtd_10);

    // quantidade de moedas de 5c
    int qtd_5 = troco / 5;
    troco = troco - (5 * qtd_5);

    // quantidade de moedas de 1c
    int qtd_1 = troco / 1;
    troco = troco - (1 * qtd_1);

    // quantidade de moedas
    int total_moedas = qtd_25 + qtd_10 + qtd_5 + qtd_1;
    printf("O número total de moedas é: %i\n", total_moedas);
    printf("Moedas de 25: %i\n", qtd_25);
    printf("Moedas de 10: %i\n", qtd_10);
    printf("Moedas de 5: %i\n", qtd_5);
    printf("Moedas de 1: %i\n", qtd_1);
}
