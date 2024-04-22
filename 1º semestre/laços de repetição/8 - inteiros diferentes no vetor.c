#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int vetor[8], i, j, verificar;
    bool v;

    for (i = 0; i < 8; i++)
    {
        system ("cls");
        printf ("Insira o %d%c n%cmero.\n", i + 1, 167, 163);
        scanf ("%d", &verificar);

        j = 0;
        v = 0;

        while (j < i)
        {
            if (v == 1) break;
            v = (verificar == vetor[j]);
            j++;
        }

        if (v == 0) vetor[i] = verificar;
        else
        {
            printf ("O n%cmero %d j%c foi inserido. Insira um n%cmero diferente.\n", 163, verificar, 160, 163);
            i--;
            system ("pause");
        }        
    }

    system ("cls");
    
    puts ("Os valores inseridos foram:\n");

    for (i = 0; i < 8; i++)
    {
        printf ("%d\n", vetor[i]);
    }
    
    return 0;
}