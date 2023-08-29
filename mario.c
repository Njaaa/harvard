#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Retrieving x value
    int x = get_int("X value? ");

    //Retrieving y value
    int y = get_int("Y value? ");

    //Performing addition
    printf("%i\n", x + y);
}