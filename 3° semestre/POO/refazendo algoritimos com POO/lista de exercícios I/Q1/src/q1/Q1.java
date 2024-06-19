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

        System.out.print("Insira o comprimento do terreno: ");
        float comprimento = sc.nextFloat();

        System.out.print("Insira a largura do terreno: ");
        float largura = sc.nextFloat();

        System.out.println("\nA área do terreno é: "
                + comprimento * largura);

        sc.close();
    }

}
