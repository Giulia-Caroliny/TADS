#include <stdio.h>
#include <stdlib.h>


int main() {
    int n, j, c, res, quant, quant2;
    float soma, media, nmaior, nmenor, mp1, mp;

    printf("Insira o 1%c n%cmero ou insira \"-1\" para acessar o menu.\n", 167, 163);
    scanf("%d", &n);
    
    nmaior = n;
    nmenor = n;
    mp1 = 0;
    quant2 = 0;
    j = 1;

    while (n != -1){
        soma = soma + n;
        quant++;
        media = soma / quant;
        if(nmaior < n) nmaior = n;
        if(nmenor > n) nmenor = n;
        res = n % 2;
        if(res == 0){
            mp1 = mp1 + n;
            quant2++;
        }
        j++;
        printf("Insira o %d%c n%cmero ou insira \"-1\" para acessar o menu.\n", j, 167, 163);
        scanf("%d", &n);
    }
    
    if (quant == 0){
        printf("Nenhum n%cmero inserido.", 163);
        return 0;
    }

    printf("\nMenu de op%c%ces.\nSelecione a fun%c%co desejada.\n(1)Soma dos n%cmeros digitados\n(2)Quantidade de n%cmeros digitados\n(3)M%cdia dos n%cmeros digitados\n(4)Maior n%cmero digitado\n(5)Menor n%cmero digitado\n(6)M%cdia dos n%cmeros pares\n(7)Sair do programa.\n", 135, 228, 135, 198, 163, 163, 130, 163, 163, 163, 130, 163);
    scanf("%d", &c);

    while(c < 1 || c > 7){
        printf("O n%cmero escolhido n%co representa uma op%c%co. Retornando ao menu de op%c%ces.\n", 163, 198, 135, 198, 135, 228);
        printf("\nMenu de op%c%ces.\nSelecione a fun%c%co desejada.\n(1)Soma dos n%cmeros digitados\n(2)Quantidade de n%cmeros digitados\n(3)M%cdia dos n%cmeros digitados\n(4)Maior n%cmero digitado\n(5)Menor n%cmero digitado\n(6)M%cdia dos n%cmeros pares\n(7)Sair do programa.\n", 135, 228, 135, 198, 163, 163, 130, 163, 163, 163, 130, 163);
        scanf("%d", &c);
    }

    do
    {
        switch(c){
            case 1: printf("A soma dos n%cmeros %c: %.2f\n", 163, 130, soma);
            break;
            case 2: printf("A quantidade de n%cmeros digitados foi: %d\n", 130, quant);
            break;
            case 3: printf("A m%cdia dos n%cmeros %c: %.2f\n", 130, 163, 130, media);
            break;
            case 4: printf("O maior n%cmero digitado foi: %.2f\n", 163, nmaior);
            break;
            case 5: printf("O menor n%cmero digitado foi: %.2f\n", 163, nmenor);
            break;
            case 6: printf("A m%cdia dos n%cmeros pares %c: %.2f\n", 130, 163, 130, mp = mp1 / quant2);
            break;
            default: printf("Op%c%co n%co identificada.", 135, 198, 198);
        }
        printf("\nMenu de op%c%ces.\nSelecione a fun%c%co desejada.\n(1)Soma dos n%cmeros digitados\n(2)Quantidade de n%cmeros digitados\n(3)M%cdia dos n%cmeros digitados\n(4)Maior n%cmero digitado\n(5)Menor n%cmero digitado\n(6)M%cdia dos n%cmeros pares\n(7)Sair do programa.\n", 135, 228, 135, 198, 163, 163, 130, 163, 163, 163, 130, 163);
        scanf("%d", &c);

    } while (c != 7);

    printf("Finalizando o programa.");

    return 0;
}