/**
 * vigenere.c
 *
 * Takes user input and encrypts it using Vigenère’s cipher.
 * Alphabetical key is a command line argument.
 */
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check the number of arguments
    if (argc != 2)
    {
        printf("The number of arguments should be two!\n");
        return 1;
    }
    string key = argv[1];
    for (int i = 0, j = strlen(key); i < j; i++)
    {
        // check if character is alphabetical
        if (!isalpha(key[i]))
        {   
            printf("Your key should contain alphabetical characters only!\n");
            return 1;
        }
    }
    printf ("plaintext:  ");
    string pt = GetString();
    int lenK = strlen(key);
    printf ("ciphertext: ");
    for (int i = 0, j=0, t = strlen(pt); i < t; i++)
    {
        // check if character is alphabetical
        if (isalpha(pt[i]))
        {         
            // treat A/a as 0, … Z/z as 25; use modulo to wraparound the key
            int ciphK = toupper(key[j % lenK]) - 'A';
            // check if character is uppercase letter
            if (isupper(pt[i]))
            {
                pt[i] = (pt[i] - 'A' + ciphK) % 26 + 'A';
                printf("%c", pt[i]);
                // use incrementation only for alphabetical characters
                j++;
            }
            // check if character is lowercase letter
            else
            {
                pt[i] = (pt[i] - 'a' + ciphK ) % 26 + 'a';
                printf("%c", pt[i]);
                // use incrementation only for alphabetical characters
                j++;
            }
        }
        // output all non-alphabetical chars
        else printf("%c", pt[i]);
    }
    printf("\n");
    return 0;
}