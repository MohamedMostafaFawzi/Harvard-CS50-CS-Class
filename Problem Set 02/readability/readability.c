#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{

    // Get the value from the user
    string text = get_string("Text: ");

    int numberOfWords = 0;
    int numberOfSentences = 0;
    int numberOfLetters = 0;

    int textLength = strlen(text);

    for (int i = 0; i < textLength; i++)
    {

        // if it's a letter according to the isalpha function so it increments the numberOfLetters accordingly
        if (isalpha(text[i]))
        {
            numberOfLetters++;
        }

        // Checking the number of words if there's space after and before the letter or there's no letters and the letter
        if ((i != textLength - 1 && text[i] == ' ' && text[i + 1] != ' ') || (i == 0 && text[i] != ' '))
        {
            numberOfWords++;
        }

        // If there's a . or ! or ? so it increments the numberOfSentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            numberOfSentences++;
        }

    }

    // L is the average number of letters per 100 words in the text
    float L = (numberOfLetters / (float) numberOfWords) * 100;
    // S is the average number of sentences per 100 words in the text
    float S = (numberOfSentences / (float) numberOfWords) * 100;

    // The Coleman-Liau index formula
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}