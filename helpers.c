/**
 * helpers.c
 * 
 * more
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    while (n > 0)
    {
        // set the value of the upper and lower limits of search
        int lower = 0;
        int upper = n - 1;
        while(lower <= upper)
        {
            // set middle
            int middle = (upper + lower) / 2;
    
            // check if value is middle
            if (values[middle] == value)
            {
                return true;
            }
            // check if value is at the right half
            else if (values[middle] < value)
            {
                lower = middle + 1;
            }
            // check if value is at the left half
            else if (values[middle] > value)
            {
                upper = middle - 1;
            }
        }
        return false;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int k = 0; k < n; k++)
    {
        /**
         * do minus 1 and minus k to save the last number
         * as sorted in each iteration
         */
        for (int i = 0; i < n - 1 - k; i++)
        {
            // check if next number is smaller than previous one
            if ( values[i] > values[i + 1])
            {
                // if yes, swap one with another
                int temp = values[i + 1];
                values[i + 1] = values[i];
                values[i] = temp;
            }
        }
    }
    return;
}
