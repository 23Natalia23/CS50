/**
 * Implements a dictionary's functionality.
 */

#include <stdio.h> // fopen() fgetc() fclose()
#include <stdlib.h> // malloc() free()
#include <string.h> // strlen()
#include <ctype.h> // tolower()

/**
 * #include <stdbool.h>
 * bool определяется как _Bool
 * true определяется как 1
 * false определяется как 0
 * __bool_true_false_are_defined расширяется до 1
 * Программы, использующие эти макросы, могут отменять и
 * переопределять bool, true, и false.
 */
#include <stdbool.h>

#include "dictionary.h"

// alphabet + '\''
#define ALPHABET 27

// trie
typedef struct node
{
    bool is_word;
    struct node* letters[ALPHABET];
}
node;

// the top/beginning of trie
node *root;

// size of dictionary
unsigned int dict_size = 0;

// for unload function
bool free_node(node *ptr);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    node *cursor = root;
    // go through each letter in input word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int index = (word[i] == '\'') ? ALPHABET - 1 : tolower(word[i]) - 'a';
        /**
         * Go to corresponding element in letters,
         * if Null word is misspeled.
         */
        if (cursor->letters[index] == NULL)
        {
            return false;
        }
        // if not Null, go to next letter
        cursor = cursor->letters[index];
    }
    // check if is_word is true
    return (cursor->is_word) ? true : false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }
    root = (node *) malloc(sizeof(node));
    // check if malloc succeeded
    if (root == NULL)
    {
        return false;
    }
    // initialisation of root
    root->is_word = false;
    for (int i = 0; i < ALPHABET; i++)
    {
        root->letters[i] = NULL;
    }
    /**
     * Create cursor pointer ptr to traverse the trie,
     * inialised to equal root.
     */
    node *ptr = root;
    
    // scan dictionary word by word
    for (int i = fgetc(file); i != EOF; i = fgetc(file))
    {
        if (i != '\n')
        {
            /**
             * Each element in letters correspond to a different letter
             * (alphabet + apostrophe).
             */
            int index = (i == '\'') ? ALPHABET - 1 : tolower(i) - 'a';
            // check the value of letters
            if (ptr->letters[index] == NULL)
            {
                // have letters point to new node
                ptr->letters[index] = (node *) malloc(sizeof(node));
                // check if malloc succeeded
                if (ptr->letters[index] == NULL)
                {
                    return false;
                }
                ptr->letters[index]->is_word = false;
                for (int j = 0; j < ALPHABET; j++)
                {
                    ptr->letters[index]->letters[j] = NULL;
                }
            }
            ptr = ptr->letters[index];
        }
        else
        {
            ptr->is_word = true;
            // reset the pointer back to the top of the trie
            ptr = root;
            dict_size++;
        }
    }
    fclose(file);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dict_size;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    return free_node(root);
}
// free all memory
bool free_node(node *ptr)
{
    for (int i = 0; i < ALPHABET; i++)
    {
        if (ptr->letters[i] != NULL)
        {
            free_node(ptr->letters[i]);
        }
    }
    free(ptr);
    return true;
}