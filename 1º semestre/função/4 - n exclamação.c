#include <stdio.h>

void linhas(int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("\n!");
        for (j = 0; j < i; j++)
        {
            printf("!");
        }  
    }
}

int main()
{
    int n;

    puts("Insira um valor:");
    scanf("%d", &n);
    
    linhas(n);

    return 0;
}