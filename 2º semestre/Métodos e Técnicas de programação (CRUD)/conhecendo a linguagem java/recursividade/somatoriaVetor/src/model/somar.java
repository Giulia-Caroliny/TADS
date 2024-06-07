package model;

public class somar {
    public static int somandoVetor(int num[], int tam)
    {
        if(tam == 0) return 0;
        else return (num[tam-1] + somandoVetor(num, tam - 1));
        
    }   
}
