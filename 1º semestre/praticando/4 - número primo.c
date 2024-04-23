#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, i, res, quant;

    i = 1;
    quant = 1;

    do{
        printf("Digite um n%cmero:\n", 163);
        scanf("%d", &n);
        if(n < 0) printf("O n%cmero %c inferior ou igual a zero. Insira um n%cmero positivo.\n", 163, 130, 163);
    } while (n < 0);
    
    if(n == 1) printf("O n%cmero 1 n%co %c primo.", 163, 198, 130);
    else{
        while (i < 8)
        {
            res = n % i;
            if (res == 0 && i != n) quant++;
            i++;        
        }

        if (quant != 2) printf("\nO n%cmero n%co %c primo.", 163, 198, 130);
        else printf("\nO n%cmero %c primo.", 163, 130);
    }
    return 0;
}