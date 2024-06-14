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
import model.UsuarioIdenti;
import model.funcionarioCadastro;

public class DaoUsuario {

    Connection con = null;
    PreparedStatement pstm = null;
    public static int teste;

    public List<Usuario> getUsuarios() {
        List<Usuario> lista = new ArrayList<>();
        ResultSet rs = null;
        con = new Conexao().getConexao();

        try {
            pstm = con.prepareStatement("SELECT * FROM usuario"); //tirar o id como pesquisa
            rs = this.pstm.executeQuery();
            if (rs.first()) {
                do {
                    Usuario u = new Usuario();
                    u.nome = rs.getString("nome");
                    u.email = rs.getString("e-mail");
                    u.senha = rs.getString("senha");

                    lista.add(u);

                } while (rs.next());
            }

            pstm.close();
        } catch (SQLException erro) {
            JOptionPane.showMessageDialog(null, "Erro ao buscar dados no BD " + erro);
        } finally {
            try {
                con.close();
            } catch (SQLException err) {
                JOptionPane.showMessageDialog(null, "Erro ao fechar a conexão de busca " + err);
            }
        }

        return lista;
    }

    public boolean validarLogin(String n, String s) {
        boolean resp = false;
        ResultSet rs = null;
        con = new Conexao().getConexao();

        try {
            pstm = con.prepareStatement("SELECT * FROM usuarios WHERE nome=? and senha=?");
            pstm.setString(1, n);
            pstm.setString(2, s);
            rs = this.pstm.executeQuery();

            if (rs.next()) {
                do {
                    UsuarioIdenti.id = rs.getInt("codigo");
                    UsuarioIdenti.identificador = rs.getString("identificador");
                    resp = true;
                } while (resp == false);
            }

            pstm.close();
        } catch (SQLException erro) {
            JOptionPane.showMessageDialog(null, "Erro ao buscar dados no BDll " + erro);
        } finally {
            try {
                con.close();
            } catch (SQLException err) {
                JOptionPane.showMessageDialog(null, "Erro ao fechar a conexão de busca " + err);
            }
        }

        return resp;
    }

    public int getIDCliente() {
        int id = -1;
        ResultSet rs = null;
        con = new Conexao().getConexao();

        String Consulta = "SELECT codigo_cliente FROM clientes WHERE codigo_usuario = " + Integer.toString(UsuarioIdenti.id);

        try {
            pstm = con.prepareStatement(Consulta);
            rs = this.pstm.executeQuery();
            if (rs.next()) {
                do {
                    id = rs.getInt("codigo_cliente");
                } while (id == -1);
            }

            pstm.close();
        } catch (SQLException erro) {
            JOptionPane.showMessageDialog(null, "Erro ao buscar dados no BDxx " + erro);
        } finally {
            try {
                con.close();
            } catch (SQLException err) {
                JOptionPane.showMessageDialog(null, "Erro ao fechar a conexão de busca " + err);
            }
        }

        return id;
    }

    public void cadastrarUsuario(Usuario user) {
        con = new Conexao().getConexao();
        String consulta;
        ResultSet rs = null;

        try {
            pstm = con.prepareStatement("INSERT INTO `usuarios` (`nome`, `cpf`, `email`, `telefone`, `endereco`, `identificador`, `senha`) VALUES (?,?,?,?,?,?,?)");
            pstm.setString(1, user.nome);
            pstm.setInt(2, user.CPF);
            pstm.setString(3, user.email);
            pstm.setString(4, user.telefone);
            pstm.setString(5, user.endereco);
            pstm.setString(6, user.identificador);
            pstm.setString(7, user.senha);
            this.pstm.execute();

            pstm.close();
        } catch (SQLException erro) {
            JOptionPane.showMessageDialog(null, "Erro ao salvar user no BD " + erro);
        }

        try {
            pstm = con.prepareStatement("SELECT * FROM usuarios WHERE nome=? and senha=?");
            pstm.setString(1, user.nome);
            pstm.setString(2, user.senha);
            rs = this.pstm.executeQuery();

            if (rs.next()) {
                do {
                    user.id = rs.getInt("codigo");

                    JOptionPane.showMessageDialog(null, user.id + user.identificador);
                } while (user.id == -1);
            }

            pstm.close();
        } catch (SQLException erro) {
            JOptionPane.showMessageDialog(null, "Erro ao buscar dados no BDll " + erro);
        }

        if ("C".equals(user.identificador)) {

            try {
                pstm = con.prepareStatement("INSERT INTO clientes (codigo_cliente, codigo_usuario) VALUES (null, ?)");
                pstm.setInt(1, user.id);
                this.pstm.execute();

                pstm.close();
            } catch (SQLException erro) {
                JOptionPane.showMessageDialog(null, "Erro ao salvar user no BD " + erro);
            } finally {
                try {
                    con.close();
                } catch (SQLException err) {
                    JOptionPane.showMessageDialog(null, "Erro ao fechar a conexão de salvamento " + err);
                }
            }

        } else {

            try {
                pstm = con.prepareStatement("INSERT INTO funcionarios (codigo_funcionario, codigo_usuario, cargo, data_ingresso) VALUES (null, ?,?,?)");
                pstm.setInt(1, user.id);
                pstm.setString(2, funcionarioCadastro.cargo);
                pstm.setString(3, funcionarioCadastro.dataIngresso);

                this.pstm.execute();

                pstm.close();
            } catch (SQLException erro) {
                JOptionPane.showMessageDialog(null, "Erro ao salvar user no BDmm " + erro);
            } finally {
                try {
                    con.close();
                } catch (SQLException err) {
                    JOptionPane.showMessageDialog(null, "Erro ao fechar a conexão de salvamento " + err);
                }
            }
        }

    }

}
