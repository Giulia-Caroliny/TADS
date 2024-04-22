#include <stdio.h>
#include <stdlib.h>

int main(){

    float valor[8];
    int x, y, i;

    for (i = 0; i < 8; i++)
    {
        printf("Insira o %d%c valor:\n", i + 1, 167);
        scanf("%f", &valor[i]);
    }
    
    system("cls");

    do
    {
        printf("Digite a posi%c%co dos valores a serem somados.\n", 135, 198);
        scanf("%d %d", &x, &y);
        
        if(x > 8 || y > 8 || x < 1 || y < 1) printf("Valores inexistentes.\n");

        system("pause");
        system("cls");

    } while (x > 8 || y > 8 || x < 1 || y < 1);
        
    printf("%.2f + %.2f = %.2f\n", valor[x-1], valor[y-1], valor[x-1] + valor[y-1]);

    return 0;
}