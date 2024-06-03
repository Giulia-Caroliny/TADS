package model;

public class somar {
    public static int somando(int num)
    {
        if(num == 0) return 0;
        else return num + somando(num-1);
    }
    
}
