#include <cs50.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, string argv[])
{
    // open file
    FILE *input = fopen(argv[1], "r");

    // create buffer for file
    uint8_t buffer[4];

    // create an array of signature bytes
    uint8_t signature[] = {0x25, 0x50, 0x44, 0x46};

    // read first 4 bytes from the file
    fread(buffer, sizeof(uint8_t), 4, input);

    //
}
