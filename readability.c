#include <cs50.h>
#include <stdio.h>

// Prototype
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

// Variables
float index;
int grade;
float L;
float S;

// Main
int main(void)
{ // Prompt for text
    string text = get_string("Input Text: ");

    // Calculate the ratios
    L = (float) count_letters(text) / count_words(text) * 100;
    S = (float) count_sentences(text) / count_words(text) * 100;

    index = 0.0588 * L - 0.296 * S - 15.8;

    // Rounding to nearest integer
    grade = index;
    if (index - grade >= 0.5)
    {
        grade++;
    }
    // Below 1 / 16 and above constraints
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Establishing letter count
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)

    { // Only counting alphabetical letters
        if ((text[i] >= 'A' && text[i] <= 'Z') || ((text[i] >= 'a' && text[i] <= 'z')))
        {
            letters++;
        }
    }
    return letters;
}

// Use spaces to establish word count
int count_words(string text)
{
    int words = 1; // Will be one more space than words
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
        // Word count does not go up in case of several spaces in a row
        if (text[i - 1] == ' ' && text[i] == ' ')
        {
            words--;
        }
    }
    // Reset words to 0 if input is empty
    if (text[0] == '\0')
    {
        words = 0;
    }
    return words;
}

int count_sentences(string text)
{
    // Define sentence count by punctuation
    int sentences = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
        // No extra sentence count in case of multiple punctuation such as !!! and !?
        if ((text[i - 1] == '!' || text[i - 1] == '?' || text[i - 1] == '.') &&
            (text[i] == '!' || text[i] == '?' || text[i] == '.'))
        {
            sentences--;
        }
    }
    return sentences;
}
