package correcaoprovaq4;
import java.util.Scanner;

/**
 *
 * @author giuli
 */
public class CorrecaoProvaQ4 {

    public static void main(String[] args) {
        int trocar;
        int[] valores = new int[20];
        Scanner sc = new Scanner(System.in);
        
        for(int i = 0; i < 20; i++)
        {
            System.out.print("Insira um valor:");
            valores[i] = sc.nextInt();
            for(int j = 0; j < i; j++)
            {
                if(valores[i] == valores[j])
                {
                    System.out.println("Número já inserido. Temte outro.");
                    i--;
                }
            }
        }
        
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if (valores[i] > valores[j]) 
                {
                    trocar =valores[i];
                    valores[i] = valores[j];
                    valores[j] = trocar;
                }
            }
        }
        for (int i = 0; i < 20; i++)
        {
            System.out.println(valores[i]);
        }
    }   
}
