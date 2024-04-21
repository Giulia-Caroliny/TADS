#include <stdio.h>
#include <string.h>


int main() {
    char palavra[50];
    int i, j;
    int palindromo = 1; // Variável para indicar se é um palíndromo ou não

    printf("Digite uma palavra: ");
    gets(palavra);

    // Verificar se é um palíndromo
    for (i = 0, j = strlen(palavra) - 1; i < j; i++, j--) 
    {
        if (palavra[i] != palavra[j]) {
            palindromo = 0;
            break;
        }
    }

    // Imprimir o resultado
    if (palindromo) {
        printf("A palavra %c um palindromo.\n", 130);
    } else {
        printf("A palavra n%co %c um palindromo.\n", 198, 130);
    }

    return 0;
}
