#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto
{
    float x, y;
    struct Ponto *prox;
} ponto;

ponto *primeiro;

int tam;

void menu(){
    
}

void addIni( float x, float y){
    ponto *p = (ponto*) malloc(sizeof(ponto));
    p->x = x;
    p->y = y;
    p->prox = primeiro;
    primeiro = p;    
    tam++;
}

void addFim( float x, float y){
    ponto *p = (ponto*) malloc(sizeof(ponto));
    p->x = x;
    p->y = y;
    p->prox = NULL;

    if (primeiro == NULL) primeiro = p;
    else {
        ponto *aux = primeiro;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = p;
    }
    tam++;
}


void addPos( float x, float y, int pos){
    ponto *p = (ponto*) malloc(sizeof(ponto));
    p->x = x;
    p->y = y;

    if (pos > tam) printf("posicao invalidan\n");
    else {
        if (pos == 0)
        {
            p->prox = primeiro;
            primeiro = p;
        } else {
            ponto *aux = primeiro;

            for (int i = 0; i < pos - 1; i++)
            {
                aux = aux->prox;
            }

            p->prox = aux->prox;
            aux->prox = p;
            tam++;
        }
    }  
}

void remover(int pos){

    if (pos > tam || pos == 0) printf("posicao invalidan ou lista vazia\n");
    else {
        if (pos == 0)
        {
            primeiro = primeiro->prox;
        } else {
            ponto *aux = primeiro;

            for (int i = 0; i < pos - 1; i++)
            {
                aux = aux->prox;
            }
            aux->prox = aux->prox->prox;
        }

        tam--;
    }  
}

void imprimir(ponto *p){
    
    if(p != NULL)
    {
        printf("Ponto (%.1f, %.1f)\n", p->x, p->y);
        imprimir(p->prox);
    }
}

int main (){
    int op = 0;

    while (op != 6)
    {
        menu();

        switch (op)
        {
            case 1:
                //addini
            break;
            case 2:
                //addfim
            break;
            case 3:
                //addpos
            break;
            case 4:
                //remover
            break;
            case 5:
                //imprimir
            break;
            case 6:
                system("exit");
            break;
            default:
                printf("opcao invalida");
            break;
        }
        system("pause");
    }
    return 0;
}

