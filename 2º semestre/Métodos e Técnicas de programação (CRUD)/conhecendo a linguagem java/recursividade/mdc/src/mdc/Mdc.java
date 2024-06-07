package mdc;
import javax.swing.JOptionPane;
import model.calculandoMDC;

public class Mdc {

    public static void main(String[] args) {
        int x = Integer.parseInt(JOptionPane.showInputDialog("digite o primeiro valor."));
        int y = Integer.parseInt(JOptionPane.showInputDialog("digite o segundo valor."));
        
        JOptionPane.showMessageDialog(null,"O máximo divisor comun de " + x + " e " + y + " é: " + calculandoMDC.calculo(x, y));
    }
    
}
