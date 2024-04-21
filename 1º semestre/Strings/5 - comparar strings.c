#include <stdio.h>
#include <string.h>


int main() {
    char string1[100];
    char string2[100];
    char resultado[200];

    printf("Digite a primeira string: ");
    gets(string1);

    printf("Digite a segunda string: ");
    gets(string2);

    if (strcmp(string1, string2) == 0) {
        printf("Strings iguais\n");
    } else {
        printf("String 1: %s\n", string1);
        printf("String 2: %s\n", string2);

        strcpy(resultado, string1); // Copiar a primeira string para o resultado
        strcat(resultado, string2); // Concatenar a segunda string ao resultado
        printf("String resultante: %s\n", resultado);
    }

    return 0;
}
