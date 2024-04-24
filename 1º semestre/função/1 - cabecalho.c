#include <stdio.h>

void cabecalho ()
{
    int i;

    for (i = 0; i < 36; i++)
    {
        printf("=");
    }
    printf("\n+            Algoritmos            +");
    printf("\n+");
    for (i = 0; i < 34; i++)
    {
        printf("-");
    }
    printf("+");
    printf("\n+    Instituto Federal de Goi%cs    +", 160);
    printf("\n+          Campus Formosa          +\n");
    for (i = 0; i < 36; i++)
    {
        printf("=");
    }
}

int main()
{
    cabecalho();
    return 0;
}