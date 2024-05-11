package model;

public class calculandofat {
    public static int calcular(int num)
    {
        int fat = 1;
        
        for(int i = num; i > 0; i--) 
        {
            fat *= i;
        }
        
        return fat;
    }
    
}
