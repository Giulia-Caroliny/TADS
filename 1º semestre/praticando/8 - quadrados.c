#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float i;
    i = 15;

    do
    {
        printf("\nO quadrado de %f %c: %.0f \n", i, 130, pow(i, 2));
        i++;
    } while (i < 201);
        
    return 0;
}