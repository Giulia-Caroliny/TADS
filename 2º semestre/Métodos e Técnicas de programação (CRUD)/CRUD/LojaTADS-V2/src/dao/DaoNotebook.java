package dao;
import java.sql.*;
import java.util.List;
import java.util.ArrayList;
import model.Notebook;
import conexao.Conexao;
import javax.swing.JOptionPane;

public class DaoNotebook {
Connection con = null;
PreparedStatement pstm = null;

public List<Notebook> getNotebooks()
{
    List<Notebook> lista = new ArrayList<Notebook>();
    ResultSet rs = null;
    con = new Conexao().getConexao();
    
    try{
    pstm = con.prepareStatement("SELECT * FROM tb_notebook");
    rs =  this.pstm.executeQuery();
    if(rs.first())
    {
        do{
            Notebook n = new Notebook();
             n.id = rs.getInt("id_note");
             n.modelo=rs.getString("modelo_note");
             n.marca = rs.getString("marca_note");
             n.serie = rs.getString("serie_note");
             
             lista.add(n);
            
        }while(rs.next());
    }
    
    pstm.close();
    }
    catch(SQLException erro)
    {
        JOptionPane.showMessageDialog(null, "Erro ao buscar dados no BD "+erro);
    }
    finally{
        try{
        con.close();
        }
        catch(SQLException err)
        {
            JOptionPane.showMessageDialog(null, "Erro ao fechar a conexão de busca "+err);
        }
    }
    
    return lista;
}


public void salvarNotebook(Notebook note)
{
    con = new Conexao().getConexao();
    
    try{
        pstm = con.prepareStatement("INSERT INTO tb_notebook (modelo_note, marca_note, serie_note) VALUES (?, ?, ?)");
        pstm.setString(1, note.modelo);
        pstm.setString(2, note.marca);
        pstm.setString(3, note.serie);
        this.pstm.execute();

        JOptionPane.showMessageDialog(null, "Notebook salvo com sucesso!");

        pstm.close();
    }
    catch(SQLException erro)
    {
        JOptionPane.showMessageDialog(null, "Erro ao buscar dados no BD "+erro);
    }
    finally{
        try{
            con.close();
        }
        catch(SQLException erro)
        {
            JOptionPane.showMessageDialog(null, "Erro ao fechar a conexão de busca "+erro);
        }
    }
}
    
}
