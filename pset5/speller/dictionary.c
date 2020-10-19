// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];


unsigned int number_of_words = 0;
bool is_loaded_dictionaries = false;


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char checked_word[strlen(word)];
    strcpy(checked_word, word);
    
    for (int i = 0; checked_word[i] != '\0'; i++)
    {
        checked_word[i] = tolower(checked_word[i]);
    }
    
    int index = hash(checked_word);
    
    if (table[index] != NULL)
    {
        for (node *nodepointer = table[index]; nodepointer != NULL; nodepointer = nodepointer -> next)
        {
            if (strcmp(nodepointer -> word, checked_word) == 0)
            {
                return true;
            }
        }
    }
    return false;
}



// Hashes word to a number
unsigned int hash(const char *word)
{
    
    int hash = 0;
    int n;

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            n = word[i] - 'a' + 1;
        }
        else
        {
            n = 27;
        }
        
        hash = ((hash << 3) + n) % N;
    }
    return hash;
}



// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open the file
    FILE *infile = fopen(dictionary, "r");
    
    // If the file is empty return false
    if (infile == NULL)
    {
        return false;
    }
    
    
    // Loop on the table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    
    char word[LENGTH + 1];
    node *new_nodepointer;
    
    while (fscanf(infile, "%s", word) != EOF)
    {
        number_of_words++;
        
        do
        {
            new_nodepointer = malloc(sizeof(node));
            if (new_nodepointer == NULL)
            {
                free(new_nodepointer);
            }
        }
        while (new_nodepointer == NULL);
        
        strcpy(new_nodepointer -> word, word);
        int index = hash(word);
            
        new_nodepointer -> next = table[index];
        table[index] = new_nodepointer;

    }
    fclose(infile);
    is_loaded_dictionaries = true;
    return true;
}



//  if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (!is_loaded_dictionaries)
    {
        return 0;
    }
    // Returns number of words in dictionary
    return number_of_words;
}



// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Check if the dictionary is not loaded in memory
    if (!is_loaded_dictionaries)
    {
        return false;
    }
    
    // If the dictionary is loaded in memory free it
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *pointer = table[i];
            while (pointer != NULL)
            {
                node *predpointer = pointer;
                pointer = pointer -> next;
                free(predpointer);
            }
        }
    }
    return true;
}
