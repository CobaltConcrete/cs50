// calculate the approximate grade level to comprehend given text based on Coleman-Liau Index

#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string text = get_string("Text: ");

    float letters, words, sentences;
    letters = words = sentences = 0.0;
    int index;
    int n = strlen(text) + 1;

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\0')
        {
            words++;
        }

        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    index = round(5.88 * (letters/words) - 29.6 * (sentences/words) - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
