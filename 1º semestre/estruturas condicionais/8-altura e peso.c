#include <stdio.h>

int main ()
{

float altura, peso;

printf("Insira sua altura e seu peso:");
scanf("%f", &altura);
scanf("%f", &peso);

if (altura>0 && altura<1.20)
{
    if (peso>0 && peso<60){
        printf("Sua classifica%c%co %c: A", 135, 198, 130);
    }
    else if (peso>=60 && peso<=90){
        printf("Sua classifica%c%co %c: D",135, 198, 130);
    }
    else if (peso>90){
        printf("Sua classifica%c%co %c: G", 135, 198, 130);
    }  
}

else if (altura>=1.20 && altura<=1.70)
{
    if (peso>0 && peso<60){
        printf("Sua classifica%c%co %c: B", 135, 198, 130);
    }
    else if (peso>=60 && peso<=90){
        printf("Sua classifica%c%co %c: E",135, 198, 130);
    }
    else if (peso>90){
        printf("Sua classifica%c%co %c: H", 135, 198, 130);
    }  
}

else if (altura>1.70)
{
    if (peso>0 && peso<60){
        printf("Sua classifica%c%co %c: C", 135, 198, 130);
    }
    else if (peso>=60 && peso<=90){
        printf("Sua classifica%c%co %c: F",135, 198, 130);
    }
    else if (peso>90){
        printf("Sua classifica%c%co %c: I", 135, 198, 130);
    }  
}

return 0;

}