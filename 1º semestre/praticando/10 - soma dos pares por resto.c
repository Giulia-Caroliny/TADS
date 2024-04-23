#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, res, quant, soma;

    soma = 0;
    n = 2;
    quant = 0;

    while (quant < 50)
    {
        res = n % 2;
        if (res == 0){
            soma = soma + n;
            quant++;}
        n++;
    }
    printf("\nA soma dos primeiros 50 n%cmeros pares %c: %d", 163, 130, soma);

    return 0;
}