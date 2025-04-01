#include <cs50.h>
#include <stdio.h>

int main(void)
{

    string name = get_string("Name: ");
    string phone_number = get_string("Number: ");

    FILE *phonebook = fopen("myphonebook.txt", "a");
    fprintf(phonebook, "Name: %s | Number: %s\n", name, phone_number);
}
