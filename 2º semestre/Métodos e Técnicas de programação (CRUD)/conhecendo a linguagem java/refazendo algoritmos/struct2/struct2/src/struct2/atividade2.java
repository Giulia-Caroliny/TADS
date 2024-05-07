package struct2;

import java.util.Scanner;

public class atividade2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o nome da rua: ");
        String rua = scanner.nextLine();

        System.out.print("Digite o número: ");
        int numero = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Digite a cidade: ");
        String cidade = scanner.nextLine();

        System.out.print("Digite o estado: ");
        String estado = scanner.nextLine();

        System.out.print("Digite o CEP: ");
        String cep = scanner.nextLine();

        System.out.println("\nEndereço\n");
        System.out.println("Nome da rua: " + rua);
        System.out.println("Numero: " + numero);
        System.out.println("Cidade: " + cidade);
        System.out.println("Estado: " + estado);
        System.out.println("CEP: " + cep);

    }
}