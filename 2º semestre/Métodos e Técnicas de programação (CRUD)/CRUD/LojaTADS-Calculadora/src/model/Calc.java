package model;

/**
 *
 * @author giuli
 */
public class Calc {
    public double Operaçao(double n1, double n2, int op)
    {
        switch(op)
        {
            case 1 -> {
                return n1 + n2;
            }
            case 2 -> {
                return n1 - n2;
            }
            case 3 -> {
                return n1 / n2;
            }
            case 4 -> {
                return n1 * n2;
            }
            default -> {                
            }
        }
        return 0;
    }
}
