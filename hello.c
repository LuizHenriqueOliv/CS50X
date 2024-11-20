#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string nome = get_string("Qual o seu nome? ");
    string idade = get_string("Qual a sua idade? ");
    printf("Olá, %s, você tem %s anos \n", nome, idade);
}
