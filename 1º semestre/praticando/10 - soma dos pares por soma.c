#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, soma, quant;

    quant = 0;

    for (i = 0; quant <= 50; i+= 2)
    {
        soma = soma + i;
        quant++;
        printf(" %d\n", i);
    }
    
    printf("\nA soma dos primeiros 50 n%cmeros pares %c: %d", 163, 130, soma);

    return 0;
}