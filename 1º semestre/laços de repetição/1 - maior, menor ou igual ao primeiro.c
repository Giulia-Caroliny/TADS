#include <stdio.h>
#include <stdlib.h>

int main(){

    int valor[20], i,  maior = 0, menor = 0, igual = 0;

    for ( i = 0; i < 20; i++)
    {
        printf("Insira o %d%c valor.\n", i + 1, 167);
        scanf("%d", &valor[i]);

        if( valor[i] > valor[0]) maior++;
        else if( valor[i] < valor[0]) menor++;
        else if( valor[i] == valor[0]) igual++;

    }

    printf("O 1%c valor digitado foi %d. \nDentre os demais valores, %d valores s%co iguais a %d, %d valores s%co maiores que %d e %d valores s%co menores que %d.\n", 167, valor[0], igual - 1, 198, valor[0], maior, 198, valor[0], menor, 198, valor[0]);

    return 0;
}