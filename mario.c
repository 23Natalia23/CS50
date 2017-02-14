#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int height;
    
    do
    {
        printf("Height:");
        height = GetInt();
    }
    while (height<0 || height>23);
    
    for(int i=0; i<height; i++)
    {
        for(int j=height-1-i; j>0 ;j--)
        {
            printf (" ");
        }
        for(int k=0; k<i+1; k++)
        {
            printf ("#");
        }
        for(int l=0; l<2; l++)
        {
          printf (" ");
        }
        for(int m=0; m<i+1; m++)
        {
            printf ("#");
        }
        printf ("\n");
    }
}
