//Code by Erik Svartaas

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int start;
    do
    {
        start = get_int("Enter starting population size: ");
    }

//Making sure the user gets reprompted if number less than 9

    while (start < 9);

    // TODO: Prompt for end size

    int end;
    do
    {

        end = get_int("Enter end population size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold

// Year count starts at 0
    int years = 0;

//Defining a function for population growth, with plus one year for each iteration
//Zero growth implies 0 years

    int population = start;
    if(start == end)
    {
        years = 0;
    }

//upper constraint is end, iterations stop after population has grown to end. Years grow by one each iteration
    else
    {
        for (; population < end; years++)

//Defining population growth each year using two new variables
        {
            int growth = population / 3;
            int decline = population / 4;
            population += (growth - decline);
        }
    }
    // TODO: Print number of years

    //Retrieving the integers with %d

    printf("Starting population: %i\n", start);
    printf("End population: %i\n", end);
    printf("Years: %i\n", years);



}
