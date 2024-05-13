package struct4;
import java.util.Scanner;
import model.Computador;

public class atividade4 {
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        Computador[] computadores = new Computador[3];

        for (int i = 0; i < 3; i++)
        {
            computadores[i] = new Computador();

            System.out.println("Cadastro do computador " + (i + 1) + ":");

            System.out.print("Digite a marca: ");
            computadores[i].marca = sc.nextLine();

            System.out.print("Digite o ano de fabricacao: ");
            computadores[i].anoFabricacao = sc.nextInt();

            System.out.print("Digite o peso: ");
            computadores[i].peso = sc.nextFloat();

            sc.nextLine();
            System.out.println();
        }

        System.out.println("Computadores cadastrados:");

        for (int i = 0; i < 3; i++)
        {
            System.out.println("Computador " + (i + 1) + ":");
            System.out.println("Marca: " + computadores[i].marca);
            System.out.println("Ano de Fabricacao: " + computadores[i].anoFabricacao);
            System.out.println("Peso: " + computadores[i].peso);
            System.out.println();
        }

        sc.close();
    }
}