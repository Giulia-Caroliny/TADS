#include <stdio.h>

int soma(int x, int y)
{
    return x + y;
}

int subtrair(int x, int y)
{
    return x - y;
}

int dividir(int x, int y)
{
    return x / y;
}

int multiplicar(int x, int y)
{
    return x * y;
}

int main()
{
    int num1, num2;

    puts("Insira dois valores: ");
    scanf("%d %d", &num1, &num2);

    printf("A soma de %d e %d %c: %d.\n", num1, num2, 130, soma(num1, num2));
    printf("A subtra%c%co de %d e %d %c: %d.\n", 135, 198, num1, num2, 130, subtrair(num1, num2));
    printf("A divis%co de %d e %d %c: %d.\n",198, num1, num2, 130, dividir(num1, num2));
    printf("A multiplica%c%co de %d e %d %c: %d.\n", 135, 198, num1, num2, 130, multiplicar(num1, num2));

    return 0;
}