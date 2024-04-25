#include <stdio.h>
#include <stdlib.h>

struct Endereco //estrutura do endereço
{
    char rua[20], cidade[20], estado[20];
    int num, cep;
};

struct Data //estrutura da data de nascimento
{
    int dia, mes, ano;
};

struct Endereco endereco(){ //função para pedir os dados de endereço

    struct Endereco a;

    printf("Insira seu endere%co.\n", 135);
    fflush(stdin);
    printf("N%cmero:\n", 163);
    scanf("%d", &a.num);

    puts("Rua:");
    scanf("%s", a.rua);

    puts("Cidade:");
    scanf("%s", a.cidade);

    puts("Estado:");
    scanf("%s", a.estado);

    puts("CEP:");
    scanf("%d", &a.cep);

    system("cls");

    return a;
}

struct Data nascimento (){ //função para pedir os dados de data de nascimento
    struct Data b;

    printf("Insira sua data de nascimento:\n");
    puts("dia:");
    scanf("%d", &b.dia);

    printf("M%cs:\n", 136);
    scanf("%d", &b.mes);

    puts("Ano:");
    scanf("%d", &b.ano);

    system("cls");

    return b;
}

struct Pessoa //estrutura geral contendo as demais informações e a estrutura de data e endereço
{
    char nome[15], sexo[15];
    float peso;
    struct Data a;
    struct Endereco b;
};

int main (){
    struct Pessoa eu;

    puts("Insira seus dados."); //pedindo os dados que não estão nas funções de data e endereço
    puts("Nome:");
    scanf("%s", eu.nome);

    system("cls");

    puts("Sexo:");
    scanf("%s", eu.sexo);

    system("cls");

    puts("Peso:");
    scanf("%f", &eu.peso);

    system("cls");

    eu.a = nascimento(); //chamando a função nascimento e atribuindo a estrutura Data 'b' de dentro da função à estrutura Data 'a' dentro da estrutura geral Pessoa
    eu.b = endereco(); //chamando a função endereço e atribuindo a estrutura Endereço 'a' de dentro da função à estrutura Endereço 'b' dentro da estrutura geral Pessoa

    printf("%s.\n%s.\n%.2f.\n%d/%d/%d.\nRua %s. Num %d. %s-%s. CEP = %d.\n", eu.nome, eu.sexo, eu.peso, eu.a.dia, eu.a.mes, eu.a.ano, eu.b.rua, eu.b.num, eu.b.cidade, eu.b.estado, eu.b.cep);

    return 0;

}