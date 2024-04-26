#include <stdio.h>

int main(){

    int a = 5, b = 12, c= 5;
    int *p;
    int *q;

    p = &a;
    q = &b;
    (*p)++;

    c = *p + *q;
    printf("%d, %d, %d", a, b, c);
    return 0; 
}