#include <stdio.h>
int main()
{
   int num1, num2;
   
   printf("Escreva dois n%cmeros:", 163);
   scanf("%d", &num1);
   scanf("%d", &num2);
   
   if (num1>num2){
       printf("O maior n%cmero %c %d",163, 130, num1);
   }
   else if(num2>num1){
        printf("O maior n%cmero %c %d", 163, 130, num2);
   }
   else{
        printf("Os n%cmeros s%co iguais", 163, 198);
   }
    
   return 0;
   
}