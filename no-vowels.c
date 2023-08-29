// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    if (argc == 2)
    {


        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; argv[i][j] != '\0'; j++)
            {
                if (argv[i][j] == 'a' || argv[i][j] == 'A')
                {
                    argv[i][j] = '4';
                }
                if (argv[i][j] == 'e' || argv[i][j] == 'E')
                {
                    argv[i][j] = '3';
                }
                if (argv[i][j] == 'i' || argv[i][j] == 'I')
                {
                    argv[i][j] = '1';
                }
                if (argv[i][j] == 'o' || argv[i][j] == 'O')
                {
                    argv[i][j] = '0';
                }
                printf("%c", argv[i][j]);
            }
            printf("\n");
        }
    }

    else
    {
        printf("Error\n");
        return 1;
    }
}
