#include <stdio.h>

int fatorial(int n)
{
    int fat = 1, i;

    for (i = n; i >= 1; i--)
    {
        fat = fat * i;
    }
    return fat;
}

int main()
{
    int n;

    printf("Digite o valor:");
    scanf("%d", &n);

    printf("\nO fatorial de %d %c: %d.", n, 130, fatorial(n));
    return 0;
}