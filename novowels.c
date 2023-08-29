// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

char vow[] = { 'a', 'e', 'i', 'o'};
char uvow[] = { 'A', 'E', 'I', 'O'};
char dig[] = { '4', '3', '1', '0'};

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; argv[i][j] != '\0'; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (argv[i][j] == vow[k] || argv[i][j] == uvow[k])
                    {
                        argv[i][j] = dig[k];
                    }
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
