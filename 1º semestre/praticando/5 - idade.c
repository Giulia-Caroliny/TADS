#include <stdio.h>
#include <stdlib.h>

int main(){

    int j, idade;
    float soma, quant;

    j = 1;
    quant = 0;

    do{
        printf("\nInsira a 1%c idade.\n", 166);
        scanf("%d", &idade);

        if (idade == 0)printf("N%co foram inseridas nenhuma idade.", 198);    
        if (idade < 0)printf("A idade n%co pode ser negativa", 198);
    } while (idade <= 0);

    while (idade != 0){
        if (idade < 0) {
            printf("A idade n%co pode ser negativa.\n", 198);
        } else{
            soma = soma + idade;
            quant++;
            j++;
        }
        printf("Insira a %d%c idade ou insira \"0\" para verificar a m%cdia das idades inseridas.\n", j, 166, 130);
        scanf("%d", &idade);
    }

    printf("\nA m%cdia das idades %c: %.2f", 130, 130, soma / quant);
    return 0;
}