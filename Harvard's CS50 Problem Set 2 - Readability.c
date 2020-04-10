//Harvard's CS50 Problem Set 2 - Readability
//Author: HeidiHappens

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
//user input.
    string text = get_string("Text: ");

    int lettercount = 0;
    int wordcount = 1;
    int sentencecount = 0;

//counts number of letters, words and sentences.
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            lettercount++;
        }
        else if (text[i] == ' ')
        {
            wordcount++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentencecount++;
        }
    }

//equates the variables L and S for the Coleman-Liau index.
    float L = (float) lettercount / (float) wordcount * 100;
    float S = (float) sentencecount / (float) wordcount * 100;

//computes the Coleman-Liau index.
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

//prints out reading level.
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }

    else if (grade >= 1 || grade < 16)
    {
        printf("Grade %i\n", grade);
    }
}