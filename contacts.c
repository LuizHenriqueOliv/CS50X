#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    int age = get_int("how old are you? ");
    string phone_number = get_string("What's your phone number? ");

    printf("Name: %s\n", name);
    printf("Age: %i\n", age);
    printf("Phone number: %s\n", phone_number);
}
