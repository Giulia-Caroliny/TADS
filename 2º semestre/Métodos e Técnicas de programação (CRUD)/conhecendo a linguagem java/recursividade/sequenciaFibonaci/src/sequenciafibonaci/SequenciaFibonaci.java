package sequenciafibonaci;
import javax.swing.JOptionPane;
import calcular.calculando;
public class SequenciaFibonaci {

    public static void main(String[] args) {
        int num = Integer.parseInt(JOptionPane.showInputDialog(null, "Insira um número."));
       
        JOptionPane.showMessageDialog(null, "o número é: " + calculando.sequencia(num - 1));
    }  
}
