package model;

public class fatorar {
    public static int fatorando (int num)
        {
            if (num == 0) return 1;
            else return num * fatorando(num - 1);
        }
    
}
