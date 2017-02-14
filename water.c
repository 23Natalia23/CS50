#include <stdio.h>
#include <cs50.h>
int countBottles(int bottle);

int main (void)
{
    int minutes;
    do
    {
        printf("How many minutes do you take a shower?\n");
        minutes = GetInt();
    }
    while (minutes<1);
    printf("Minutes:%i\nBottles:%i\n", minutes, countBottles(minutes));
}

int countBottles(int bottle)
{
    return bottle*=12;
}