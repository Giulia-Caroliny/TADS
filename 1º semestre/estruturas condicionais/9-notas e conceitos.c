#include <stdio.h>

int main()
{

float trabalho, aval, exame, media;

printf("Insira as notas do trabalho de laborat%crio, avalia%c%co semestral e exame final:", 162, 135, 198);
scanf("%f", &trabalho);
scanf("%f", &aval);
scanf("%f", &exame);

media=(trabalho+aval+exame)/3;

if (media>=0 && media<5){
    printf("Sua m%cdia %c \"%.2f\" e seu conceito %c \"E\"", 130, 130, media, 130);
}
else if (media>=5 && media<6){
    printf("Sua m%cdia %c \"%.2f\" e seu conceito %c \"D\"", 130, 130, media, 130);
}
else if (media>=6 && media<7){
    printf("Sua m%cdia %c \"%.2f\" e seu conceito %c \"C\"", 130, 130, media, 130);
}
else if (media>=7 && media<8){
    printf("Sua m%cdia %c \"%.2f\" e seu conceito %c \"B\"", 130, 130, media, 130);
}
else if (media>=8 && media<=10){
    printf("Sua m%cdia %c \"%.2f\" e seu conceito %c \"A\"", 130, 130, media, 130);
}
else {
    printf("A m%cdia %c inferior a 0 ou superior a 10. As notas inseridas est%co incorretas.", 130, 130, 198);
}

return 0;

}