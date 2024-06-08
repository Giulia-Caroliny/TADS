package PseudoCalculadora;

public class Caucular {
    public double num1;
    public double num2;
    
    public double somaNumeros()
    {
        return num1 + num2;
    }
    
    public double subtracaoNumeros()
    {
        return num1 - num2;
    }
    
    public double multiplicacaoNumeros()
    {
        return num1 * num2;
    }
    
    public double divisaoNumeros()
    {
        if (num2 != 0) {
            return num1 / num2;
        } else {
            return 0;
        }  
    }
}
