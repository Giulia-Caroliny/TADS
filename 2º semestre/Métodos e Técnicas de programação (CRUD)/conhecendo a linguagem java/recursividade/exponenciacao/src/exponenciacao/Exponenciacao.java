package exponenciacao;
import javax.swing.JOptionPane;
import model.exponencial;

public class Exponenciacao {

    public static void main(String[] args) {
        int base, expoente;
        
        base = Integer.parseInt(JOptionPane.showInputDialog("Insira a base da exponenciação."));
        expoente = Integer.parseInt(JOptionPane.showInputDialog("Insira o expoente da exponenciação."));
        
        JOptionPane.showMessageDialog(null, "O resultado da exponenciação é: " + exponencial.calculando(base, expoente));

    }
    
}
