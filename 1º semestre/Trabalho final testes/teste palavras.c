#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Palavras
{
    char palavra[11];
};

FILE *farofa;
int i, j, k = 0, l = 0, m, ki, op, erro = 0;
struct Palavras computador[25], jogador[25], jogoFM[50], verificar[50];


void jogando(){
    do //vai repetir até o jogador errar a palavra
    {
        system("cls");
        if (k == 0 || k %2 == 0)
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

        if (k == 0 || k %2 == 0) //para números pares, o computador vai printar as palavras e sortear uma nova para acrescentar ao final
        {
            strncpy(jogoFM[k].palavra, computador[j].palavra, ki);
            //jogoFM[k].palavra = computador[j].palavra;
            k++;
            printf("Fui ao mercado e comprei:\n");
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

            printf("Fui ao mercado e comprei:\n");

            for (i = 0; i <= k; i++) //comparar as palavras que o usuário inserir com as já lançadas no vetor jogoFM
            {
                if (i != k)
                {   
                    gets(verificar[i].palavra);
                    ki = strlen(verificar[i].palavra);

                    if (atoi(verificar[i].palavra) == 8) return;
                    
                    if (strncmp(verificar[i].palavra, jogoFM[i].palavra, ki) != 0) //imprimir se a palavra estiver errada.
                    {
                        printf("\nOps! Palavra errada. A palavra a seguir era: %s.\n", jogoFM[i].palavra);
                        erro = 1;
                        return;
                    }
                }else if (i == k)
                {
                    printf("e...?.");
                    gets(jogador[l].palavra);
                    ki = strlen(jogador[l].palavra);

                    if (atoi(jogador[l].palavra) == 8) return;


                    for (m = 0; m < k; m++)
                    {
                        while (strncmp(jogador[l].palavra, jogoFM[m].palavra, ki) == 0)
                        {
                            printf("\nEssa palavra j%c foi utilizada. Insira outra:\n", 163);
                            gets(jogador[l].palavra);
                        }
                    }

                    strncpy(jogoFM[k].palavra, jogador[l].palavra, ki);
                    printf("\n%s", jogoFM[k].palavra);
                    l++;
                }
            }                 
            k++;
        }
    } while(erro == 0);
}

int main(){
    farofa = fopen("farofa.txt", "r"); //abre o arquivo com as palavras do computador

    for (i = 0; i < 25; i++)//atribui as palavras ao vetor
    {
        fgets(computador[i].palavra, 11, farofa);
    }
    
    fclose(farofa);

    do
    {
        for (i = 0; i < 50; i++)
        {
            jogoFM[i].palavra[0] = '\0';
        }

        
        jogando();
    
        puts("\nDigite 1 para jogar novamente. Digite 9 para voltar ao menu.");
        scanf("%d", &op);    

        if (op == 9) return 0;
    
    } while (op == 1);

    return 0;
}
