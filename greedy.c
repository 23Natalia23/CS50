#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    float inputm;
    int coins=0;
    
    do
    {
        printf("How much change is owed?\n");
        inputm = GetFloat();
    }
    while (inputm<0);
    
    int change = (int) roundf(inputm*100);
    
    while(change>=25)
    {
        coins++;
        change-=25;
    }
    while(change>=10)
    {
        coins++;
        change-=10;
    }
    while(change>=5)
    {
        coins++;
        change-=5;
    }
    while(change>=1)
    {
        coins++;
        change-=1;
    }
    
    printf("%i\n", coins);
}
