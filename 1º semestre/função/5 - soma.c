#include <stdio.h>

int soma(int x, int y)
{
    return x + y;
}

int main()
{
    int num1, num2;

    puts("Insira dois valores: ");
    scanf("%d %d", &num1, &num2);

    printf("A soma de %d e %d %c: %d.\n", num1, num2, 130, soma(num1, num2));
    
    return 0;
}