#include <stdio.h>
#include <stdlib.h>

int main(){

    int valor[7], i, quant;

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
        system("cls");
    }

    do
    {
        printf("Escolha a op%c%co:\n(1)quantidade de n%cmeros 2\n(2)quantidade de n%cmeros 3\n(3)quantidade de n%cmeros 5\n(4)Sair.\n", 135, 198, 163, 163, 163);
        scanf("%d", &i);

        system("cls");
        quant = 0;

        switch (i)
        {
            case 1: 
                for (i = 0; i < 7; i++)
                {
                    if(valor[i] == 2) quant++;
                }
        
                if(quant == 0) printf("N%co foram inseridos n%cmeros 2.\n", 198, 163);
                else printf("Foram inseridos %d n%cmeros 2.\n", quant, 163);

                system("pause");
            break;
            case 2: 
                for (i = 0; i < 7; i++)
                {
                    if(valor[i] == 3) quant++;
                }

                if(quant == 0) printf("N%co foram inseridos n%cmeros 3.\n", 198, 163);
                else printf("Foram inseridos %d n%cmeros 3.\n", quant, 163);

                system("pause");
            break;
            case 3: 
                for (i = 0; i < 7; i++)
                {
                    if(valor[i] == 5) quant++;
                }
        
                if(quant == 0) printf("N%co foram inseridos n%cmeros 5.\n", 198, 163);
                else printf("Foram inseridos %d n%cmeros 5.\n", quant, 163);

                system("pause");
            break;
            case 4:
            break;
            default:
                printf("Op%c%co n%co identificada.\n", 135, 198, 198);
                system("pause");
            break;
        }

        system("cls");
    } while (i != 4);

    puts("Encerrando programa.");
    return 0;
}