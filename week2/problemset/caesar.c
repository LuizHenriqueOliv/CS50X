#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // pegar a chave
    while (argc != 2)
    {
        printf("Por favor coloque um argumento\n");
        return 1;
    }

    string key = argv[1];
    int k = atoi(key);

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    printf("key: %s\n", key);

    // pegar o texto
    string text = get_string("plaintext: ");

    // criptografar o texto
    string ciphertext = text;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]))
        {
            ciphertext[i] = (((text[i] + k - 65)) % 26) + 65;
        }
        else if (islower(text[i]))
        {
            ciphertext[i] = (((text[i] + k - 97)) % 26) + 97;
        }
    }
    // printar o texto criptografado
    printf("ciphertext: %s\n", ciphertext);
}
