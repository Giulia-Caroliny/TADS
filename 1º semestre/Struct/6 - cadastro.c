#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Endereco //estrutura do endereço
{
    char rua[20], bairro[20], cidade[20], estado[20];
    int cep;
};

struct Cadastro //estrutura geral contendo as informações e a estrutura endereço
{
    char nome[15], estadocivil[15], sexo[15];
    int rg, cpf, telefone, idade;
    float salario;
    struct Endereco a;
};

struct Endereco endereco(){ //função para pedir os dados de endereço

    struct Endereco a;

    printf("Insira seu endere%co.\n", 135);
    puts("Rua:");
    gets(a.rua);

    puts("Bairro:");
    gets(a.bairro);

    puts("Cidade:");
    gets(a.cidade);

    puts("Estado:");
    gets(a.estado);

    puts("CEP:");
    scanf("%d", &a.cep);

    system("cls");

    return a;
}

int maioridade(struct Cadastro cadastro[7]) //função para comparar os valores dentro do cadastro afim de achar a maior idade e retornar a posição em que se encontra.
{
    int pos = 0, i;

    for (i = 0; i <= 7; i++)
    {
        if(cadastro[i].idade > cadastro[pos].idade) pos = i;        
    }

    return pos;
}


int main (){
    struct Cadastro cadastro[7];
    int i, rg;
    char menino[] = "masculino";


    for (i = 0; i < 7; i++) //pedindo os dados que não está na função endereço
    {
        puts("Insira seus dados."); 
        puts("Nome:");
        gets(cadastro[i].nome);
        system("cls");

        cadastro[i].a = endereco(); //chamando a função endereço e atribuindo os dados inseridos à estrutura endereço dentro da estrutura cadastro

        printf("Sal%crio:", 160);
        scanf("%f", &cadastro[i].salario);
        system("cls");

        puts("RG:");
        scanf("%d", &cadastro[i].rg);
        system("cls");

        puts("CPF:");
        scanf("%d", &cadastro[i].cpf);
        system("cls");

        puts("Estado civil:");
        gets(cadastro[i].estadocivil);

        system("cls");

        puts("Telefona:");
        scanf("%d", &cadastro[i].telefone);
        system("cls");

        puts("Idade:");
        scanf("%d", &cadastro[i].idade);
        system("cls");

        puts("Sexo:");
        gets(cadastro[i].sexo);
        system("cls");
    }
    //pessoa com maior idade: chamando a função que tem como parâmetro o vetor cadastro para retornar a posição da maior idade dentro do vetor cadastro.
    printf("A pessoa cadastrada de maior idade %c o %s com %d anos.\n", 130, cadastro[maioridade(cadastro)].nome, cadastro[maioridade(cadastro)].idade);

    for (i = 0; i < 7; i++) //encontrar as pessoas que foram inseridos como masculino
    {
        if(strcmp(cadastro[i].sexo,menino) == 0) printf("%s %c menino.\n", cadastro[i].nome, 130);
    }
    
    for (i = 0; i < 7; i++) //verificar as pessoas inseridas que recebem mais que 1000
    {
        if(cadastro[i].salario > 1000) printf("%s tem o sal%crio superior a 1000 reais.\n", cadastro[i].nome, 160);
    }

    puts("Buscar cadastro.\nInsira o RG:");
    scanf("%d", &rg);

    for (i = 0; i < 7; i++)//verificar se o rg tem correnpondente nos cadastrados6
    {
        if(cadastro[i].rg == rg){
            printf("%s. RG: %d.\n Endere%co: rua %s, bairro %s, %s-%s. CEP: %d.\nSal%crio: %.2f.\nCPF: %d.\n%s.\nTelefone: %d.\n%d anos.\nSexo %s.\n", cadastro[i].nome, cadastro[i].rg, 135, cadastro[i].a.rua, cadastro[i].a.bairro, cadastro[i].a.cidade, cadastro[i].a.estado, cadastro[i].a.cep, 160, cadastro[i].salario, cadastro[i].cpf, cadastro[i].estadocivil, cadastro[i].telefone, cadastro[i].idade, cadastro[i].sexo);
            break;
        } else if(i == 6 && cadastro[i].rg != rg) //informar que não foi encontrado, se for esse o caso, e finalizar o sistema
        {
            puts("Cadastro inexistente."); 
            return 0;
        }
    }

    return 0;
}