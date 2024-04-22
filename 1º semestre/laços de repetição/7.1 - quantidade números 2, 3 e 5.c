#include <stdio.h>
#include<stdlib.h>

int main(){

    int valor[7], i, quant2 = 0, quant3 = 0, quant5 = 0;

    for (i = 0; i < 7; i++)
    {
        printf("Insira o %d%c n%cmero. Valores APENAS de 0 a 9.\n", i + 1, 167, 163);
        scanf("%d", &valor[i]);

        if(valor[i] > 9 || valor[i] < 0) 
        {
            printf("N%cmero inv%clido.\n", 163, 160);
            i--;
            system("pause");
        }
        else if(valor[i] == 2) quant2++;
        else if(valor[i] == 3) quant3++;
        else if(valor[i] == 5) quant5++;
        system("cls");
    }
    
    do
    {
        printf("Escolha a op%c%co:\n(1)quantidade de n%cmeros 2\n(2)quantidade de n%cmeros 3\n(3)quantidade de n%cmeros 5\n", 135, 198, 163, 163, 163);
        scanf("%d", &i);

        if(i > 3 || i < 1) 
        {
            printf("Op%c%co inv%clida.\n", 135, 198, 160);
            system("pause");
        }

        system("cls");
    } while (i > 3 || i < 1);
    
    switch (i)
    {
        case 1: printf("Foram inseridos %d n%cmeros 2.\n", quant2, 163);
        break;
        case 2: printf("Foram inseridos %d n%cmeros 3.\n", quant3, 163);
        break;
        case 3: printf("Foram inseridos %d n%cmeros 5.\n", quant5, 163);
        break;
    }
    return 0;
}