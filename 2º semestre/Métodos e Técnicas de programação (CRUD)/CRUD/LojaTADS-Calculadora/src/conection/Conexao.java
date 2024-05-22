package conection;

import javax.swing.JOptionPane;
import java.sql.*;

/**
 *
 * @author giuli
 */
public class Conexao {
    Connection conection;
    public void conectaBD()
    {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            conection = DriverManager.getConnection("url", "user", "password");
            JOptionPane.showMessageDialog(null,"Conexão realizada com sucesso!");
        } catch (ClassNotFoundException drive) {
            JOptionPane.showMessageDialog(null, "Driver não encontrado: " + drive);
        } catch (SQLException fonte) {
            JOptionPane.showMessageDialog(null, "Fonte do BD não encontrado: " + fonte);
        }
    }
}
