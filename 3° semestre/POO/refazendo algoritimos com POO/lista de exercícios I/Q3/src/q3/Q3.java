/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package q3;

import java.util.Scanner;

/**
 *
 * @author giuli
 */
public class Q3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Custo do produto: ");
        double custo = sc.nextDouble();

        System.out.print("Percentual de acréscimo: ");
        double percentual = sc.nextDouble();

        System.out.println("O valor de venda é de "
                + (custo + custo * percentual / 100)
                + " reais.");

        sc.close();
    }

}
