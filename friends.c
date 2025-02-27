#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Whats your name? ");
    int age = get_int("Whats your age? ");
    string hometown = get_string("Whats your hometown? ");
    string phone_number = get_string("Whats your phone number? ");

    printf("My new friend is %s, %i, they are from %s, and your phone number is %s.\n", name, age, hometown, phone_number);
}
