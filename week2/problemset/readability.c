#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // peça ao usuário um texto
    string text = get_string("Texto: ");
    int lenght = strlen(text);
    int letters = 0;

    // contar letras (um loop que percorre todos os elementos do texto e verifica se é letra ou não)
    for (int i = 0; i < lenght; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    // contar palavras (um loop que percorre todos os elementos do texto e conta quantos espaços tem
    // e soma mais um)
    int spaces = 0;
    for (int i = 0; i < lenght; i++)
    {
        if (isspace(text[i]))
        {
            spaces++;
        }
    }
    int words = spaces + 1;

    // contar frases (um loop que percorre todos os elementos do texto e conta quantos pontos
    // (./!/?) tem)
    int sentences = 0;
    for (int i = 0; i < lenght; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // calcular o index (index = 0.0588 * L - 0.296 * S - 15.8) (L = (l/p) * 100) (S = (s/p) * 100)
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;
    int index = (int) (0.0588 * L - 0.296 * S - 15.8 + 0.5);

    // printar o nível
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
