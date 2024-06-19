/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package q2;

import java.util.Scanner;

/**
 *
 * @author giuli
 */
public class Q2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Número de quilowatts: ");
        double watts = sc.nextDouble();

        System.out.println("O valor a ser pago é de "
                + (0.12 * watts + 0.12 * watts * 0.18)
                + " reais.");

        sc.close();
    }

}
