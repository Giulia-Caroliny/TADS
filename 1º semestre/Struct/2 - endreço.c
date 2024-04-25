#include <stdio.h>

struct Endereco
{
    char rua[20], cidade[20], estado[20];
    int num, cep;
};

int main()
{
    struct Endereco a;

    printf("Insira seu endere%co.\n", 135);
    puts("Rua:");
    scanf("%s", a.rua);

    printf("N%cmero:\n", 163);
    scanf("%d", &a.num);

    puts("Cidade:");
    scanf("%s", a.cidade);

    puts("Estado:");
    scanf("%s", a.estado);

    puts("CEP:");
    scanf("%d", &a.cep);

    printf("Endereco: casa num %d, rua %s, %s-%s, CEP num %d.\n", a.num, a.rua, a.cidade, a.estado, a.cep);

    return 0;
}
