#include <stdio.h>
#include <stdlib.h>

int main(){

    int valores[10], res, i;

    for ( i = 0; i < 10; i++)
    {
        printf("Insira o %d%c valor.\n", i + 1, 167);
        scanf("%d", &valores[i]);
    }
    
    system("cls");

    for (i = 0; i < 10; i++)
    {
        res = valores[i] % 2;

        if(res != 0) printf("O %d%c valor \"%d\" %c %cmpar.\n", i + 1, 167, valores[i], 130, 214);
    }
    
    return 0;
}