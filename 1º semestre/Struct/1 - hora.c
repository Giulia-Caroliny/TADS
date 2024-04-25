#include <stdio.h>

struct Hora
{
    int hora, minuto, segundo;
};

int main()
{
    struct Hora a;

    puts("Hora. De 00 a 23.");
    scanf("%d", &a.hora);

    puts("Minutos. De 00 a 60.");
    scanf("%d", &a.minuto);

    puts("Segundos. De 00 a 60.");
    scanf("%d", &a.segundo);

    printf("%d:%d e %d segundos.", a.hora, a.minuto, a.segundo);

    return 0;
}
