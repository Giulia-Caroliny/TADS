#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main() {
    float a, b, c, p, A;
    bool v;
    
    do{
        printf("Insira os lados do tri%cngulo:", 131);
        scanf("%f", &a);
        scanf("%f", &b);
        scanf("%f", &c);

        v = (a > (b + c) || b > (a + c) || c > (a + b) || a <= 0 || b <= 0 || c <= 0); 

        if (a > (b + c) || b > (a + c) || c > (a + b) || a <= 0 || b <= 0 || c <= 0){
            printf("\nDados inv%clidos. Os valores inseridos n%co configuram um tri%cngulo.\n", 160, 198, 131);
        }
    } while (v == 1);

    p=(a+b+c)/2;
    A=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("\nA %crea do tri%cngulo %c: %0.2f.\n", 160, 131, 130, A);

return 0;
}