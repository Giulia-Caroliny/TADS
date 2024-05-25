package calcular;

public class calculando {
    public static int sequencia(int n)
    {
        if (n <= 1) return 1;
        else return sequencia(n - 1) + sequencia(n - 2);
    }
    
}
