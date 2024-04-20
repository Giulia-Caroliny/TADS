#include <stdio.h>

int main()
{
   int dia;
   
   printf("Escreva um n%cmero de 1 a 7:", 163);
   scanf("%d", &dia);
   
   switch(dia)
   {
       case 1: printf("O dia da semana %c domingo", 130);
       break;
       case 2: printf("O dia da semana %c segunda", 130);
       break;
       case 3: printf("O dia da semana %c ter%ca", 130, 135);
       break;
       case 4: printf("O dia da semana %c quarta", 130);
       break;
       case 5: printf("O dia da semana %c quinta", 130);
       break;
       case 6: printf("O dia da semana %c sexta", 130);
       break;
       case 7: printf("O dia da semana %c s%cbado", 130, 160);
       break;
       default: printf("N%cmero inv%clido", 163, 160);
   }
   return 0; 
   
}
