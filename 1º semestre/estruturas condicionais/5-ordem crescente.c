#include <stdio.h>

int main()
{
   int num1, num2, num3;
   
   printf("Digite tr%cs n%cmeros:", 136, 163);
   scanf("%d", &num1);
   scanf("%d", &num2);
   scanf("%d", &num3);

   if (num1>=num2 && num2>=num3)
   {
       printf("A ordem crescente dos n%cmeros %c: %d, %d e %d", 163, 130, num3, num2, num1);
   }
   else if (num1>=num3 && num3>=num2)
   {
       printf("A ordem crescente dos n%cmeros %c: %d, %d e %d", 163, 130, num2, num3, num1);
   }
   else if (num2>=num1 && num1>=num3)
   {
       printf("A ordem crescente dos n%cmeros %c: %d, %d e %d", 163, 130, num3, num1, num2);
   }
   else if (num2>=num3 && num3>=num1)
   {
       printf("A ordem crescente dos n%cmeros %c: %d, %d e %d", 163, 130, num1, num3, num2);
   }
   else if (num3>=num1 && num1>=num2)
   {
       printf("A ordem crescente dos n%cmeros %c: %d, %d e %d", 163, 130, num2, num1, num3);
   }
   else if (num3>=num2 && num2>=num1)
   {
       printf("A ordem crescente dos n%cmeros %c: %d, %d e %d", 163, 130, num1, num2, num1);
   }

   return 0;
   
}
