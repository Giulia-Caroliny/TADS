/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dao;

import conexao.Conexao;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JOptionPane;
import model.Usuario;

/**
 *
 * @author Afranio
 */
public class DaoUsuario {
    Connection con = null;
    PreparedStatement pstm = null;

public List<Usuario> getUsuarios()
{
    List<Usuario> lista = new ArrayList<Usuario>();
    ResultSet rs = null;
    con = new Conexao().getConexao();
    
    try{
    pstm = con.prepareStatement("SELECT * FROM tb_usuario");
    rs =  this.pstm.executeQuery();
    if(rs.first())
    {
        do{
            Usuario u = new Usuario();
             u.id = rs.getInt("id");
             u.nome=rs.getString("nome");
             u.email = rs.getString("email");
             u.senha = rs.getString("senha");
             
             lista.add(u);
            
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


public boolean validarLogin(String n, String s)
{
    boolean resp =false; 
    ResultSet rs = null;
    con = new Conexao().getConexao();
    
    try{
    pstm = con.prepareStatement("SELECT * FROM tb_usuario WHERE nome=? and senha=?");
    pstm.setString(1, n);
    pstm.setString(2, s);
    rs =  this.pstm.executeQuery();
    if(rs.first())
    {
        resp=true;
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
    
    return resp;
}





}
