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

        System.out.println("Nome: ");
        String nome = sc.nextLine();

        if (nome.equals("Giulia")) {
            System.out.println("NOME CORRETO");
        } else {
            System.out.println("NOME INCORRETO");
        }

        sc.close();
    }

}
