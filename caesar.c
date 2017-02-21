/**
 * caesar.c
 *
 * Takes user input and encrypts it.
 */
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h> // atoi()
#include <string.h> // strlen()
#include <ctype.h>  // isalpha()

int main(int argc, string argv[])
{
    // check the number of arguments
    if (argc != 2)
    {
        printf("The number of arguments is two!\n");
        return 1;
    }
    // convert string to int
    int key = atoi(argv[1]);
    printf ("plaintext:  ");
    string plaintext = GetString();
    printf ("ciphertext: ");
    for (int i = 0, t = strlen(plaintext); i < t; i++)
    {
        // check if character is alphabetic
        if (isalpha(plaintext[i]))
        {
            // check if character is uppercase letter
            if (isupper(plaintext[i]))
            {
                plaintext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
                printf("%c", plaintext[i]);
            }
            // check if character is lowercase letter
            else
            {
                plaintext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
                printf("%c", plaintext[i]);
            }
        }
        else printf("%c", plaintext[i]);
    }
    printf("\n");
    return 0;
}