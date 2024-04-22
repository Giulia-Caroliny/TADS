#include <stdio.h>
#include <stdlib.h>

int main(){

    int i;
    float valor[50];

    for (i = 0; i < 50; i++)
    {
        printf("Insira o %d %c valor:\n", i + 1, 167);
        scanf("%f", &valor[i]);

        if (valor[i] < 0) valor[i] = 0;
    }
    
    return 0;
}