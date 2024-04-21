#include <stdio.h>

int main() {
    char palavra[] = "batatinha";
    int i, vogais = 0, consoantes = 0;

    printf("Vogais: ");

    for (i = 0; palavra[i] != '\0'; i++) 
    {
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u') {
            printf("%c ", palavra[i]);
        }
    }

    printf("\n");

    printf("Consoantes: ");

    for (i = 0; palavra[i] != '\0'; i++) 
    {
        if (palavra[i] != 'a' && palavra[i] != 'e' && palavra[i] != 'i' && palavra[i] != 'o' && palavra[i] != 'u') 
        {
            printf("%c ", palavra[i]);
        }
    }

    printf("\n");

    for (i = 0; palavra[i] != '\0'; i++) 
    {
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u') 
        {
            vogais++;
        } else {
            consoantes++;
        }
    }

    printf("Quantidade de vogais: %d\n", vogais);
    printf("Quantidade de consoantes: %d\n", consoantes);

    return 0;
}