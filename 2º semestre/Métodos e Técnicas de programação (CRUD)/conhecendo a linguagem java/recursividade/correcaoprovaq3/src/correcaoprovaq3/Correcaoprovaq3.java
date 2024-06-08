package correcaoprovaq3;

import javax.swing.JOptionPane;

public class Correcaoprovaq3 {

    public static void main(String[] args) {
        
    JOptionPane.showMessageDialog(null, fib(10));    
        
    } 
    public static int fib(int n){
            if(n<=1)
                return n;
        else
            return fib(n-1) + fib(n-2);
    }        
}
