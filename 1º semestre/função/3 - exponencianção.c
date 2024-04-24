#include <stdio.h>

int exponencial(int x, int y)
{
    int i, result = x;

    for (i = 1; i < y; i++)
    {
        result = result * x;
    }
    return result;
}

int main()
{
    int base, expoente;
    puts("Insira a base e o expoente:");
    scanf("%d %d", &base, &expoente);

    printf("O resultado da exponencia%c%co %c: %d.", 135, 198, 130, exponencial(base, expoente));

    return 0;
}