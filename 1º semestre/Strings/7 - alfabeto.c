#include <stdio.h>
#include <string.h>


char substituirLetra(char letra) {
    if (letra >= 'a' && letra <= 'z') {
        letra += 3;
        if (letra > 'z') {
            letra -= 26;
        }
    } else if (letra >= 'A' && letra <= 'Z') {
        letra += 3;
        if (letra > 'Z') {
            letra -= 26;
        }
    }
    
    return letra;
}

int main() {

    char palavra[20], palavraSubstituida[20];
    int i;
    
    printf("Digite uma palavra: ");
    fflush(stdin);
    scanf("%s", palavra);  
    
    for (i = 0; palavra[i] != '\0'; i++) {
        palavraSubstituida[i] = substituirLetra(palavra[i]);
    }
    
    printf("Palavra substituida: %s\n", palavraSubstituida);
    
    return 0;
}
