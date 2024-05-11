package fatorial;
import javax.swing.JOptionPane;
import model.calculandofat;
public class Fatorial {
    public static void main(String[] args) {
        int num, fat;
        
        num = Integer.parseInt(JOptionPane.showInputDialog("Digite um número."));
        
        fat = calculandofat.calcular(num);
        
        JOptionPane.showMessageDialog(null, "O fatorial de " + num + " é: " + fat);
    }
    
}
