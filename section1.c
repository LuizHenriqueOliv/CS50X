#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    int age = get_int("how old are you? ");
    int phone_number = get_int("What's your phone number? ");

    printf("Hello, %s! \n You have %i years old, and your phone number is %i. \n", name, age, phone_number);
}
