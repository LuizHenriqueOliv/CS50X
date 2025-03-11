#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    // peça a entrada ao usuário
    if (argc != 2)
    {
        printf("Please, provide a word\n");
        return 1;
    }

    string text = argv[1];
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if (!isalpha(text[i]))
        {
            printf("This is not a letter.\n");
            return 2;
        }
    }

    // iterar a cada elemento da string
        // verifique se é alfabético ou não
    for (int i = 1; i < n; i++)
    {
        if (text[i] < text[i - 1])
        {
            printf("No\n");
            return 0;
        }
    }

    // print yes or no
    printf("Yes\n");
}
