#include <stdio.h>
int main()
{
   int mes;
   
   printf("Escreva um n%cmero referente ao m%cs:", 163, 136);
   scanf("%d", &mes);
   
   switch (mes)
   {
       case 1: printf("O m%cs %c janeiro", 136, 130);
       break;
       case 2: printf("O m%cs %c fevereiro", 136, 130);
       break;
       case 3: printf("O m%cs %c mar%co", 136, 130, 135);
       break;
       case 4: printf("O m%cs %c abril", 136, 130);
       break;
       case 5: printf("O m%cs %c maio", 136, 130);
       break;
       case 6: printf("O m%cs %c junho", 136, 130);
       break;
       case 7: printf("O m%cs %c julho", 136, 130);
       break;
       case 8: printf("O m%cs %c agosto", 136, 130);
       break;
       case 9: printf("O m%cs %c setembro", 136, 130);
       break;
       case 10: printf("O m%cs %c outubro", 136, 130);
       break;
       case 11: printf("O m%cs %c novembro", 136, 130);
       break;
       case 12: printf("O m%cs %c dezembro", 136, 130);
       break;
       default: printf("N%cmero inv%clido", 163, 160);
   }
   return 0;
   
}
