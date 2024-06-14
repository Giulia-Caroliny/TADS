/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controller;
import dao.DaoUsuario;
import java.util.List;
import java.util.ArrayList;
import javax.swing.JOptionPane;
import model.Usuario;
import model.encomendaDados;

/**
 *
 * @author giuli
 */
public class ControllerUsuario {
    
    DaoUsuario dao = new DaoUsuario();
    List<Usuario> lista = new ArrayList<>();
    
    public boolean Logar (String u, String s) {
        boolean resp = dao.validarLogin(u, s);
        if(!resp) JOptionPane.showMessageDialog(null, "Usuário ou senha inválidos", "Erro", JOptionPane.ERROR_MESSAGE);
       
        return resp;
    }
    
    public void getIDCliente(){
        encomendaDados.codCliente = dao.getIDCliente();
    }
    
    public boolean inserirUsuario(Usuario u) {
        if (!u.nome.equals("") && u.CPF != 0 && !u.email.equals("") && !u.senha.equals("")) {
            dao.cadastrarUsuario(u);
            JOptionPane.showMessageDialog(null, "Cadastro realizado com sucesso!!!");
            return true;
        } else {
            JOptionPane.showMessageDialog(null, "Todos os campos obrigatórios devem ser preenchidos");
            return false;
        }
    }
    
    public List<Usuario> getUpdateUsuarios() {
        lista.clear();
        lista = dao.getUsuarios();
        return lista;
    }
}
