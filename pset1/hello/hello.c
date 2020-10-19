#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Add string name to get the name of the user
    string name = get_string("What's your name?\n");
    // Prints the output Hello and the name of the user
    printf("hello, %s\n", name);
}