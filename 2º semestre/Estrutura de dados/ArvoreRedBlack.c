#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No{
    int cor_no;
    int chave_no;
    struct No *direita;
    struct No *esquerda;
    struct No *parente;
}No;

typedef struct Lado{
    int nivel;
    const char *Lado; 
    int pai;
}LadoEPai;

typedef struct Arvore{
    No *raiz; 
}Arvore;

No* criarRaiz(){
    No *nulo;
    nulo = (No *) calloc(1, sizeof(No));

    if(!nulo){
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    nulo -> cor_no = 1;
    nulo -> direita = NULL;
    nulo -> esquerda = NULL;
    nulo -> parente = NULL;
    nulo -> chave_no = 1000;

    return nulo;
}

int alturaNo(No *r, No *nulo){
    if(r == nulo){
        return -1;
    }
    if(alturaNo(r -> esquerda, nulo) > alturaNo(r -> direita, nulo)){
        return (alturaNo(r -> esquerda, nulo) + 1);

    }else{
        return (alturaNo(r -> direita, nulo) + 1);

    }
}

Arvore* criarArvore(No *nulo){
    Arvore *av;

    av = (Arvore *)calloc(1, sizeof(Arvore));
    if(!av){
        printf("Erro ao alocar memória no fim do programa.");
        exit(1);
    }

    av -> raiz = nulo;

    return av;
}

int arvoreVazia(Arvore *a, No *nulo){
    if(a -> raiz == nulo){
        return 1;
    }
    return 0;
}

int ordem(No *no, No *nulo){
    if(no == nulo){
        return 0;

    }else{
        ordem(no -> esquerda, nulo);
        printf("Número: %d\n", no -> chave_no);
        if(no -> cor_no == 1){
            printf("Cor: Preto\n\n");

        }else{
            printf("Cor: Vermelho\n\n");

        }
        ordem(no -> direita, nulo);
    }
}

int rodarDireita(No *no, Arvore *a){
    No *aux = no->esquerda;
    no->esquerda = aux->direita;

    if(aux->direita && aux->direita->chave_no != 1000) {
        aux->direita->parente = no;
    }

    aux->parente = no->parente;

    if (a->raiz == no) {
        a->raiz = aux;
    } else {
        if (aux->parente) {
            if (aux->parente->direita == no) {
                aux->parente->direita = aux;
            } else {
                aux->parente->esquerda = aux;
            }
        }
    }

    aux->direita = no;
    no->parente = aux;

    return 1;
}


int rodarEsquerda(No *no, Arvore *a){
    No *aux = no->direita;
    no->direita = aux->esquerda;

    if(aux->esquerda && aux->esquerda->chave_no != 1000) {
        aux->esquerda->parente = no;
    }

    aux->parente = no->parente;

    if (a->raiz == no) {
        a->raiz = aux;
    } else {
        if (aux->parente) {
            if (aux->parente->esquerda == no) {
                aux->parente->esquerda = aux;
            } else {
                aux->parente->direita = aux;
            }
        }
    }

    aux->esquerda = no;
    no->parente = aux;

    return 1;
}


void corrigir(No *no , Arvore *a){
    No *tio;

    while (no != a->raiz && no->parente->cor_no == 0) {
        if (no->parente == no->parente->parente->esquerda) {
            tio = no->parente->parente->direita;

            if (tio && tio->cor_no == 0) {
                no->parente->cor_no = 1;
                tio->cor_no = 1;
                no->parente->parente->cor_no = 0;
                no = no->parente->parente;
            } else {
                if (no == no->parente->direita) {
                    no = no->parente;
                    rodarEsquerda(no, a);
                }

                no->parente->cor_no = 1;
                no->parente->parente->cor_no = 0;
                rodarDireita(no->parente->parente, a);
            }
        } else {
            tio = no->parente->parente->esquerda;

            if (tio && tio->cor_no == 0) {
                no->parente->cor_no = 1;
                tio->cor_no = 1;
                no->parente->parente->cor_no = 0;
                no = no->parente->parente;
            } else {
                if (no == no->parente->esquerda) {
                    no = no->parente;
                    rodarDireita(no, a);
                }

                no->parente->cor_no = 1;
                no->parente->parente->cor_no = 0;
                rodarEsquerda(no->parente->parente, a);
            }
        }
    }

    a->raiz->cor_no = 1;
}


void inserirNo(Arvore *a, int info, No *nulo) {
    No *aux, *ant, *novoNo;

    novoNo = (No *)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro na memória.");
        exit(1);
    }

    novoNo->chave_no = info;
    novoNo->cor_no = 0; 
    novoNo->direita = nulo;
    novoNo->esquerda = nulo;

    aux = a->raiz;
    ant = nulo;

    while (aux != nulo) {
        ant = aux;
        if (info < aux->chave_no) {
            aux = aux->esquerda;
        } else {
            aux = aux->direita;
        }
    }

    novoNo->parente = ant;

    if (ant == nulo) {
        a->raiz = novoNo;
    } else if (info < ant -> chave_no) {
        ant->esquerda = novoNo;
    } else {
        ant->direita = novoNo;
    }

    corrigir(novoNo, a);
}

No* buscarMinimo(No *no , No *nulo){

    No *ant;

    while(no != nulo){

        ant = no;

        no = no -> esquerda;
    }

    return ant;
}

int consertar(Arvore *a, No *n){

    No *irmao;

    while(n != a -> raiz && n -> cor_no == 1 ){


        if(n == n -> parente -> esquerda){

            irmao = n -> parente -> direita;

            if(irmao -> cor_no == 0){

                irmao -> cor_no = 1; 
                n -> parente -> cor_no = 0 ; 
                rodarEsquerda(n -> parente, a); 
                irmao = n -> parente -> direita;
            }

            if(irmao -> esquerda -> cor_no == 1  && irmao -> direita -> cor_no == 1){

                irmao -> cor_no = 0; 
                n = n -> parente;
            }

            else{
                
                if(irmao -> direita -> cor_no == 1){

                    irmao -> esquerda -> cor_no = 1; 
                    irmao -> cor_no= 0;
                    rodarDireita(irmao, a);
                    irmao = n -> parente -> direita;
                }

                irmao -> cor_no = n -> parente -> cor_no;
                n -> parente -> cor_no = 1;
                irmao -> direita -> cor_no = 1;
                rodarEsquerda(n -> parente, a);
                n = a -> raiz;
            }
        }
        else{

            irmao = n -> parente -> esquerda;

            if(irmao -> cor_no == 0){

                irmao -> cor_no = 1;
                n -> parente -> cor_no = 0 ;
                rodarDireita(n ->parente, a); 
                irmao = n -> parente -> esquerda;
            }
            if( irmao -> esquerda -> cor_no == 1  && irmao -> direita -> cor_no == 1){
                irmao -> cor_no = 0; 
                n = n -> parente;
            }

            else{

                if(irmao -> esquerda -> cor_no == 1){
                    irmao -> direita -> cor_no = 1; 
                    irmao -> cor_no = 0;	
                    rodarEsquerda(irmao, a);
                    irmao = n -> parente -> esquerda;
                }

                irmao -> cor_no = n -> parente -> cor_no;
                n -> parente -> cor_no = 1;
                irmao -> esquerda ->cor_no = 1;
                rodarDireita(n -> parente, a);
                n = a -> raiz;
            }
        }
    }

    n -> cor_no = 1; 

    return 1;
}

No* buscarMaximo(No *no , No *nulo){

    No *ant;

    while(no != nulo){

        ant = no;

        no = no -> direita;
    }

    return ant;
}

int deletarNo(Arvore *a , int info , No *nulo){

    No *aux,*guarda;
    No *maximo;

    No *x;
    int corRemovida;

    aux = a -> raiz;

    while(aux != nulo && aux -> chave_no != info){

        if(info < aux->chave_no){
            aux = aux -> esquerda;
        }
        else{
            aux = aux -> direita;
        }

    }

    if(aux == nulo){
        printf("Erro: Nó com chave %d não encontrado.\n", info); 
        return 0; 
    }

    while(1){

        corRemovida = aux -> cor_no;

        if(aux -> direita == nulo){

            x = aux -> esquerda;

            if( aux -> parente != nulo ){

                if(aux -> esquerda != nulo) aux -> esquerda -> parente = aux -> parente;

                if( aux -> parente -> chave_no >= aux -> chave_no){
                    aux -> parente -> esquerda = aux -> esquerda;
                }
                else aux -> parente -> direita = aux -> esquerda;
            }
            else{

                a -> raiz = aux -> esquerda;

                if( aux -> esquerda != nulo ) aux -> esquerda -> parente = aux -> parente;
            }

            break;
        }

        else if( aux -> esquerda == nulo){
            x = aux -> direita;

            if(aux -> parente != nulo){

                aux -> direita -> parente = aux -> parente;

                if( aux -> parente -> chave_no > aux -> chave_no ){
                    aux -> parente -> esquerda = aux -> direita;
                }
                else aux -> parente -> direita = aux -> direita;
            }
            else{

                a -> raiz = aux -> direita;

                if( aux -> direita != nulo) aux -> direita -> parente = aux -> parente;
            }
            break;

        }
        
        else{

            maximo = buscarMaximo(aux -> esquerda, nulo);

            aux -> chave_no = maximo -> chave_no;
            aux = maximo;

        }
    }

    guarda = aux -> parente;

    free(aux);

    if(corRemovida == 1 ){

        if(x == nulo){
            x -> parente = guarda;
        }
        consertar(a, x);
    }

    printf("Nó com chave %d deletado com sucesso.\n", info); 

    return 1;
}


int nivelDoNo(No *raiz, int chave, No *nulo, int nivel) {
    if (raiz == nulo) {
        return -1; 
        
    }

    if (raiz -> chave_no == chave) {
        return nivel; 
    }

    if (chave < raiz -> chave_no) {
        return nivelDoNo(raiz -> esquerda, chave, nulo, nivel + 1);
    }
    
    else {
        return nivelDoNo(raiz -> direita, chave, nulo, nivel + 1);
    }
}

int encontrarNivel(No *raiz, int chave, No *nulo) {
    return nivelDoNo(raiz, chave, nulo, 0);
}

LadoEPai encontrarLadoEPai(No *raiz, int chave, No *nulo, int paiAtual) {
    LadoEPai resultado = {-1, NULL, -1};

    if (raiz == nulo) {
        return resultado;
    }

    if (raiz -> chave_no == chave) {
        resultado.nivel = 0;
        resultado.pai = paiAtual; 
        return resultado;
    }

    if (chave < raiz -> chave_no) {
        resultado = encontrarLadoEPai(raiz->esquerda, chave, nulo, raiz->chave_no);
        if (resultado.nivel != -1) {
            resultado.nivel++;
            resultado.Lado = "esquerdo";
        }
    } else {
        resultado = encontrarLadoEPai(raiz->direita, chave, nulo, raiz->chave_no);
        if (resultado.nivel != -1) {
            resultado.nivel++;
            resultado.Lado = "direito";
        }
    }

    return resultado;
}

int main(){
    No *vazio = criarRaiz();
    Arvore *arvore = criarArvore(vazio);
   	LadoEPai result;
    setlocale(LC_ALL, "portuguese");

    int opcao, op, valor, valorDel, valorBusca, alturaArvore;

    do {
        system("cls");
        printf("+---------------------- •??• ----------------------+\n");
        printf("•       Bem-Vindo a Nossa Arvore Red Black!         •\n");
        printf("•                                                   •\n");
        printf("•	ESCOLHA A OPÇÃO DESEJADA:              			•\n");
        printf("•   	(1) Inserir números                         •\n");
        printf("•   	(2) Remover                                 •\n");
        printf("•   	(3) Imprimir                                •\n");
        printf("•   	(4) Imprimir Especificidades               •\n");
        printf("•   	(5) Nível                                   •\n");
        printf("•   	(0) Sair do programa                        •\n");
        printf("•                                                   •\n");
        printf("+---------------------- •??• -----------------------+\n\nSelecione: ");
       	scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                system("cls");
                printf("Insira um número: ");
                scanf("%d", &valor);
                inserirNo(arvore, valor, vazio);
                do{
                    system("cls");
                	printf("Deseja inserir outro número ?\n");
                	printf("1 - SIM \t 0 - NÃO\nSelecione: ");
                	scanf("%d", &op);
                	
                	switch(op){
                		case 1:
                			printf("Insira um número: ");
                			scanf("%d", &valor);
                			inserirNo(arvore, valor, vazio);
                			break;
						case 0:
							break;
						default:
							printf("Insira um valor válido!!");
					}
                	
				}while(op!=0);
                
                break;

            case 2:
                system("cls");
                printf("Insira o valor a ser removido: ");
                scanf("%d", &valorDel);
                deletarNo(arvore, valorDel, vazio);
                system("pause");
				break;

            case 3:
                system("cls");
                ordem(arvore -> raiz, vazio);
                system("pause");
                break;

            case 4:
                system("cls");
                printf("Número para busca: ");
                scanf("%d", &valorBusca);

                result = encontrarLadoEPai(arvore->raiz, valorBusca, vazio, -1);

                if (result.nivel != -1) {
                    if (result.pai == -1){
                        printf("\nO elemento %d não possui pai - ele é a raiz!\n", valorBusca);
                    }
                    else{
                        printf("\nO elemento %d está \nNo nivel %d \nNo lado %s \nSeu pai é o número %d\n", valorBusca, result.nivel, result.Lado, result.pai);
                    }
                } else {
                    printf("\nO elemento %d não foi encontrado na árvore.\n", valorBusca);
                }
                system("pause");
            	break;

            case 5:
                system("cls");
                alturaArvore = alturaNo(arvore -> raiz, vazio);
                if(alturaArvore == -1){
                    printf("Nao existe raiz na árvore!\n\n");
                }else {
                    printf("Altura da árvore é: %d\n", alturaArvore);
                }
                system("pause");
            	break;

            case 0:
            	break;
            default:
				printf("Insira um valor válido!!");
				break;
        }

    }while(opcao != 0);
    
    
    system("cls");
	printf("ARVORE ENCERRADA! Até a próxima :D");

    return 0;
}

