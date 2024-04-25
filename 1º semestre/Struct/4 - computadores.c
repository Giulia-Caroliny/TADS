#include <stdio.h>
#include <stdlib.h>

struct Computadores //estrutura com as informações dos computadores
{
    char marca[20];
    int ano;
    float peso;
};

struct Computadores cadastro() //função para realizar o cadastro. Retorna as informações para serem guardadas na estrutura geral
{
    struct Computadores a;
    printf("Cadastrar m%cquinas.\n", 163);
    puts("Marca do computador:");
    fflush(stdin);
    scanf("%s", a.marca);

    printf("Ano de fabrica%c%co:\n", 135, 198);
    scanf("%d", &a.ano);

    puts("Peso do computador:");
    scanf("%f", &a.peso);

    system("cls");

    return a;
}

void maquinas(int i, struct Computadores pcs[i]) //função para imprimir as especificações de cada máquina. Recebe a posição de dentro do vetor e a estrutura com as informações.
{
    printf("\nComputador %d.Especifica%c%ces:\n", i+1, 135, 228);
    printf("\tMarca: %s.", pcs[i].marca);
    printf("\tAno de fabrica%c%co: %d.", 135, 198, pcs[i].ano);
    printf("\tPeso: %.3f.\n", pcs[i].peso);
}

int main()
{
    struct Computadores pcs[3];
    int i;

    for (i = 0; i < 3; i++) //chamar a função cadastro para solicitar as informações e atribui-las à estrutura
    {
        pcs[i] = cadastro();
    }
    
    for (i = 0; i < 3; i++) //chama a função máquinas para imprimir as especificações de cada computador guardadas no vetor pcs.
    {
        maquinas(i, pcs);
    }   

    return 0;
}
