#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Celula
{
    int bomba;
    int estaAberta;
    int vizinhos;
};

struct Celula jogo[10][10];
int l, c, tam = 10;

void iniciarJogo(){
    for (l = 0; l < tam; l++)
    {
        for (c = 0; c < tam; c++)
        {
            jogo[l][c].bomba = 0;
            jogo[l][c].estaAberta = 0;
            jogo[l][c].vizinhos = 0;
        }
    }
}

void sortearBombas(int n){
    int i;
    srand(time(NULL));

    for (i = 1; i <= n; i++)
    {
        l = rand()% tam;
        c = rand()% tam;
        if (jogo[l][c].bomba == 0) jogo[l][c].bomba = 1;
        else i--;
        
        jogo[l][c].bomba = 1;
    }
}

int coordenada(int l, int c){
    if (l >= 0 && l < tam && c >= 0 && c < tam) return 1;
    else return 0;
}

int bombasvizinhas(int l, int c){
    int quantidade = 0;

    if(coordenada(l - 1, c) && jogo[l - 1][c].bomba) quantidade++;
    if(coordenada(l + 1, c) && jogo[l + 1][c].bomba) quantidade++;
    if(coordenada(l, c - 1) && jogo[l][c - 1].bomba) quantidade++;
    if(coordenada(l, c + 1) && jogo[l][c + 1].bomba) quantidade++;
    if(coordenada(l - 1, c - 1) && jogo[l - 1][c - 1].bomba) quantidade++;
    if(coordenada(l + 1, c - 1) && jogo[l + 1][c - 1].bomba) quantidade++;
    if(coordenada(l - 1, c + 1) && jogo[l - 1][c + 1].bomba) quantidade++;
    if(coordenada(l + 1, c + 1) && jogo[l + 1][c + 1].bomba) quantidade++;

    return quantidade;
}

void contarBombas(){
    for (l = 0; l < tam; l++)
    {
        for (c = 0; c < tam; c++)
        {
            jogo[l][c].vizinhos = bombasvizinhas(l, c);
        }
    }
}

void imprimir(){
    printf("\n\t    ");
    for (l = 0; l < tam; l++)
    {
        printf(" %d  ", l);
    }
    printf("\n\t   ----------------------------------------- \n");    
    for (l = 0; l < tam; l++)
    {
        printf("\t%d  |", l);
        for (c = 0; c < tam; c++)
        {
            if(jogo[l][c].estaAberta){
                if (jogo[l][c].bomba)
                {
                    printf(" * ");
                }else{
                    printf(" %d ", jogo[l][c].vizinhos);
                }
            } else {
                printf("   ");
            }
            printf("|");
        }
        printf("\n\t   -----------------------------------------  \n");    

    }

}

void abrircelula(int l, int c){
    if(coordenada(l, c) == 1 && jogo[l][c].estaAberta == 0){
        jogo[l][c].estaAberta = 1;
        if (jogo[l][c].vizinhos == 0)
        {
            abrircelula(l - 1, c);
            abrircelula(l + 1, c);
            abrircelula(l, c - 1);
            abrircelula(l, c + 1);
            
        }
    }
}

int ganhar(){
    int quant = 0;

    for (l = 0; l < tam; l++)
    {
        for (c = 0; c < tam; c++)
        {
            if(jogo[l][c].estaAberta == 0 && jogo[l][c].bomba == 0) quant++;
        }
    }
    return quant;
}

void jogar(){
    int linha, coluna;

    do{
        imprimir();
        do{
            printf("Insira os valores de linha e coluna:");
            scanf("%d", &linha);
            scanf("%d", &coluna);

            if (coordenada(linha, coluna) == 0) printf("Coordenada inv%clida.\n", 160);
        } while(coordenada(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1);
        abrircelula(linha, coluna);
    } while(ganhar() != 0 && jogo[linha][coluna].bomba == 0);
    system("cls");

    if(jogo[linha][coluna].bomba == 1) printf("\n\t\t Tururu! Voc%c perdeu.", 136);
    else printf("\n\t Weee are the champions, my frieend!!!\n\tParab%cns. Voc%c ganhou!", 130, 136);
    imprimir();
}

int main(){

    iniciarJogo();
    sortearBombas(10);
    contarBombas();
    jogar();
}