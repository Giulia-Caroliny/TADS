#include <stdio.h>
#include <stdlib.h>

int main(){

    int vetor1[20], vetor2[20], vetor3[20], i, res;

    for (i = 0; i < 20; i++)
    {
        printf("Vetor 1\nInsira o %d %c n%cmero:\n", i + 1, 167, 163);
        scanf("%d", &vetor1[i]);

        res = i % 2;

        if(res == 0) vetor3[i] = vetor1[i];

        system("cls");
    }
    
    for (i = 0; i < 20; i++)
    {
        printf("Vetor 2\nInsira o %d %c n%cmero:\n", i + 1, 167, 163);
        scanf("%d", &vetor2[i]);

        res = i % 2;

        if(res == 1) vetor3[i] = vetor2[i];

        system("cls");
    }

    puts("O terceiro vetor comtempla:\n");

    for (i = 0; i < 20; i++)
    {
        printf("%d\n", vetor3[i]);
    }
    
    return 0;
}