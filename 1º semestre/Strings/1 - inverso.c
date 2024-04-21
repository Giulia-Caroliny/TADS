#include <stdio.h>
#include <string.h>

int main() {
    char palavra1[11], palavra2[11], palavra3[11];
    int i;

    printf("Digite a primeira palavra: ");
    gets(palavra1);

    printf("Digite a segunda palavra: ");
    gets(palavra2);

    printf("Digite a terceira palavra: ");
    gets(palavra3);

    printf("As palavras na ordem inversa s%co:\n", 198);

    printf("Primeira palavra: ");
    for (i =  strlen(palavra1) - 1; i >= 0; i--) 
    {
        printf("%c", palavra1[i]);
    }
    printf("\n");

    printf("Segunda palavra: ");
    for (i =  strlen(palavra2) - 1; i >= 0; i--) 
    {
        printf("%c", palavra2[i]);
    }
    printf("\n");

    printf("Terceira palavra: ");
    for (i =  strlen(palavra3) - 1; i >= 0; i--) 
    {
        printf("%c", palavra3[i]);
    }
    printf("\n");

    return 0;
}
