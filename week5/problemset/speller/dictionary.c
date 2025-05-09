// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 10000;

// Hash table
node *table[N];

// word counter
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
int compare_case_insensitive(const char *str1, const char *str2)
{
    while (*str1 && *str2)
    {
        if ()
    }
}

bool check(const char *word)
{
    unsigned int index = hash(word);

    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int sum = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += tolower(word[i]);
    }

    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if (source == NULL)
    {
        printf("não foi possível abrir o arquivo\n");
        return false;
    }

    // start hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // buffer
    char word[LENGTH + 1];
    int index = 0;
    char c;

    // read each word in the file
    while (fread(&c, sizeof(char), 1, source) == 1)
    {
        if (isalpha(c) || c == '\'')
        {
            if (index < LENGTH)
            {
                word[index++] = c;
            }
        }
        else if (c == '\n')
        {
            word[index] = '\0';

            // here, i go add the word in the hash table
            unsigned int hash_value = hash(word);
            node *new_node = malloc(sizeof(node));

            if (new_node == NULL)
            {
                fclose(source);
                return false;
            }

            // copy words to the new node
            strcpy(new_node->word, word);
            new_node->next = table[hash_value];
            table[hash_value] = new_node;

            index = 0; // reset index to the next word
            word_count++;
        }
    }

    if (index > 0)
    {
        word[index] = '\0';

            // here, i go add the word in the hash table
            unsigned int hash_value = hash(word);
            node *new_node = malloc(sizeof(node));

            if (new_node == NULL)
            {
                fclose(source);
                return false;
            }

            // copy words to the new node
            strcpy(new_node->word, word);
            new_node->next = table[hash_value];
            table[hash_value] = new_node;

            index = 0; // reset index to the next word
            word_count++;
    }
    // close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];


        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }

    return true;
}
