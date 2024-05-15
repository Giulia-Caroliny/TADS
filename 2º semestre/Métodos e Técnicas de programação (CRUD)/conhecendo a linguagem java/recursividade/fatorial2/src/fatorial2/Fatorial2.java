package fatorial2;
import javax.swing.JOptionPane;
import model.fatorar;

public class Fatorial2 {

    public static void main(String[] args) {
        int num;
        
        num = Integer.parseInt(JOptionPane.showInputDialog("Digite um número."));
        JOptionPane.showMessageDialog(null, "O fatorial de " + num + " é: " + fatorar.fatorando(num));
    }
}
