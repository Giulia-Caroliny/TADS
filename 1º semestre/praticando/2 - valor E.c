#include <stdio.h>
#include <stdlib.h>

int main() {

    float E, i, n, n1, fat;

    printf("Digite um n%cmero:", 163);
    scanf("%f", &n);

    E = 1;
    for(i = 1; i <= n; i++){
        fat = 1;
        for (n1 = 1; n1 <= i; n1++){
            fat = fat * n1;
        }
        E = E + 1/fat;
    }
    
    printf("\nO valor \"E\" %c: %f", 130, E);
            
    return 0;
}