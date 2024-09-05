#include <stdio.h>
#include <cs50.h>

int main(void){

    int Height;

    // Get a valid height from the user 
    do{
        Height = get_int ("Height : ");
    }
    while (Height > 8 || Height < 1);

    for (int i =0; i < Height; i++)  // print the pyramid
    {
        for (int j = 0; j , Height - i - 1; j++)  // print space before the hashes
        {
            printf (" ");
        }

        for (int k = 0; k <= i; k++)  // print the hashes 
        {
            printf("#");
        }

        printf("\n");
    }
}