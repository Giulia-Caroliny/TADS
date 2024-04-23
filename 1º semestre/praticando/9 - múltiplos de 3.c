#include <stdio.h>
#include <stdlib.h>

int main(){

    int k, j, n, soma;

    j = 1;
    k = 0;
    n = 3;

    for (soma = n; j <= 5; soma+=n)
    {
        j++;
        k++;
        printf("O %d%c m%cltiplo de %d %c: %d\n", k, 167, 163, 3, 130, soma);
    }    

    return 0;
}