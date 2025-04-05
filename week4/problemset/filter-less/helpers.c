#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // percorrer todos os pixels da imagem
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // pegar a média dos valores red, green e blue
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);

            // atualizar os valores
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // percorrer todos os pixels da imagem
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                // pegar o valor e transformar em sepia color
                int sepia_red = fmin(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue), 255);
                int sepia_green = fmin(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue), 255);
                int sepia_blue = fmin(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue), 255);

                // atualizar os valores
                image[i][j].rgbtRed = sepia_red;
                image[i][j].rgbtGreen = sepia_green;
                image[i][j].rgbtBlue = sepia_blue;
            }
        }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp;
    // percorrer metade dos pixels de cada linha da imagem
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width/2); j++)
        {
            // trocar o j-ésimo pixel pelo width - j pixel
                temp = image[i][j].rgbtRed;
                image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
                image[i][width - 1 - j].rgbtRed = temp;

                temp = image[i][j].rgbtGreen;
                image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
                image[i][width - 1 - j].rgbtGreen = temp;

                temp = image[i][j].rgbtBlue;
                image[i][j].rgbtBlue= image[i][width - 1 - j].rgbtBlue;
                image[i][width - 1 - j].rgbtBlue = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
