/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package q4;

import java.util.Scanner;

/**
 *
 * @author giuli
 */
public class Q4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Horas normais trabalhadas: ");
        int horaN = sc.nextInt();

        System.out.println("Horas extras trabalhadas: ");
        int horaE = sc.nextInt();

        System.out.println("Salário bruto: "
                + (horaN * 10 + horaE * 15));

        System.out.println("Salário líquido: "
                + ((horaN * 10 + horaE * 15) - (horaN * 10 + horaE * 15) * 0.1));

        sc.close();
    }

}
