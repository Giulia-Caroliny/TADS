/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package q5;

import java.util.Scanner;

/**
 *
 * @author giuli
 */
public class Q5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Carga horária da disciplina: ");
        int cargaH = sc.nextInt();

        System.out.println("Hora/aula por encontro: ");
        int horaAula = sc.nextInt();

        System.out.println("Quantidade de faltas: ");
        int faltas = sc.nextInt();

        System.out.println("Percentual de faltas: "
                + (faltas * 100) / (cargaH / horaAula));

        sc.close();
    }

}
