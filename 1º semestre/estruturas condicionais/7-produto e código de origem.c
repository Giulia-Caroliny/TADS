#include <stdio.h>

int main() {

int codigo;
float valor;

printf("Insira o valor do produto e seu c%cdigo de origem:", 162);
scanf("%f", &valor);
scanf("%d", &codigo);

switch (codigo)
{
    case 1: printf("%.2f %c Sul.", valor, 196);
    break;
    case 2: printf("%.2f %c Norte.", valor, 196);
    break;
    case 3: printf("%.2f %c Leste.", valor, 196);
    break;
    case 4: printf("%.2f %c Oeste.", valor, 196);
    break;
    case 5: printf("%.2f %c Nordeste.", valor, 196);
    break;
    case 6: printf("%.2f %c Sudeste.", valor, 196);
    break;
    case 7: printf("%.2f %c Centro Oeste.", valor, 196);
    break;
    case 8: printf("%.2f %c Centro Sul.", valor, 196);
    break;
    default: printf("C%cdigo de origem do produto inv%clido.", 162, 160);
}

return 0;

}