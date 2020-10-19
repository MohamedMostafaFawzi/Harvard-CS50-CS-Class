#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int n;

    do
    {
        // Get the height from the user
        n = get_int("Height: ");
    }
    // If the height is < 1 or > 8 or not an int, go back to step one
    while (n > 8 || n < 1);

    // Iterate from 1 through the height int
    // Iteration i, print i hashes and then a newline
    for (int i = 0; i < n; i++)
    {
        // Iteration j, print j hashes and i spaces and then a newline
        for (int j = 0; j < n; j++)
        {
            if (i + j < n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }

}