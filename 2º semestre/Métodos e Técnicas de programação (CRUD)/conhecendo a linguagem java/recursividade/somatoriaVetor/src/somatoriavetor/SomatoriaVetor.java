package somatoriavetor;

import javax.swing.JOptionPane;
import model.somar;

public class SomatoriaVetor {
    public static void main(String[] args) {
        int num[] = {8, 6, 4, 2}, tam = 4;
        
        JOptionPane.showMessageDialog(null, "A soma de 8, 6, 4 e 2 é: " + somar.somandoVetor(num, tam));
    }
    
}
