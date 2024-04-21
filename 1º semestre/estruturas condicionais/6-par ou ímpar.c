#include <stdio.h>

int main ()
{
    int num, resto;

    printf("Digite um n%cmero:", 163);
    scanf("%d", &num);

resto = num % 2;

if (resto==1){
    printf("Ele %c um n%cmero %cmpar", 130, 163, 214);
} 
else {
    printf("Ele %c um n%cmero par", 130, 163);
}

return 0;
    
}