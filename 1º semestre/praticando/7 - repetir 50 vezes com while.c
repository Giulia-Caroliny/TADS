#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, a, b, c, d;

    i = 1;

    while (i <= 50)
    {
        printf("\nDigite 4 n%cmeros.\n", 163);
        scanf("%d %d %d %d", &a, &b, &c, &d);

        printf("A soma de %d, %d, %d e %d %c: %d.\n", a, b, c, d, 130, a + b + c + d);
        printf("Restam %d processos.\n", 50 - i);
        i++;
    }
    return 0;
}