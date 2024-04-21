#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char palavra[20];
    char palavraMaiuscula[20];

    printf("Digite uma palavra: ");
    gets(palavra);
    
    // Copiar a string original para a variável palavraMaiuscula
    strcpy(palavraMaiuscula, palavra);

    int length = strlen(palavraMaiuscula);

    // Converter para letras maiúsculas
    for (int i = 0; i < length; i++) {
        palavraMaiuscula[i] = toupper(palavraMaiuscula[i]);
    }

    printf("String original: %s\n", palavra);
    printf("String convertida: %s", palavraMaiuscula);

    return 0;
}
