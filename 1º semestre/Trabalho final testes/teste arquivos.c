#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Palavras
{
    char b[11];
};


int main(){

    FILE* peixe = fopen("a.txt", "w");
    FILE* fonte = fopen("teste_palavras.txt", "r");
    struct Palavras c[25];
    int i;

    // fprintf(peixe, "teste");


    // int tamanho = 0;
    // while (fgets(c[tamanho].b, 11, fonte) != NULL) {
    //     tamanho += 2;
    // }
    char pular[11];
    for (i = 0; i < 25; i++)
    {
        fgets(pular, 11, fonte);
        fgets(c[i].b, 11, fonte);
    }
    

    for (i = 0; i < 25; i++)
    {
        printf("%s", c[i].b);
    }
    

    for (i = 0; i < 25; i++)
    {
        fprintf(peixe, "%s", c[i].b);
    }

    fclose(fonte);
    fclose(peixe);
    return 0;
}