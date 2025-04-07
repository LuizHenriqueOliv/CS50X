#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // aceitar uma única linha de comando
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // abrir o cartão de memória
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // criar um buffer para armazenar os dados do cartão
    uint_t buffer[512];
        // enquanto houver dados para ler no cartão
        while (fread(buffer, 1, 512, card) == 512);
        {
            // criar JPEGs dos dados
            
        }

}
