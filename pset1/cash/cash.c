#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float dollars;

    do
    {
        // Get the value from the user
        dollars = get_float("Changed owed: ");
    }
    // If the value is < 0, go back to step one
    while (dollars < 0);
    
    // Round the dollars to cents
    int cents = round(dollars * 100);
    int coins = 0;
    
    // While cents more than or equal to 25 subtract 25 and increment the coins by 1
    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }
    
    // While cents more than or equal to 10 subtract 10 and increment the coins by 1
    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }
    
    // While cents more than or equal to 5 subtract 5 and increment the coins by 1
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }
    
    // While cents more than or equal to 1 subtract 1 and increment the coins by 1
    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }
    
    // Print the number of coins
    printf("%i\n", coins);

}