#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    float conjunto1[12], conjunto2[12], verificar;
    int i, j, k = 0, quant = 0;
    bool v;

    for (i = 0; i < 12; i++)
    {
        system ("cls");
        printf ("1%c conjunto.\nInsira o %d%c n%cmero.\n", 167, i + 1, 167, 163);
        scanf ("%f", &verificar);

        j = 0;
        v = 0;

        do
        {
            if (v == 1) break;
            v = (verificar == conjunto1[j]);

            j++;
        } while (j < i);

        if (v == 0) conjunto1[i] = verificar;  
    }
    
    for (i = 0; i < 12; i++)
    {
        system ("cls");
        printf ("2%c conjunto.\nInsira o %d%c n%cmero.\n", 167, i + 1, 167, 163);
        scanf ("%f", &verificar);

        j = 0;
        v = 0;

        do
        {
            if (v == 1) break;
            v = (verificar == conjunto2[j]);

            j++;
        } while (j < i);

        if (v == 0) conjunto2[i] = verificar;

        j = 0;

        for (j = 0; j < 12; j++)
        {
            if (conjunto2[i] == conjunto1[j]) quant++; 
        }
    }

    system ("cls");

    float intersecao[quant];

    if (quant == 0){
        printf("N%co h%c valores no conjunto interse%c%co.\n", 198, 160, 135, 198);
    }
    
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (conjunto1[i] == conjunto2[j])
            {
                intersecao[k] = conjunto1[i];
                k++;
            }
            
        }
            
    }

    printf ("A interse%c%co dos conjuntos contempla os valores:\n", 135, 198);
    for (i = 0; i < quant; i++)
    {
        printf ("%.2f\n", intersecao[i]);
    }
    return 0;
}