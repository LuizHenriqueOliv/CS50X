#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Pegar a chave
    string key = argv[1];

    // validar a chave
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // verificar se tem 26 caracteres
    int n = strlen(key);
    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // verificar se são todos alphabeticos
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    // converter toda a chave para maiúscula
    for (int i = 0; i < n; i++)
    {
        key[i] = toupper(key[i]);
    }

    // verificar se são todos diferentes
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (key[i] == key[j + 1])
            {
                printf("The key have charaters equals.\n");
                return 1;
            }
        }
    }

    // pegar o texto
    string text = get_string("Plaintext: ");
    string ciphertext = text;
    int len = strlen(text);

    // encriptar
    for (int i = 0; i < len; i++)
    {
        if (islower(text[i]))
        {
            ciphertext[i] = key[text[i] - 97] + 32;
        }
        else if (isupper(text[i]))
        {
            ciphertext[i] = (key[text[i] - 65]);
        }
    }

    // printar o texto cifrado
    printf("ciphertext: %s\n", ciphertext);
}
