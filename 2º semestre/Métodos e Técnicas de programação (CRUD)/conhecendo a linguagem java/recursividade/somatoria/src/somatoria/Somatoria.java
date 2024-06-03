package somatoria;

import javax.swing.JOptionPane;
import model.somar;

public class Somatoria {

    public static void main(String[] args) {
        int num = Integer.parseInt(JOptionPane.showInputDialog(null, "Insira um número.")); 
        JOptionPane.showMessageDialog(null, "A somatória dos " + num + " primeiros números inteiro é: " + somar.somando(num));
    }
    
}
