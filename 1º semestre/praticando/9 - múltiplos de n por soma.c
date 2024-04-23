#include <stdio.h>
#include <stdlib.h>

int main(){
    int k, i, j, n, soma;

    i = 0;
    j = 1;
    k = 0;

    printf("Insira um n%cmero para saber seus m%cltiplos.\n", 163, 163);
    scanf("%d", &n);

    while (i <= 1)
    {
        printf("\nQuantos m%cltiplos deseja que sejam exibidos?\n", 163);
        scanf("%d", &i);
        
        if (i < 0){
            printf("\nA quantidade n%co pode ser menor que \"1\".\n", 198);
        } else if (i == 1){
            printf("\nO 1%c m%cltiplo de %d %c ele mesmo: %d.\n", 167, 163, n, 130, n);
            return 0;
        }        
    }
    
    for (soma = n; j <= i; soma+=n)
    {
        j++;
        k++;
        printf("O %d%c m%cltiplo de %d %c: %d\n", k, 167, 163, n, 130, soma);
    }    

    return 0;
}