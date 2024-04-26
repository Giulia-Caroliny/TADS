#include <stdio.h>

int main(){
    int a, *pa;
    float b, *pb;
    char c, *pc;

    a = 1;
    b = 3.3;
    c = 'c';

    pa = &a;
    pb = &b;
    pc = &c;

    printf("\nVariaveis a, b e c antes da deifica%c%co: %d, %.2f e %c\n\nVariaveis pa, pb e pc: %d, %d e %d.\n", 135, 198, a, b, c, pa, pb, pc);

    *pa = 2;
    *pb = 6.6;
    *pc = 'b';
    
    printf("\nVariaveis a, b e c depois da deifica%c%co: %d, %.2f e %c.\n", 135, 198, a, b, c);

    return 0;
}