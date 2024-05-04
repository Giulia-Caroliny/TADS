#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <unistd.h>

//------------------------------------------------------------------------------------------------------------------------------//
// CABEÇALHO

void cabecalho(int op){ //função cabeçalho, recebe como parâmetro a opção que o usuário escolheu no menu
    int i;
    printf("\t");
    for (i = 0; i < 38; i++)
    {
        printf("-");
    }
    printf("\n\t| %c %c        ALEGROL%cNDIA        %c %c |", 94, 94, 182, 94, 94);

    switch(op) // usa o parâmetro op do usuário para colocar o nome no cabecalho e discriminar em que parte do sistema ele está
    {
        case 1:
            printf("\n\t|  U             Menu             U  |\n");
        break;
        case 2:
            printf("\n\t|  U         Jogo da Velha        U  |\n");
        break;
        case 3:
            printf("\n\t|  U         Jogo da Forca        U  |\n");
        break;
        case 4:
            printf("\n\t|  U           JoKenP%c            U  |\n", 147);
        break;
        case 5:
            printf("\n\t|  U     Jogo \"fui ao mercado\"    U  |\n");
        break;
        case 6:
            printf("\n\t|  U         Campo minado         U  |\n");
        break;
        case 7:
            printf("\n\t|  U            Snake             U  |\n");
        break;
        case 8:
            printf("\n\t|  U         Estatisticas         U  |\n");
        break;
    }
    printf("\t");
    for (i = 0; i < 38; i++)
    {
        printf("-");
    }
}

//------------------------------------------------------------------------------------------------------------------------------//
// MENU

int menu(){ //função que imprime na tela as opções do sistema e retorna a opção selecionada

    int i;

    system("cls");
    cabecalho(1); //chama a função cabeçalho

    puts("\n\tO que deseja jogar?");
    puts("\t(1) Jogo da velha.");
    puts("\t(2) Jogo da forca.");
    printf("\t(3) JoKenP%c.\n", 147);
    puts("\t(4) Jogo \"fui ao mercado e comprei ...\".");
    puts("\t(5) Jogo campo minado.");
    puts("\t(6) Jogo da cobrinha (snake).");
    puts("\t(7) Estatisticas.");
    puts("\t(8) Sair.");

    scanf("%d", &i);

    return i;
}

//------------------------------------------------------------------------------------------------------------------------------//
//Estruturas para salvar e recuperar as estatísticas

struct JogoVelha
{
    int jogador1;
    int jogador2;
    int velha;
};

struct JogoForca
{
    int vitorias;
    int derrotas;
};

struct JogoJokenpo
{
    int jogador;
    int computador;
    int empate;
};

struct JogoCampoMinado
{
    int vitorias;
    int derrotas;
};

struct Estatisticas 
{
    struct JogoVelha jvelha;
    struct JogoForca jforca;
    struct JogoJokenpo jjokenpo;
    int memoria;
    struct JogoCampoMinado jcampominado;
    int snake;
};

struct Estatisticas pudim;

//------------------------------------------------------------------------------------------------------------------------------//
// JOGO DA VELHA

void jogovelha(){
    int l, c, k = 3, linha, coluna, jogador, ganhou, jogadas, opcao, op, salvo;
    char jogo[3][3], converter[14], s[2], j1[2], j2[2];
    FILE *jogosalvo;

    system("cls");
    cabecalho(2);

    jogosalvo = fopen("pastel.txt", "r"); //abrir arquivo para verificar se tem jogo salvo e, se tiver, recuperá-lo
    fgets(converter, 14, jogosalvo);
    s[0] = converter[0]; //É na posição 0 que diz se há ou não um jogo salvo
    salvo = atoi(s);
    fclose(jogosalvo);

    do //enquanto o jogador escolher continuar jogando, opção do jogador for igual a 1
    {
        ganhou = 0;

        do //pede a opção ao usuário até ser inserido uma opção válida
        {
            if(salvo == 1){ //Se encontrar jogo salvo, pergunta ao usuário se ele deseja ou não carregar jogo
                printf("\nDeseja carregar jogo salvo? (1)Sim (0)N%co.", 198);
                scanf("%d", &op);
            }
        } while (op > 1 || op < 0);
        
        if (op ==1) //se o usuário quiser carregar o jogo nessa etapa será atribuído o jogo salvo ao jogo atual e o arquivo salvo será limpo
        {
            j1[0] = converter[1]; //É na posição 1 que diz qual jogador jogou por último no jogo salvo
            j2[0] = converter[2]; //É na posição 2 que diz quantas jogadas tinham sido feitas no jogo salvo
            jogador = atoi(j1);
            jogadas = atoi(j2);
            
            for (l = 0; l < 3; l++) //atribui o jogo salvo à matriz do jogo atual
            {
                for (c = 0; c < 3; c++)
                {
                    jogo[l][c] = converter[k];
                    k++;
                }           
            }

            //limpa os dados do arquivo e escreve o 0 (sem jogo salvo)
            jogosalvo = fopen("pastel.txt", "w");
            fprintf(jogosalvo, "0");
            fclose(jogosalvo);
            
        } else { //prepara o jogo: atribui todos os valores da matriz à ' ' (barra), o número de jogadas 0 e o primeiro jogador
            jogador = 1;
            jogadas = 0;
            for (l = 0; l < 3; l++)
            {
                for (c = 0; c < 3; c++)
                {
                    jogo[l][c] = ' ';
                }                
            }
        }

        do //enquanto ninguém vencer e as jogadas não ultrapassarem 9 (posições dentro da matriz)
        {
            system("cls");
            cabecalho(2);
            puts("\nPara voltar ao menu insira 8.");

            //imprime o jogo
            printf("\n\n\t 0   1   2\n\n");
            for (l = 0; l < 3; l++)
            {
                for (c = 0; c < 3; c++)
                {
                    if (c == 0) printf("\t");
                    printf(" %c ", jogo[l][c]);
                    if (c < 2) printf("|");
                    if (c == 2) printf(" %d", l);
                }
                if (l < 2) printf("\n\t-----------");
                printf("\n");                
            }

            do //pede as coordenadas para o usuário e verifica de são válidas
            {
                puts("\nJOGADOR 1 = O\nJOGADOR 2 = X");
                printf("\n JOGADOR %d, digite a linha e a coluna que deseja jogar: ", jogador);
                scanf("%d", &linha);

                if (linha == 8){ //se o jogador desejar sair
                    if (jogadas != 0) //se o jogo já tiver começado pergunta se quer salvar o jogo
                    {                   
                        do
                        {
                            printf("Deseja salvar o jogo? (1)Sim (0)N%co", 198);
                            scanf("%d", &op);
                        } while (op < 0 || op > 1);
                        
                        if (op == 1) //salva o jogo
                        {
                            fopen("pastel.txt", "w");
                            fprintf(jogosalvo, "1%d%d", jogador, jogadas);
                            for (l = 0; l < 3; l++)
                            {
                                for (c = 0; c < 3; c++)
                                {
                                    fprintf(jogosalvo, "%c", jogo[l][c]);
                                }
                            }
                            fclose(jogosalvo);
                        }
                    }
                    return;
                } 

                scanf("%d", &coluna);

                if (coluna == 8){ //se o jogador desejar sair
                    if (jogadas != 0) //se o jogo já tiver começado pergunta se quer salvar o jogo
                    {                   
                        do
                        {
                            printf("Deseja salvar o jogo? (1)Sim (0)N%co", 198);
                            scanf("%d", &op);
                        } while (op < 0 || op > 1);

                        if (op == 1) //salva o jogo
                        {
                            fopen("pastel.txt", "w");
                            fprintf(jogosalvo, "1%d%d", jogador, jogadas);

                            for (l = 0; l < 3; l++)
                            {
                                for (c = 0; c < 3; c++)
                                {
                                    fprintf(jogosalvo, "%c", jogo[l][c]);
                                }
                            }
                            fclose(jogosalvo);
                        }
                    }
                    return;
                } 
            } while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' '); //enquanto as coordenadas forem inválidas
            
            if (jogador == 1) jogo[linha][coluna] = 'O', jogador++;
            else jogo[linha][coluna] = 'X', jogador = 1;

            jogadas++;

            system("cls");
            cabecalho(2);

            //verifica se algum jogador venceu, imprime e alimenta as estatísticas
            if (jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O') printf("\nParab%cns! O jogador 1 venceu por linha!", 130), ganhou = 1, pudim.jvelha.jogador1++;
            if (jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O') printf("\nParab%cns! O jogador 1 venceu por linha!", 130), ganhou = 1, pudim.jvelha.jogador1++;
            if (jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O') printf("\nParab%cns! O jogador 1 venceu por linha!", 130), ganhou = 1, pudim.jvelha.jogador1++;

            if (jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X') printf("\nParab%cns! O jogador 2 venceu por linha!", 130), ganhou = 1, pudim.jvelha.jogador2++;
            if (jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X') printf("\nParab%cns! O jogador 2 venceu por linha!", 130), ganhou = 1, pudim.jvelha.jogador2++;
            if (jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X') printf("\nParab%cns! O jogador 2 venceu por linha!", 130), ganhou = 1, pudim.jvelha.jogador2++;

            if (jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O') printf("\nParab%cns! O jogador 1 venceu por coluna!", 130), ganhou = 1, pudim.jvelha.jogador1++;
            if (jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O') printf("\nParab%cns! O jogador 1 venceu por coluna!", 130), ganhou = 1, pudim.jvelha.jogador1++;
            if (jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O') printf("\nParab%cns! O jogador 1 venceu por coluna!", 130), ganhou = 1, pudim.jvelha.jogador1++;

            if (jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X') printf("\nParab%cns! O jogador 2 venceu por coluna!", 130), ganhou = 1, pudim.jvelha.jogador2++;
            if (jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X') printf("\nParab%cns! O jogador 2 venceu por coluna!", 130), ganhou = 1, pudim.jvelha.jogador2++;
            if (jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X') printf("\nParab%cns! O jogador 2 venceu por coluna!", 130), ganhou = 1, pudim.jvelha.jogador2++;

            if (jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O') printf("\nParab%cns! O jogador 1 venceu por diagonal principal!", 130), ganhou = 1, pudim.jvelha.jogador1++;
            if (jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') printf("\nParab%cns! O jogador 2 venceu por diagonal principal!", 130), ganhou = 1, pudim.jvelha.jogador2++;

            if (jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O') printf("\nParab%cns! O jogador 1 venceu por diagonal secund%cria!", 130, 163), ganhou = 1, pudim.jvelha.jogador1++;
            if (jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X') printf("\nParab%cns! O jogador 2 venceu por diagonal secund%cria!", 130, 163), ganhou = 1, pudim.jvelha.jogador2++;

        } while (ganhou == 0 && jogadas < 9);

        printf("\n"); //imprime o jogo final
        for (l = 0; l < 3; l++)
        {
            for (c = 0; c < 3; c++)
            {
                if (c == 0) printf("\t");
                printf(" %c ", jogo[l][c]);
                if (c < 2) printf("|");
                if (c == 2) printf(" %d", l);
            }
            if (l < 2) printf("\n\t-----------");
            printf("\n");                
        }

        if (ganhou == 0) puts("\n Deu velha!"), pudim.jvelha.velha++; //alimenta as estatísticas

        do //enquanto a opção for inválida
        {
            puts("\nDigite 1 para jogar novamente. Digite 8 para voltar ao menu.");
            scanf("%d", &opcao);
        } while (opcao != 1 && opcao != 8);
    } while (opcao == 1);
}

//------------------------------------------------------------------------------------------------------------------------------//
// JOGO DA FORCA

struct Forca
{
    char palavra[11];
};

void jogoforca(){

    FILE *bibliotecaPalavras;
    FILE *chuchu;
    int i, j, opcao, ki;
    struct Forca palavras[50];
    char palavraAdivinhada[11], jogosalvo[20];  
    char letra, a[3];
    int tentativas = 5;
    int palavraCompleta = 0;

    bibliotecaPalavras = fopen("caramelo.txt", "r"); //recebe do arquivo 50 opções de palavras para o jogo
    for (i = 0; i < 51; i++)
    {
        fgets(palavras[i].palavra, 11, bibliotecaPalavras);
    }
    fclose(bibliotecaPalavras);

    chuchu = fopen("chuchu.txt", "r"); //recebe os dados do arquivo de jogos salvos
    fgets(jogosalvo, 20, chuchu); //lê a primeira linha do arquivo, onde contém se há jogo salvo e o tamanho da palavra do jogo salvo, se houver

    if (jogosalvo[0] == '1') //se houver jogo salvo pergunta se quer carregá-lo
    {
        do
        {
            printf("\nDeseja carregar jogo salvo? (1)Sim (0)N%co.", 198);
            scanf("%d", &j);
        } while (j > 1 || j < 0);    
    }
    
    do //enquanto o jogador escolher continuar jogando, opção do jogador for igual a 1
    {
        system("cls");
        cabecalho(3);

        if (j == 1) //se o usuário quiser carregar o jogo salvo serão atribuídas a palavra, seu tamanho e o número de tentativas feitas no jogo salvo
        {
            a[0] = jogosalvo[1];
            ki = atoi(a); //tamanho da palavra salva

            fgets(jogosalvo, 20, chuchu);
            strcpy(a, jogosalvo);
            j = atoi(a); //número da posição da palavra dentro do arquivo


            fgets(jogosalvo, 20, chuchu);
            a[0] = jogosalvo[0];
            tentativas = atoi(a); //número de tentativas já feitas

            fgets(jogosalvo, 20, chuchu); //recebe as letras já descobertas e suas posições
            for (i = 0; jogosalvo[i] != '\0'; i++)
            {
                palavraAdivinhada[i] = jogosalvo[i];
            }
            fclose(chuchu);

            chuchu = fopen("chuchu.txt", "w"); //limpa os dados do arquivo e escreve o 0 (sem jogo salvo)
            fprintf(chuchu, "0");
            fclose(chuchu);
        }
        else{ //se o usuário não quiser carregar o jogo salvo ou se não tiver jogo salvo, inicia um novo jogo
            srand((unsigned)time(NULL));
            j = rand()% 50; //sorteando um número para selecionar a palavra do arquivo
        

            ki = strlen(palavras[j].palavra) - 1; //tamanho da palavra - o \n

            for (int i = 0; i < ki; i++) { //atribui à todas as posições da palavra o * para a palavra ficar invisível
                palavraAdivinhada[i] = '*';
            }
            palavraAdivinhada[ki] = '\0'; //indica o fim da palavra
        }

        while (tentativas > 0 && !palavraCompleta) { //repete enquanto ainda houver tentativas ou até o usuário acertar a palavra
            system("cls");
            cabecalho(3);
            puts("\nInsira 8 para voltar ao menu.");

            printf("\nA palavra tem %d letras. Tente adivinhar!\n", ki);
            printf("\nPalavra: %s\n", palavraAdivinhada);
            printf("Tentativas restantes: %d\n", tentativas);
            printf("Digite uma letra: ");
            scanf(" %c", &letra); //recebe uma letra do jogador

            if (letra == '8'){ //se o jogador desejar sair pergunta se quer salvar o jogo
                do //enquanto a opção for inválida
                {
                    printf("Deseja salvar o jogo? (1)Sim (0)N%co", 198);
                    scanf("%d", &opcao);
                } while (opcao > 1 || opcao < 1);
                
                if (opcao == 1) //salva o jogo
                {
                    chuchu = fopen("chuchu.txt", "w");
                    fprintf(chuchu, "1%d\n%d\n%d\n%s\n", ki, j, tentativas, palavraAdivinhada);
                    fclose(chuchu);
                }

                return;
            }

            int letraEncontrada = 0;

            for (int i = 0; i < ki; i++){ //verifica todas as letras se a letra inserida faz parte da palavra, se fizer o * é substituido pela letra
                if (palavras[j].palavra[i] == letra) {
                    palavraAdivinhada[i] = letra;
                    letraEncontrada = 1;
                }
            }

            if (letraEncontrada) {
                printf("\nParab%cns! A letra est%c correta.\n", 130, 160);
            } else {
                printf("\nOps! A letra n%co faz parte da palavra.\n", 198);
                tentativas--; //se não fizer parte da palavra o número de tentativas diminui
            }

            //compara a palavra advinhada até o momento e a palavra final
            if (strncmp(palavras[j].palavra, palavraAdivinhada, ki) == 0) palavraCompleta = 1; 
        }

        if (palavraCompleta) { //alimenta as estatísticas
            printf("\nParab%cns! Voc%c acertou a palavra: %s\n", 130, 136, palavras[j].palavra);
            pudim.jforca.vitorias++;
        } else {
            printf("\nVoc%c perdeu! A palavra correta era: %s\n", 136, palavras[j].palavra);
            pudim.jforca.derrotas++;
        }

        do //enquanto a opção for inválida
        {
            puts("\nDigite 1 para jogar novamente. Digite 8 para voltar ao menu.");
            scanf("%d", &opcao); //pergunta ao jogador se deseja jogar novamente
        } while (opcao != 1 && opcao != 8);

        if (opcao == 8) return; //se não, ele retorna ao menu
        else{ //se sim, ele atribui os valores iniciais às variáveis para recomeçar o jogo
            palavraCompleta = 0;
            tentativas = 5;
        }    
        
    } while (opcao == 1);
}

//------------------------------------------------------------------------------------------------------------------------------//
//JOGO JOKEMPÔ

void jokenpo(){
    int jogador, computador, opcao;

    do //enquanto o jogador escolher continuar jogando, opção do jogador for igual a 1
    {
        system("cls");
        cabecalho(4);
        puts("\nInsira 8 para voltar ao menu.");

        do //pede opções até o jogador inserir uma opção válida
        {
            puts("\n\n1 - PEDRA.");
            puts("2 - PAPEL.");
            puts("3 - TESOURA.\n");
            printf("Digite a op%c%co desejada:", 135, 198);
            scanf("%d", &jogador);

            if (jogador == 8) return; //se o usuário quiser sair, retorna ao menu

        } while (jogador < 1 || jogador > 3);
        
        srand(time(NULL)); //sorteia uma opção para o computador
        computador = rand()%3 + 1;

        system("cls");
        cabecalho(4);

        switch (jogador) //imprime as opções do jogador e do computador
        {
            case 1:
                puts("\nJogador escolheu PEDRA.\n");
            break;
            case 2:
                puts("\nJogador escolheu PAPEL.\n");
            break;
            case 3:
                puts("\nJogador escolheu TESOURA.\n");
            break;
        }
        switch (computador)
        {
            case 1:
                puts("Computador escolheu PEDRA.\n");
            break;
            case 2:
                puts("Computador escolheu PAPEL.\n");
            break;
            case 3:
                puts("Computador escolheu TESOURA.\n");
            break;
        }

        //verifica quem venceu ou se houve um empate, imprime e alimenta as estatísticas
        if (jogador == computador) printf("Empate!"), pudim.jjokenpo.empate++;
        else if(jogador == 1 && computador == 3){
            printf(" ___ \t  \t%c  /\n(   )\tvs\t %c/\n(___)\t  \t /%c\n     \t  \tO  Q\n\n", 92, 92, 92);
            printf("Jogador venceu!");
            pudim.jjokenpo.jogador++;
        }
        else if(jogador == 2 && computador == 1){
            printf(" ___ \t  \t ___\n|   |\tvs\t(   )\n|   |\t  \t(___)\n|___|\t  \t     \n\n");
            printf("Jogador venceu!");
            pudim.jjokenpo.jogador++;
        }
        else if(jogador == 3 && computador == 2){
            printf("%c  /\t  \t ___ \n %c/ \tvs\t|   |\n /%c \t  \t|   |\nO  Q\t  \t|___|\n\n", 92, 92, 92);
            printf("Jogador venceu!");
            pudim.jjokenpo.jogador++;
        }
        else if(jogador == 1 && computador == 2){
            printf(" ___ \t  \t ___ \n(   )\tvs\t|   |\n(___)\t  \t|   |\n     \t  \t|___|\n\n");
            printf("Computador venceu!");
            pudim.jjokenpo.computador++;
        }
        else if(jogador == 2 && computador == 3){
            printf(" ___ \t  \t%c  /\n|   |\tvs\t %c/\n|   |\t  \t /%c\n|___|\t  \tO  Q\n\n", 92, 92, 92);
            printf("Computador venceu!");
            pudim.jjokenpo.computador++;
        }
        else if(jogador == 3 && computador == 1){
            printf("%c  /\t  \t ___ \n %c/ \tvs\t(   )\n /%c \t  \t(___)\nO  Q\t  \t     \n\n", 92, 92, 92);
            printf("Computador venceu!");
            pudim.jjokenpo.computador++;
        }

        do //enquanto a opção for inválida
        {
            puts("\nDigite 1 para jogar novamente. Digite 8 para voltar ao menu.");
            scanf("%d", &opcao);
        } while (opcao != 1 && opcao != 8);
    } while (opcao == 1);
}

//------------------------------------------------------------------------------------------------------------------------------//
//JOGO DA MEMÓRIA (FUI AO MERCADO...)

struct Palavras
{
    char palavra[11];
};

FILE *farofa;
int i, j, k, l, m, ki, op1, erro;
struct Palavras computador[25], jogador[25], verificar[50];

void jogofuiaomercado(){
    struct Palavras jogoFM[50];

    for (i = 0; i < 50; i++) //atribui nada ao vetor das palavras do jogo
    {
        jogoFM[i].palavra[0] = '\0';
    }

    k = 0;
    l = 0;
    ki = 0;
    erro = 0;

    do //vai repetir até o jogador errar a palavra
    {
        system("cls");
        cabecalho(5);

        if (k == 0 || k %2 == 0) //para números pares, o computador vai sortear uma nova para acrescentar ao final
        {
            do //sorteia um número para o vetor das palavras do arquivo
            {
                srand((unsigned)time(NULL));
                j = rand()%25;
                ki = strlen(computador[j].palavra) - 1;

                for (i = 0; i < 25; i++) //compara as palavras para ver se já não foram utilizadas
                {
                    if(strncmp(computador[j].palavra, jogoFM[i].palavra, ki) == 0){
                        break;
                    }
                }
                
            } while (strncmp(computador[j].palavra, jogoFM[i].palavra, ki) == 0);
        }

        if (k == 0 || k %2 == 0) //para números pares, o computador vai imprimir as palavras do jogo e adicionar a nova palavra sorteada
        {
            strncpy(jogoFM[k].palavra, computador[j].palavra, ki); //copia a nova palavra para o vetor das palavras do jogo
            k++;

            printf("\nFui ao mercado e comprei:\n"); //imprime as palavras
            for (i = 0; i < k; i++)
            {
                if (k == 1) printf("%s.\n", jogoFM[i].palavra);
                else if (i == k - 1) printf(" e %s.\n", jogoFM[i].palavra);            
                else if (i == 0) printf("%s", jogoFM[i].palavra);
                else printf(", %s", jogoFM[i].palavra);
            }
            system("pause");
        }
        else if(k % 2 == 1) { //nos ímpares o usuário vai inserir palavra por palavra, se corretas, ao final, adicionará uma palavra

            printf("\nFui ao mercado e comprei:\n");
            for (i = 0; i <= k; i++) //comparar as palavras que o usuário inserir com as já lançadas no vetor jogoFM
            {
                if (i != k) //enquanto a palavra não for a última
                {   
                    fflush(stdin);
                    scanf("%s", verificar[i].palavra); //recebe a palavra
                    ki = strlen(verificar[i].palavra);

                    if (atoi(verificar[i].palavra) == 8) return; //se o usuário quiser sair, retorna ao menu
                    
                    //compara a palavra inserida com a no vetor de palavras do jogo e imprimir se a palavra estiver errada.
                    if (strncmp(verificar[i].palavra, jogoFM[i].palavra, ki) != 0) 
                    {
                        printf("\nOps! Palavra errada. A palavra a seguir era: %s.\n", jogoFM[i].palavra);
                        erro = 1;
                        pudim.memoria = k - 1; //alimenta as estatísticas
                        return; //finaliza o jogo
                    }
                }else if (i == k) //depois de o jogador acertar todas as palavras, pede uma nova palavra e adiciona ao vetor do jogo
                {
                    printf("e...?.");
                    fflush(stdin);
                    scanf("%s", jogador[l].palavra); //recebe nova palavra
                    ki = strlen(jogador[l].palavra);

                    if (atoi(jogador[l].palavra) == 8) return; //se o usuário quiser sair, retorna ao menu

                    for (m = 0; m < k; m++) //verifica se a palavra já foi utilizada no jogo
                    {
                        while (strncmp(jogador[l].palavra, jogoFM[m].palavra, ki) == 0) //compara a palavra inserida com as do vetor do jogo
                        {
                            printf("\nEssa palavra j%c foi utilizada. Insira outra:\n", 163);
                            gets(jogador[l].palavra); //pede uma palavra até que seja uma não utilizada ainda
                        }
                    }

                    strncpy(jogoFM[k].palavra, jogador[l].palavra, ki); //adiciona uma nova palavra ao vetor do jogo
                    l++; //aumenta a posição do vetor das palavras inseridas pelo jogador
                }
            }                 
            k++; //aumenta a posição do vetor das palavras inseridas no vetor do jogo
        }
    } while(erro == 0);
}

//------------------------------------------------------------------------------------------------------------------------------//
// JOGO CAMPO MINADO

struct Celula
{
    int bomba;
    int estaAberta;
    int vizinhos;
};

FILE *campoMinado;
struct Celula jogo[10][10];
int l, c, tam = 10, p;

void iniciarJogo(){ //atribui a todas as posições do vetor nada (vazio)
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

void sortearBombas(int n){ //recebe como parâmetro o número de bombas desejadas, no caso 10
    int i;

    srand(time(NULL)); 
    for (i = 1; i <= n; i++) //sorteia a posição das 10 bombas
    {
        l = rand()% tam; //sorteia a linha em que a bomba estará
        c = rand()% tam; //sorteia a coluna em que a bomba estará
        if (jogo[l][c].bomba == 0) jogo[l][c].bomba = 1; //atribui uma bomba se a posição sorteada já não tiver
        else i--; //se tiver, diminui um na contagem de bombas colocadas no "tabuleiro" 
    }
}

int coordenada(int l, int c){ //verifica se a coordena existe
    if (l >= 0 && l < tam && c >= 0 && c < tam) return 1;
    else return 0;
}

int bombasvizinhas(int l, int c){ //conta a quantidade de bombas na região
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

void contarBombas(){ //atribui o número de bombas na região em cada posição do "tabuleiro"
    for (l = 0; l < tam; l++)
    {
        for (c = 0; c < tam; c++)
        {
            jogo[l][c].vizinhos = bombasvizinhas(l, c);
        }
    }
}

void imprimir(){ //imprime o "tabuleiro" do jogo
    printf("\n\n    ");
    for (l = 0; l < tam; l++)
    {
        printf(" %d  ", l);
    }
    printf("\n   ----------------------------------------- \n");    
    for (l = 0; l < tam; l++)
    {
        printf("%d  |", l);
        for (c = 0; c < tam; c++)
        {
            if(jogo[l][c].estaAberta){ //se o jogador já tiver aberto a célula imprime * para bomba ou o número de bombas da região
                if (jogo[l][c].bomba) printf(" * ");
                else printf(" %d ", jogo[l][c].vizinhos);
            } else printf("   "); //imprime a célula vazia
            printf("|");
        }
        printf("\n   -----------------------------------------  \n");    
    }
}

void abrircelula(int l, int c){ //abrir a célula das coordenadas inseridas
    if(coordenada(l, c) == 1 && jogo[l][c].estaAberta == 0){ //verifica se são coordenadas válidas e se já não estão abertas
        jogo[l][c].estaAberta = 1; //abre a célula
        if (jogo[l][c].vizinhos == 0) //verifica se as células vizinhas não tem bombas e se as viznhas das vizinhas não tem bombas
        {
            abrircelula(l - 1, c);
            abrircelula(l + 1, c);
            abrircelula(l, c - 1);
            abrircelula(l, c + 1);
        }
    }
}

int ganhar(){ //verifica se todas as células já foram abertas e nenhuma foi uma bomba
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

void salvarjogo(){ //salva o jogo
    fopen("queijo.txt", "w"); 
    fprintf(campoMinado, "1"); //primeiro o digito 1 que indica que há um jogo salvo

    //em seguida as informações de todas as posições do tabuleiro
    for (l = 0; l < 10; l++)
    {
        for (c = 0; c < 10; c++)
        {
            fprintf(campoMinado, "%d", jogo[l][c].bomba);
        }
    }
    for (l = 0; l < 10; l++)
    {
        for (c = 0; c < 10; c++)
        {
            fprintf(campoMinado, "%d", jogo[l][c].estaAberta);
        }
    }
    for (l = 0; l < 10; l++)
    {
        for (c = 0; c < 10; c++)
        {
            fprintf(campoMinado, "%d", jogo[l][c].vizinhos);
        }
    }
    fclose(campoMinado);
}

void jogar(){
    int linha, coluna, op;

    do{ //enquanto não forem descobertas todas as células e o jogador não inserir as coordenadas de nenhuma bomba
        system("cls");
        cabecalho(6);
        printf("\nPara voltar ao menu insira um -1.\n");

        imprimir();
        do{ //pede coordenadas até que sejam válidas
            printf("Insira os valores de linha e coluna:");
            scanf("%d", &linha);
            scanf("%d", &coluna);

            if (linha == -1 || coluna == -1) //se o usuário quiser sair, retorna ao menu
            {
                p = 1; //diz que o jogador quer ir ao menu, não apenas sair da função
                do
                {
                    printf("Deseja salvar o jogo? (1)Sim (0)N%co", 198); //pergunta ao usuário que deseja salvar jogo
                    scanf("%d", &op);
                } while (op > 1 || i < 0);

                if (op == 1) salvarjogo(); //se sim, salva o jogo
                else { //se não, cria arquivo com digito 0 que indica que não há um jogo salvo
                    campoMinado = fopen("queijo.txt", "w");
                    fprintf(campoMinado, "0");
                    fclose(campoMinado);
                }
                return;
            }
            
            if (coordenada(linha, coluna) == 0) printf("Coordenada inv%clida.\n", 160); //verifica coordenada e imprime se for inválida
        } while(coordenada(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1);
        abrircelula(linha, coluna); //com as coordenadas válidas, chama a função que abre as células
    } while(ganhar() != 0 && jogo[linha][coluna].bomba == 0);

    system("cls");
    cabecalho(6);

    //imprime o resultado do jogo e o "tabuleiro", e alimenta as estatísticas
    if(jogo[linha][coluna].bomba == 1) printf("\n\t\t Tururu... Voc%c perdeu!", 136), pudim.jcampominado.derrotas++;
    else printf("\n\tWeee are the champions, my frieend!!!\n\tParab%cns. Voc%c ganhou!", 130, 136), pudim.jcampominado.vitorias++;
    imprimir();
}

void jogocampominado(){
    int op, ver, i = 1;
    char converter[302];
    int bomba[101], aberta[101], vizinha[101];

    campoMinado = fopen("queijo.txt", "r"); //abre o arquivo e recebe os dados
    fgets(converter, 302, campoMinado);
    fclose(campoMinado);

    if(converter[0] == '1'){ //o digito referente ao jogo salvo é o primeiro, se houver (1) ele pergunta ao jogador e deseja carregar jogo salvo
        do //enquanto a opção for inválida
        {
            printf("\nDeseja carregar jogo salvo? (1)Sim (0)N%co.", 198);
            scanf("%d", &ver);
        } while (ver > 1 || ver < 0);  
    }

    do //enquanto o jogador escolher continuar jogando, opção do jogador for igual a 1
    {
        if (ver == 1) //se o jogador quise carregar o jogo salvo
        {
            campoMinado = fopen("queijo.txt", "w"); //limpa os dados do arquivo e escreve o 0 (sem jogo salvo)
            fprintf(campoMinado, "0");
            fclose(campoMinado);
            for (j = 0; j < 100; j++, i++) //distribui os dados em diferentes vetores
            {
                if (converter[i] == '0')
                {
                    bomba[j] = 0;
                }else if (converter[i] == '1')
                {
                    bomba[j] = 1;
                } 
            }
            for (j = 0; j < 100; j++, i++)
            {
                if (converter[i] == '0')
                {
                    aberta[j] = 0;
                }else if (converter[i] == '1')
                {
                    aberta[j] = 1;
                } 
            }
            for (j = 0; j < 100; j++, i++)
            {
                if (converter[i] == '0')
                {
                    vizinha[j] = 0;
                } else if (converter[i] == '1')
                {
                    vizinha[j] = 1;
                }else if (converter[i] == '2')
                {
                    vizinha[j] = 2;
                }else if (converter[i] == '3')
                {
                    vizinha[j] = 3;
                }else if (converter[i] == '4')
                {
                    vizinha[j] = 4;
                }else if (converter[i] == '5')
                {
                    vizinha[j] = 5;
                }else if (converter[i] == '6')
                {
                    vizinha[j] = 6;
                }else if (converter[i] == '7')
                {
                    vizinha[j] = 7;
                }else if (converter[i] == '8')
                {
                    vizinha[j] = 8;
                }
            }

            //atribui os dados dos vetores à matriz do jogo
            i = 0;
            for (l = 0; l < 10; l++) 
            {
                for (c = 0; c < 10; c++, i++)
                {
                    jogo[l][c].bomba = bomba[i];
                }
            }
            i = 0;
            for (l = 0; l < 10; l++)
            {
                for (c = 0; c < 10; c++, i++)
                {
                    jogo[l][c].estaAberta = aberta[i];
                }
            }
            i = 0;
            for (l = 0; l < 10; l++)
            {
                for (c = 0; c < 10; c++, i++)
                {
                    jogo[l][c].vizinhos = vizinha[i];
                }
            }
        } else if(ver != 1) //se o jogador não quiser carregar o jogo salvo
        {
            iniciarJogo(); //inicia o tabuleiro
            sortearBombas(10); //sorteia a posição das bombas
            contarBombas(); //conta as bombas da região
        }
        jogar(); //inicia o jogo

        if (p == 1) return; //se o usuário quiser sair, retorna ao menu
        
        do //enquanto a opção for inválida
        {
            puts("\nDigite 1 para jogar novamente. Digite 8 para voltar ao menu."); //pergunta se o jogador deseja jogar novamente
            scanf("%d", &op);
        } while (op != 1 && op != 8);
    } while (op == 1);
}

//------------------------------------------------------------------------------------------------------------------------------//
// JOGO DA COBRINHA (SNAKE)

int altura = 20, largura = 40;
int gameover, score;
int x, y, frutinhax, frutinhay, tecla;

void setup()
{ //sorteia a posição da frutinha
    gameover = 0;
    srand(time(NULL));

    x = altura / 2;
    y = largura / 2;
    label1:
        frutinhax = 2 + rand() % 16;
        if (frutinhax == 0)
            goto label1;
    label2:
        frutinhay = 4 + rand() % 34;
        if (frutinhay == 0)
            goto label2;
    score = 0;
}
  
void quadro() //imprime o quadro, a posição da frutinha e a posição da suposta cobrinha (0)
{
    system("cls");
    cabecalho(7);
    printf("\n\n");
    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            if (i == 0 || i == 19 || j == 0 || j == 39) {
                printf("#");
            }
            else {
                if (i == x && j == y)
                    printf("0");
                else if (i == frutinhax && j == frutinhay)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
  
    printf("score = %d", score);
    puts("\nDigite 8 para voltar ao menu.");
}
  
void input() //interpreta as teclas do teclado e seleciona uma opção a partir delas
{
    if (kbhit()) {
        switch (getch()) {
        case 'a':
            tecla = 1;
            break;
        case 's':
            tecla = 2;
            break;
        case 'd':
            tecla = 3;
            break;
        case 'w':
            tecla = 4;
            break;
        case '8': //se o usuário quiser sair, retorna ao menu
            gameover = 1;
            break;
        }
    }
}
  
void logic()
{
    sleep(0.15); //tempo ou delay no movimento
    switch (tecla) { //a opção slecionada muda a posição da suposta cobrinha (0)
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }
  
    if (x < 0 || x > altura || y < 0 || y > largura) gameover = 1; //se a suposta cobrinha (0) bater nas paredes acaba o jogo

    srand(time(NULL)); //sorteia a posição das frutinhas conforme elas viram papa

    if (x == frutinhax && y == frutinhay){ //se a cobrinha estiver na posição da frutinha será sorteada nova posição
    label3:
        frutinhax = 2 + rand() % 16;
        if (frutinhax == 0)
            goto label3;
  
    label4:
        frutinhay = 4 + rand() % 34;
        if (frutinhay == 0)
            goto label4;
        score = score + 10; //a cada frutinha que vira papa adiciona 10 ao score;
    }
}

void jogosnake(){
    int op;

    do //enquanto o jogador escolher continuar jogando, opção do jogador for igual a 1
    {
        setup(); //inicia o jogo
        while (!gameover) { //enquanto o jogador não bater nas paredes 
            quadro();
            input();
            logic();
        }

        if (score > pudim.snake) pudim.snake = score; //alimenta as estatísticas
        
        do //enquanto a opção for inválida
        {
            puts("\nDigite 1 para jogar novamente."); //pergunta se o jogador deseja jogar novamente
            scanf("%d", &op);
            if (op == 8) return;
        } while (op != 1 && op != 8);
    } while (op == 1);
}

//------------------------------------------------------------------------------------------------------------------------------//
// ESTATÍSTICAS

FILE *estatistica;

void impimirEstatisticas(int op){ //imprime as estatísticas de acordo com a opção do parâmetro recebido
    switch (op) 
    {
    case 1://jogo velha
        printf("\n\tJogo da Velha\nVit%crias Jogador 1: %d.\nVit%crias Jogador 2: %d.\nVelha: %d.\n", 162, pudim.jvelha.jogador1, 162, pudim.jvelha.jogador2, pudim.jvelha.velha);
    break;
    case 2://jogo forca
        printf("\n\tJogo da Forca\nVit%crias: %d.\nDerrotas: %d.\n", 162, pudim.jforca.vitorias, pudim.jforca.derrotas);
    break;
    case 3: //jogo jokempo
        printf("\n\tJogo Jokenp%c\nVit%crias: %d.\nDerrotas: %d.\nEmpates: %d.\n",147, 162, pudim.jjokenpo.jogador, pudim.jjokenpo.computador, pudim.jjokenpo.empate);
    break;
    case 4: //jogo memoria
        printf("\n\tJogo Fui ao Mercado...\nMaior n%cmero de paravras lembradas: %d.\n", 163, pudim.memoria);
    break;
    case 5://jogo mapominado
        printf("\n\tJogo Campo Minado\nVit%crias: %d.\nDerrotas: %d.\n", 162, pudim.jcampominado.vitorias, pudim.jcampominado.derrotas);
    break;
    case 6: //jogo da cobrinha
        printf("\n\tJogo da Cobrinha (snake)\nMaior n%cmero score: %d.\n", 163, pudim.snake);
    break;
    case 7: //todos os jogos
        for (i = 1; i < 7; i++)
        {
            impimirEstatisticas(i);
        }
    break;
    }
    if (op == 8) return;
}

void receberEstatisticas(){ //recebe as estatísticas do arquivo
    estatistica = fopen("pudim.txt", "r");
    char linha[60];
    while (fgets(linha, 60, estatistica) != NULL) { //separa os valores por ',' e os atribui às estatísticas pudim
        char* token = strtok(linha, ",");
        
        if (token == NULL)continue;
        pudim.jvelha.jogador1 = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL)continue;
        pudim.jvelha.jogador2 = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL)continue;
        pudim.jvelha.velha = atoi(token);
		token = strtok(NULL, ",");
        if (token == NULL)continue;
        pudim.jforca.vitorias = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL)continue;
        pudim.jforca.derrotas = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL)continue;
        pudim.jjokenpo.jogador = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL)continue;
        pudim.jjokenpo.computador = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL)continue;
        pudim.jjokenpo.empate = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL)continue;
        pudim.memoria = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL)continue;
        pudim.jcampominado.vitorias = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL)continue;
        pudim.jcampominado.derrotas = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL)continue;
        pudim.snake = atoi(token);
    }
    fclose(estatistica);
}

void salvarEstatisticas(){ //Cria um novo arquivo com as novas estatísticas
    estatistica = fopen("pudim.txt", "w");
    fprintf(estatistica, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", pudim.jvelha.jogador1, pudim.jvelha.jogador2, pudim.jvelha.velha, pudim.jforca.vitorias, pudim.jforca.derrotas, pudim.jjokenpo.jogador, pudim.jjokenpo.computador, pudim.jjokenpo.empate, pudim.memoria, pudim.jcampominado.vitorias, pudim.jcampominado.derrotas, pudim.snake);
    fclose(estatistica);
}

int menuEstatistica(){ //imprime na tela as opções das estatísticas e retorna a opção selecionada para a função de imprimir estatísticas

    int i;

    puts("\n\n\t(1) Jogo da velha.");
    puts("\t(2) Jogo da forca.");
    printf("\t(3) JoKenP%c.\n", 147);
    puts("\t(4) Jogo \"fui ao mercado e comprei ...\".");
    puts("\t(5) Jogo campo minado.");
    puts("\t(6) Jogo da cobrinha (snake).");
    puts("\t(7) Todos os jogos.");
    puts("\t(8) Sair para o menu.");

    scanf("%d", &i);

    system("cls");
    cabecalho(8);

    return i;
}

//------------------------------------------------------------------------------------------------------------------------------//
// FUNÇÃO PRINCIPAL

int main(){
    receberEstatisticas(); //primeira coisa a fazer no sistema é receber as estatísticas
    int op, e;
    while(1) //enquanto o usuário não escolher sair do programa
    {
        op = menu(); //chama a função menu e recebe a opção como retorno

        switch (op) //de acordo com a opção selecionada navega pelo sistema
        {
        case 1: //jogo da Velha
            jogovelha();
        break;
        case 2: //jogo da Forca
            jogoforca();
        break;
        case 3: //jogo Jokempô
            jokenpo();
        break;
        case 4: //jogo da memória Fui ao mercado...
            farofa = fopen("farofa.txt", "r"); //abre o arquivo com as palavras do computador
            for (i = 0; i < 25; i++)//atribui as palavras ao vetor
            {
                fgets(computador[i].palavra, 11, farofa);
            }
            fclose(farofa);

            do //enquanto o jogador escolher continuar jogando, opção do jogador for igual a 1
            {
                jogofuiaomercado(); //chama a função que realiza o jogo
            
                do //enquanto a opção for inválida
                {
                    puts("\nDigite 1 para jogar novamente. Digite 8 para voltar ao menu."); //pergunta se o jogador deseja jogar novamente
                    scanf("%d", &op1);
                } while (op1 != 1 && op1 != 8);

                if (op1 == 8) break; //se o usuário quiser sair, retorna ao menu
            } while (op1 == 1);
        break;
        case 5: //jogo Campo Minado
            jogocampominado();
        break;
        case 6: //jogo da cobrinha
            jogosnake();
        break;
        case 7: //estatísticas
            system("cls");
            cabecalho(8);
            impimirEstatisticas(e = menuEstatistica()); //chama a função menu para retornar um valor para função imprimir 
            if (e != 8) system("pause");
        break;
        case 8://salvar as novas estatísticas quando for finalizar o programa
            salvarEstatisticas();
            system("cls");
            printf("Encerrando programa.");
            return 0;
        break;
        default: //imprime que a opção não existe
            printf("Op%c%co inexistente.", 135, 198);
            system("pause");
        break;
        }
    }
}