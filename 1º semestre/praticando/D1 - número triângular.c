#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, soma, i;

    soma = 0 
    ;

    printf("Insira um n%cmero para saber se %c tri%cngular.\n", 163, 130, 131);
    scanf("%d", &n);

    while (n <= 0)
    {
        printf("O n%cmero n%co pode ser menor ou igual a zero.\nInsira um n%cmero v%clido.", 163, 198, 163, 160);
        scanf("%d", &n);
    }
    
    for (i = 1; soma < n; i++)
    {
        soma = soma + i;
    }
    
    if (soma == n) printf("O n%cmero %c tri%cngular.", 163, 130, 131);
    else printf("O n%cmero n%co %c tri%cngular.", 163, 198, 130, 131);
    
    return 0;
}