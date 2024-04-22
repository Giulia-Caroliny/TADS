#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, quant = 0;
    float valor[10], soma = 0;

    for (i = 0; i < 10; i++)
    {
        printf("Insira o %d%c n%cmero:\n", i + 1, 167, 163);
        scanf("%f", &valor[i]);

        if(valor[i] < 0) quant++;
        else soma = soma + valor[i];
    }
    
    system("cls");

    printf("Foram inseridos %d n%cmeros negativos e a soma dos n%cmeros positivos %c: %.2f.\n", quant, 163, 163, 130, soma);

    return 0;
}