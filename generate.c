/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // check the number of arguments
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // convert input, string to int, and remember it
    int n = atoi(argv[1]);

    // check if there is seed, if yes - call srand48 with an argument of argv[2]
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    // if there is no seed - call srand48 with an argument of time(NULL), which means - no value is stored!
    else
    {
        srand48((long) time(NULL));
    }

    // print pseudorandom numbers n times calling drand48() * LIMIT (#define LIMIT 65536)
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
