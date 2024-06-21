/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package q7;

import java.util.Scanner;

import java.time.Clock;

/**
 *
 * @author giuli
 */
public class Q7 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Segundos: ");
        int seconds = sc.nextInt();

        int minutes = seconds / 60;
        seconds = seconds % 60;
        int hours = minutes / 60;

        minutes = (minutes >= 60) ? minutes % 60 : minutes;

        System.out.println(""
                + hours
                + ":"
                + minutes
                + ":"
                + seconds);

        sc.close();
    }

}
