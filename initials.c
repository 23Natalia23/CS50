/**
 * more initials, cs50
 * 
 * initials.c
 * 
 * Takes input (name) and returns initials.
 */
#include <stdio.h>
#include <cs50.h>
#include <string.h> //strlen()
#include <ctype.h>  //toupper()

// declare function
void initials(string name);

int main(void)
{
    // what to do: printf("Please, write your name and last name.\n");
    string name = GetString();
    // make sure GetString returned a string
    if (name != NULL)
    {
        // use function
        initials(name);
    }
    return 0;
}

void initials(string name)
{
    int first_letter=0;
    // check spaces and print first capital letter
    while (isblank(name[first_letter]))
    {
        first_letter++;
    }
    printf("%c", toupper(name[first_letter]));
    // iterate over the characters in "name" one at a time
    for (int i=first_letter + 1, s=strlen(name); i < s; i++)
    {   
        // check spaces and print capital letter after space(s)
        while (isblank(name[i]))
        {
            i++;
            if (!isblank(name[i]) && i < s )
                printf("%c", toupper(name[i]));
        }
    }
    printf("\n");
}