package model;
import javax.swing.JOptionPane;

/**
 *
 * @author giuli
 */
public class operacoes {
    public float num1;
    public float num2;
    
    public float somar()
    {
        try
        {
            return num1+num2;
        } catch(NumberFormatException erro)
        {
            JOptionPane.showMessageDialog(null, "Só podem ser inseridos números!" + erro, "Formato inválido", JOptionPane.ERROR_MESSAGE);
        }
        return num1+num2;
    }
    
    public float subtrair()
    {
        try
        {
            return num1 - num2;
        } catch(NumberFormatException erro)
        {
            JOptionPane.showMessageDialog(null, "Só podem ser inseridos números!" + erro, "Formato inválido", JOptionPane.ERROR_MESSAGE);
        }
        
        return num1-num2;
    }
    
    public float multiplicar()
    {
        try
        {
            return num1*num2;
        } catch(NumberFormatException erro)
        {
            JOptionPane.showMessageDialog(null, "Só podem ser inseridos números!" + erro, "Formato inválido", JOptionPane.ERROR_MESSAGE);
        }
        
        return num1*num2;
    }
    
    public float dividir()
    {
        try
        {
            return num1/num2;
        } catch(ArithmeticException erro)
        {
            JOptionPane.showMessageDialog(null, "Não existe divisão por 0!" + erro, "Erro", JOptionPane.ERROR_MESSAGE);
        }
        
        try
        {
            return num1/num2;
        } catch(NumberFormatException erro)
        {
            JOptionPane.showMessageDialog(null, "Só podem ser inseridos números!" + erro, "Formato inválido", JOptionPane.ERROR_MESSAGE);
        }
        
        return num1/num2;
    }
    
}
