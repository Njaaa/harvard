#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        char *endptr; // Used to handle non numeric key
        long key = strtol(argv[1], &endptr, 10);

        // Check if there was an error during conversion or if the argument is empty
        if (*endptr != '\0' || key < 1 || key >= (pow(2, 31) - 26))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        string plaintext = get_string("plaintext: ");

        // Make string to store the ciphertext
        string ciphertext = plaintext;

        for (int i = 0; plaintext[i] != '\0'; i++)
        {
            if (isalpha(plaintext[i]))
            {
                char base = isupper(plaintext[i]) ? 'A' : 'a';
                int c = (plaintext[i] - base + (int)key) % 26;
                ciphertext[i] = base + c; // Store the ciphertext character in the corresponding position
            }
            else
            {
                ciphertext[i] = plaintext[i]; // Non-alphabetical letters stay unchanged
            }
        }

        printf("ciphertext: %s\n", ciphertext); // Print the entire ciphertext once the loop is done
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    return 0;
}
