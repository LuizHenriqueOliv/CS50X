#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calcScoreWord(string word);

int main(void)
{
    // Pedir 2 palavras de cada vez
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // armazenando a pontuação de cada palavra
    int score_word1 = calcScoreWord(word1);
    int score_word2 = calcScoreWord(word2);

    // comparar a pontuação das palavras
    if (score_word1 > score_word2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_word2 > score_word1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("tie!\n");
    }
    // printar o vencedor ou empate
}

// função para calcular a pontuação de cada palavra
int calcScoreWord(string word)
{
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] == 'a' || word[i] == 'A')
        {
            score += 1;
        }
        else if (word[i] == 'b' || word[i] == 'B')
        {
            score += 3;
        }
        else if (word[i] == 'c' || word[i] == 'C')
        {
            score += 3;
        }
        else if (word[i] == 'd' || word[i] == 'D')
        {
            score += 2;
        }
        else if (word[i] == 'e' || word[i] == 'E')
        {
            score += 1;
        }
        else if (word[i] == 'f' || word[i] == 'F')
        {
            score += 4;
        }
        else if (word[i] == 'g' || word[i] == 'G')
        {
            score += 2;
        }
        else if (word[i] == 'h' || word[i] == 'H')
        {
            score += 4;
        }
        else if (word[i] == 'i' || word[i] == 'I')
        {
            score += 1;
        }
        else if (word[i] == 'j' || word[i] == 'J')
        {
            score += 8;
        }
        else if (word[i] == 'k' || word[i] == 'K')
        {
            score += 5;
        }
        else if (word[i] == 'l' || word[i] == 'L')
        {
            score += 1;
        }
        else if (word[i] == 'm' || word[i] == 'M')
        {
            score += 3;
        }
        else if (word[i] == 'n' || word[i] == 'N')
        {
            score += 1;
        }
        else if (word[i] == 'o' || word[i] == 'O')
        {
            score += 1;
        }
        else if (word[i] == 'p' || word[i] == 'P')
        {
            score += 3;
        }
        else if (word[i] == 'q' || word[i] == 'Q')
        {
            score += 10;
        }
        else if (word[i] == 'r' || word[i] == 'R')
        {
            score += 1;
        }
        else if (word[i] == 's' || word[i] == 'S')
        {
            score += 1;
        }
        else if (word[i] == 't' || word[i] == 'T')
        {
            score += 1;
        }
        else if (word[i] == 'u' || word[i] == 'U')
        {
            score += 1;
        }
        else if (word[i] == 'v' || word[i] == 'V')
        {
            score += 4;
        }
        else if (word[i] == 'w' || word[i] == 'W')
        {
            score += 4;
        }
        else if (word[i] == 'x' || word[i] == 'X')
        {
            score += 8;
        }
        else if (word[i] == 'y' || word[i] == 'Y')
        {
            score += 4;
        }
        else if (word[i] == 'z' || word[i] == 'Z')
        {
            score += 10;
        }
    }
    return score;
}
