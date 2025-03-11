#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char op = get_char("Que operação você deseja efetuar? ");
    float n1 = get_float("Número 1: ");
    float n2 = get_float("Número 2: ");
    float res;

    if (op == '+')
    {
        res = n1 + n2;
        printf("A soma de %.2f e %.2f é: %.2f\n", n1, n2, res);
    }
    else if (op == '-')
    {
        res = n1 - n2;
        printf("A subtração de %f por %f é: %f\n", n1, n2, res);
    }
    else if (op == '/')
    {
        res = n1 / n2;
        printf("A divisão de %f por %f é: %f\n", n1, n2, res);
    }
    else if (op == '*')
    {
        res = n1 * n2;
        printf("A multiplicação de %f por %f é: %f\n", n1, n2, res);
    }
}
