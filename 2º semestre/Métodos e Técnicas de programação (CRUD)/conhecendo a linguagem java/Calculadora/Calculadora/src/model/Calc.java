/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package model;

/**
 *
 * @author giuli
 */
public class Calc {
    public double Operaçao(double n1, double n2, int op)
    {
        switch(op)
        {
            case 1 -> {
                return n1 + n2;
            }
            case 2 -> {
                return n1 - n2;
            }
            case 3 -> {
                return n1 / n2;
            }
            case 4 -> {
                return n1 * n2;
            }
            default -> {                
            }
        }
        return 0;
    }
}
