#include <stdio.h>
#include <stdlib.h>

struct Aluno //estrutura com os dados do aluno
{
    int matricula;
    char nome[10];
    float nota1, nota2, nota3;
};

struct Aluno cadastro() //função para realizar o cadastro das informações dos alunos
{
    struct Aluno a;

    puts("Nome:");
    fflush(stdin);
    scanf("%s", a.nome);

    printf("Matr%ccula:\n", 213);
    scanf("%d", &a.matricula);

    puts("Nota da primeira prova:");
    scanf("%f", &a.nota1);
    puts("Nota da segunda prova:");
    scanf("%f", &a.nota2);
    puts("Nota da terceira prova:");
    scanf("%f", &a.nota3);

    system("cls");

    return a;
}

int posicao(float notas[5]) //função para verificar a maior nota na primeira prova. Recebe como parâmetro um vetor com as notas da primeira prove e retorna a posição da maior nota
{
    int pos = 0, i;

    for (i = 0; i <= 4; i++)
    {
        if(notas[i] > notas[pos]) pos = i;
    }

    return pos;
}

float medias(struct Aluno alunos) //função que calcula as médias. Recebe a estrutura alunos em determinada posição, calcula a média e devolve a média para essa posição
{
    float media;

    media = (alunos.nota1 + alunos.nota2 + alunos.nota3)/3;
    
    return media;
}

int mediamaior(float media[5]) //função que compara as médias. Recebe o vetor com as médias, compara e devolve a posição da maior média.
{
    int pos = 0, i;

    for (i = 0; i <= 4; i++)
    {
        if(media[i] > media[pos]) pos = i;        
    }

    return pos;
}

int mediamenor(float media[5]) //função que compara as médias. Recebe o vetor com as médias, compara e devolve a posição da menor média.
{
    int pos = 0, i;

    for (i = 0; i <= 4; i++)
    {
        if(media[i] < media[pos]) pos = i;        
    }

    return pos;
}

int main()
{
    struct Aluno alunos[5];
    int i;
    float media[5], notas[5];

    for (i = 0; i <= 4; i++) //realizar o cadastro e chamar a função média para os 5 alunos. 
    {
        alunos[i] = cadastro();
        notas[i] = alunos[i].nota1; //guarda as notas da primeira prova em um vetor para ser comparado posteriormente na função posição
        media[i] = medias(alunos[i]);
    }
    
    printf("O aluno com a maior nota na primeira prova foi o \"%s\" e sua nota foi: %.2f.\n", alunos[posicao(notas)].nome, alunos[posicao(notas)].nota1);
    printf("O aluno com a maior m%cdia foi o \"%s\" com: %.2f.\n", 130, alunos[mediamaior(media)].nome, media[mediamaior(media)]);
    printf("O aluno com a menor m%cdia foi o \"%s\" com: %.2f.\n\n", 130, alunos[mediamenor(media)].nome, media[mediamenor(media)]);
    
    for (i = 0; i < 5; i++) //verificar para cada média se o aluno está aprovado ou reprovado, e imprimir o redultado.
    {
        if (media[i] >= 7) printf("O aluno %s est%c aprovado.\n", alunos[i].nome, 160);
        else printf("O aluno %s est%c reprovado.\n", alunos[i].nome, 160); 
    }
    
    return 0;
}