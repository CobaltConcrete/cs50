// Implements a dictionary's functionality

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100;

// Hash table
node *table[N];

int wordcount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashvalue = hash(word);
    node *cursor = table[hashvalue];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
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
    // TODO: Improve this hash function
    long sum = 0;
    int n = strlen(word);

    for (int i = 0; i < n; i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];
    FILE *dict = fopen(dictionary, "r");

    if (dictionary == NULL)
    {
    return false;
    }

    while (fscanf(dict, "%s", word) != EOF)
    {
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            return false;
        }

        strcpy(temp->word, word);
        temp->next = NULL;

        int hashvalue = hash(word);

        if(table[hashvalue] == NULL)
        {
            table[hashvalue] = temp;
        }
        else
        {
            temp->next = table[hashvalue];
            table[hashvalue] = temp;
        }

        wordcount++;
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node * pointer = table[i];

        while (pointer != NULL)
        {
            node *temp = pointer;
            pointer = pointer->next;
            free(temp);
        }

         if (pointer == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
