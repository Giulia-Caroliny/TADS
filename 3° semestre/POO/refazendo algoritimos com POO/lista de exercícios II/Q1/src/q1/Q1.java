/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package q1;

import java.util.Scanner;

/**
 *
 * @author giuli
 */
public class Q1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Insira um número de 1 a 5: ");
        int num = sc.nextInt();

        switch (num) {
            case 1 ->
                System.out.println("Número Um.");
            case 2 ->
                System.out.println("Número Dois.");
            case 3 ->
                System.out.println("Número Três.");
            case 4 ->
                System.out.println("Número Quatro.");
            case 5 ->
                System.out.println("Número Cinco.");
            default -> {
                System.out.println("Número Inválido");
                throw new AssertionError();
            }
        }

        sc.close();
    }

}
