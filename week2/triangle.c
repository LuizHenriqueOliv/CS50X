#include <cs50.h>
#include <stdio.h>

bool valid_triangle(int x, int y, int z);

int main(void)
{
    // Peça ao usuário os 3 lados
    int a = get_int("Lado a: ");
    int b = get_int("Lado b: ");
    int c = get_int("Lado c: ");

    // print false/true
    bool valid = valid_triangle(a, b, c);
    printf("%s\n", valid ? "valid" : "invalid");
}

// função que verifica se o triângulo é válido
bool valid_triangle(int x, int y, int z)
{
    // verifica se cada lado é positivo
    return ((x > 0 && y > 0 && z > 0) && (x + y > z && y + z > x && x + z > y));
}
