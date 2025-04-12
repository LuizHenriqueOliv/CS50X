#include <stdint.h>
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
    uint8_t buffer[512];

    // contador de jpegs
    FILE *img = NULL;
    int file_counter = 0;
    char filename[8];

    // enquanto houver dados para ler no cartão
    while (fread(buffer, 1, 512, card) == 512)
    {
        // criar JPEGs dos dados
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            // cria o nome do arquivo e abre ele
            sprintf(filename, "%03i.jpg", file_counter); // "muda" o nome do arquivo "filename"
            img = fopen(filename, "w");
            file_counter++;
        }
        if (img != NULL) // ou seja, possui um valor
        {
            fwrite(buffer, 512, 1, img);
        }
    }

    // fecha o último jpeg
    if (img != NULL)
    {
        fclose(img);
    }

    // fechando o arquivo original
    fclose(card);
}
