#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Validating the Key
bool isvalid(string key);

int main(int argc, string argv[])
{

    // Check if the user input is valid
    if (argc != 2 || !isvalid(argv[1]))
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    // Convert the key from string to int
    int key = atoi(argv[1]);

    // get the plaintext from the user
    string plainText = get_string("plaintext: ");

    printf("ciphertext: ");

    int plainTextLength = strlen(plainText);

    for (int i = 0; i < plainTextLength; i++)
    {
        char c = plainText[i];

        if (isalpha(c))
        {

            char m = 'A';
            if (islower(c))
            {
                m = 'a';
            }
            // Caesar’s algorithm
            printf("%c", (c - m + key) % 26 + m);

        }
        else
        {
            printf("%c", c);
        }

    }

    printf("\n");

}

// Validating the Key
bool isvalid(string key)
{
    // Length of the key
    int length = strlen(key);

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }

    }

    return true;
}