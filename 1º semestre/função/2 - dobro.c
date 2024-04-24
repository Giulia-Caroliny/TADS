#include <stdio.h>

int dobro(int num)
{
    return num * 2;
}

int main()
{
    int num1, num2, num3;

    puts("Insira os valores: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("O dobro de %d %c: %d.\n", num1, 130, dobro(num1));
    printf("O dobro de %d %c: %d.\n", num2, 130, dobro(num2));
    printf("O dobro de %d %c: %d.\n", num3, 130, dobro(num3));
    
    return 0;
}