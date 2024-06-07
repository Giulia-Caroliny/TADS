package model;

public class calculandoMDC {
    public static int calculo(int x, int y)
    {
        if (y == 0) return x;
        else return calculo(y, x % y);
    }
}
