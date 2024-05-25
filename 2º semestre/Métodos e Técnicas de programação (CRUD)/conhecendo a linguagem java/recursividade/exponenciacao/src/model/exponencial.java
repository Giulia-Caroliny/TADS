package model;

public class exponencial {
    public static int calculando(int base, int expoente)
    {
        if(expoente == 0) return 1;
        else return base * calculando(base, expoente - 1);
        
    }
    
}
