#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for card number
    long number = get_long("Enter your card number: ");

    // Variables
    int csum = 0;
    int count = 0;
    int product;
    int fdigit;
    int sdigit;

    // Non-zero constraint
    while (number > 0)
    {
        // Define last digit
        int digit = number % 10;

        // Starting at count 0, no remainder after division by 2 doesn't multiply by 2
        if (count % 2 == 0)
        {
            csum += digit;
        }

        else
        {
            // Every other digit afterwards gets multiplied by 2
            product = digit * 2;
            // product gets divided in two parts and added together
            csum += product % 10;
            csum += product / 10;
        }
        // add plus one count and remove one digit from the right end
        count++;
        number /= 10;

        // storing so that we do not lose our number
        sdigit = fdigit;
        fdigit = digit;
    }

    // Determine card type
    if (csum % 10 == 0)
    {
        if (count == 15 && (fdigit == 3 && (sdigit == 4 || sdigit == 7)))
        {
            printf("AMEX\n");
        }
        else if ((count == 13 || count == 16) && fdigit == 4)
        {
            printf("VISA\n");
        }
        else if (count == 16 && fdigit == 5 && sdigit >= 1 && sdigit <= 5)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}