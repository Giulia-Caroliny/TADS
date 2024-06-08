package swing;
import javax.swing.JOptionPane;
import PseudoCalculadora.Caucular;



public class Swing {

    public static void main(String[] args) {
        
        Caucular cal = new Caucular();
        String opcao[] = {"soma", "subtração", "divisão", "multiplicação"};
        
        cal.num1 = Double.parseDouble(JOptionPane.showInputDialog("Digite um número:"));
        cal.num2 = Double.parseDouble(JOptionPane.showInputDialog("Digite um número:"));
        
        String escolha = (String)JOptionPane.showInputDialog(null, "Escolha uma operação", "Pseudo Calculadora", JOptionPane.QUESTION_MESSAGE, null, opcao, "soma");
        
        switch(escolha)
        {
            case "soma":
                JOptionPane.showMessageDialog(null, cal.somaNumeros());
                break;
            case "subtração":
                JOptionPane.showMessageDialog(null, cal.subtracaoNumeros());
                break;
            case "divisão":
                JOptionPane.showMessageDialog(null, cal.divisaoNumeros());
                break;
            case "multiplicação":
                JOptionPane.showMessageDialog(null, cal.multiplicacaoNumeros());
                break;
        }
        
    }
    
}
