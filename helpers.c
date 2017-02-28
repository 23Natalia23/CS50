/**
 * helpers.c
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
    // from the first element to the penultimate one
    for (int i = 0; i < n - 2; i++)
    {
        // set minimum
        int smallest = values[i];
        int position = i;
        // walk through unsorted part of the array
        for (int k = i + 1; k < n - 1; k++)
        {
            // find the minimum
            if (values[k] < smallest)
            {
                smallest = values[k];
                position = k;
            }
        }
        // switch elements
        int temp = values[i];
        values[i] = smallest;
        values[position] = temp;
    }
}
