package conexao;

import javax.swing.JOptionPane;
import java.sql.*;

public class Conexao {
    Connection conexao;
    
    private final String driver = "com.mysql.cj.jdbc.Driver";
    private final String url = "jdbc:mysql://localhost:3306/banco_note";
    private final String user = "root";
    private final String pass=""; 
    
    public Connection getConexao()
    {
        try{
        Class.forName(driver);//org.postgresql.Driver
        conexao = DriverManager.getConnection(url, user, pass);
        JOptionPane.showMessageDialog(null, "Conexão realizada com sucesso!!!");
        }
        catch(ClassNotFoundException drive)
        {
            JOptionPane.showMessageDialog(null, "Driver não encontrado: "+drive);
        }
        catch(SQLException fonte)
        {
            JOptionPane.showMessageDialog(null,"Fonte do BD não encontrada: "+fonte);
        }
        return conexao;
    }
    
}
