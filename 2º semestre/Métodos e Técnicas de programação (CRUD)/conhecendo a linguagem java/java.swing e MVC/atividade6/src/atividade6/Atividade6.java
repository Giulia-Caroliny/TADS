package atividade6;

import javax.swing.JOptionPane;
import model.pesquisarNum;

public class Atividade6 {
    public static void main(String[] args) {
        String numero = JOptionPane.showInputDialog("Digite um número grande:");
        char unidade = JOptionPane.showInputDialog("Digite a unidade que deseja contar:").charAt(0);

        String mensagem = "A quantidade de vezes que a unidade '" + unidade + "' aparece é: " + pesquisarNum.contarUnidade(numero, unidade);
        JOptionPane.showMessageDialog(null, mensagem);
    }
    
}
