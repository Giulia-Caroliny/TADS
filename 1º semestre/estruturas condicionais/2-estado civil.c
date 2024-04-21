#include <stdio.h>
int main()
{
   char estado;
   
   printf("Escreva a primeira letra do seu estado civil: \"c\" para casado, \"s\" para solteiro, \"v\" para vi%cvo, \"d\" para divorciado e \"q\" para desquitado.", 163);
   scanf("%c", &estado);
   
   switch (estado)
   {
       case 'c': printf("%c casado", 144);
       break;
       case 's': printf("%c solteiro", 144);
       break;
       case 'v': printf("%c vi%cvo", 144, 163);
       break;
       case 'd': printf("%c divorciado", 144);
       break;
       case 'q': printf("%c desquitado", 144);
       break;
       default: printf("Letra inv%clida.", 160);
   }
    return 0;
   
}
