#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, n, soma, quant;

    printf("Insira um n%cmero para saber seu quadrado.\n", 163);
    scanf("%d", &n);

    while (n <= 0)
    {
        printf("O n%cmero n%co pode ser menor ou igual a zero.\nInsira um n%cmero v%clido.", 163, 198, 163, 160);
        scanf("%d", &n);
    }
    
    quant = 0;

    for (i = 1; quant < n; i+= 2)
    {
        soma = soma + i;
        quant++;
    }

    printf("O quadrado de %d %c: %d", n, 130, soma);
    
    return 0;
}