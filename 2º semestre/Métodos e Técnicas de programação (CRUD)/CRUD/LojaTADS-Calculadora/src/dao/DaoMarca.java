package dao;
import java.sql.*;
import java.util.List;
import java.util.ArrayList;
import model.Marca;
import conexao.Conexao;
import javax.swing.JOptionPane;

public class DaoMarca {
Connection con = null;
PreparedStatement pstm = null;

public List<Marca> getMarcas()
{
    List<Marca> lista = new ArrayList<Marca>();
    ResultSet rs = null;
    con = new Conexao().getConexao();
    
    try{
    pstm = con.prepareStatement("SELECT * FROM tb_marca");
    rs =  this.pstm.executeQuery();
    if(rs.first())
    {
        do{
            Marca m = new Marca();
             m.id = rs.getInt("id");
             m.descricao=rs.getString("descricao");
             
             
             lista.add(m);
            
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


public int getIdMarcaByDescricao(String descricao)
{
    int id=0;
    ResultSet rs = null;
    con = new Conexao().getConexao();
    
    try{
    pstm = con.prepareStatement("SELECT id FROM tb_marca WHERE descricao =?");
    pstm.setString(1, descricao);
    rs =  this.pstm.executeQuery();
    if(rs.first())
    {
       id = rs.getInt("id");
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
    
    return id;
}


public String getDescricaoMarcaById(int id)
{
    String desc="";
    ResultSet rs = null;
    con = new Conexao().getConexao();
    
    try{
    pstm = con.prepareStatement("SELECT descricao FROM tb_marca WHERE id =?");
    pstm.setInt(1, id);
    rs =  this.pstm.executeQuery();
    if(rs.first())
    {
       desc = rs.getString("descricao");
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
    
    return desc;
}




public List<String> carregaComboBox()
{
    List<String> lista = new ArrayList<String>();
    ResultSet rs = null;
    con = new Conexao().getConexao();
    
    try{
    pstm = con.prepareStatement("SELECT descricao FROM tb_marca ORDER BY descricao ASC");
    rs =  this.pstm.executeQuery();
    if(rs.first())
    {
        do{
            String m =rs.getString("descricao");
             
             
             lista.add(m);
            
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

public void salvarMarca(Marca marca)
{
    con = new Conexao().getConexao();
    
    try{
    pstm = con.prepareStatement("INSERT INTO tb_marca (descricao) VALUES (?)");
    pstm.setString(1,marca.descricao );
    this.pstm.execute();
    
    
    pstm.close();
    }
    catch(SQLException erro)
    {
        JOptionPane.showMessageDialog(null, "Erro ao salvar notebook no BD "+erro);
    }
    finally{
        try{
        con.close();
        }
        catch(SQLException err)
        {
            JOptionPane.showMessageDialog(null, "Erro ao fechar a conexão de salvamento "+err);
        }
    }
    

}

public void editarMarca(Marca marca)
{
    con = new Conexao().getConexao();
    
    try{
    pstm = con.prepareStatement("UPDATE tb_marca SET descricao =? WHERE id =?");
    pstm.setString(1,marca.descricao );
    pstm.setInt(2, marca.id);
    this.pstm.execute();
    JOptionPane.showMessageDialog(null,"Marca alterada com sucesso!!!");
    
    pstm.close();
    }
    catch(SQLException erro)
    {
        JOptionPane.showMessageDialog(null, "Erro ao alterar notebook no BD "+erro);
    }
    finally{
        try{
        con.close();
        }
        catch(SQLException err)
        {
            JOptionPane.showMessageDialog(null, "Erro ao fechar a conexão de alteração "+err);
        }
    }
    

}





public void excluirMarca(int id)
{
    con = new Conexao().getConexao();
    
    try{
    pstm = con.prepareStatement("DELETE FROM tb_marca WHERE id=?");
    pstm.setInt(1, id);
    this.pstm.execute();
    JOptionPane.showMessageDialog(null,"Marca excluída com sucesso!!!");
    
    pstm.close();
    }
    catch(SQLException erro)
    {
        JOptionPane.showMessageDialog(null, "Erro ao excluir notebook no BD "+erro);
    }
    finally{
        try{
        con.close();
        }
        catch(SQLException err)
        {
            JOptionPane.showMessageDialog(null, "Erro ao fechar a conexão de exclusão "+err);
        }
    }
    

}

}
