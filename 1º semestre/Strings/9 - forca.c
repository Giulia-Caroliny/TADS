#include <stdio.h>
#include <string.h>

int main() {
    char palavra[10] = "FORCA";  // Palavra a ser adivinhada
    char palavraAdivinhada[10];  // Palavra com as letras reveladas
    char letra;
    int tentativas = 5, ki = strlen(palavra);
    int palavraCompleta = 0;


    // Inicializa a palavra a ser adivinhada com asteriscos
    for (int i = 0; i < ki; i++) {
        palavraAdivinhada[i] = '*';
    }
    palavraAdivinhada[strlen(palavra)] = '\0';

    printf("Jogo da Forca\n");
    printf("A palavra tem %d letras. Tente adivinhar!\n", strlen(palavra));

    while (tentativas > 0 && !palavraCompleta) {
        printf("\nPalavra: %s\n", palavraAdivinhada);
        printf("Tentativas restantes: %d\n", tentativas);
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        int letraEncontrada = 0;

        for (int i = 0; i < ki; i++) {
            if (palavra[i] == letra) {
                palavraAdivinhada[i] = letra;
                letraEncontrada = 1;
            }
        }

        if (letraEncontrada) {
            printf("Parabéns! A letra está correta.\n");
        } else {
            printf("Ops! A letra não faz parte da palavra.\n");
            tentativas--;
        }

        if (strcmp(palavra, palavraAdivinhada) == 0) {
            palavraCompleta = 1;
        }
    }

    if (palavraCompleta) {
        printf("\nParabéns! Você acertou a palavra: %s\n", palavra);
    } else {
        printf("\nVocê perdeu! A palavra correta era: %s\n", palavra);
    }

    return 0;
}
