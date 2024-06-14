package dao;

import conexao.Conexao;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import javax.swing.JOptionPane;
import model.encomendaDados;

public class DaoEncomenda {

    Connection con = null;
    PreparedStatement pstm = null;

    public void Encomendar () {
        con = new Conexao().getConexao();

        try {
            pstm = con.prepareStatement("INSERT INTO encomenda (`retirado`, `tamanho`, `codigo_itens`, `modelo`, `status`, `codigo_cliente`) VALUES (?,?,?,?,?,?)");
            pstm.setString(1, "NÃO");
            pstm.setString(2, encomendaDados.tamanho);
            pstm.setInt(3, encomendaDados.codTecido);
            pstm.setString(4, encomendaDados.Modelo);
            pstm.setString(5, "EM ANDAMENTO");
            pstm.setInt(6,encomendaDados.codCliente);
            this.pstm.execute();

            pstm.close();
        } catch (SQLException erro) {
            JOptionPane.showMessageDialog(null, "Erro ao salvar encomenda no BD " + erro);
        } finally {
            try {
                con.close();
            } catch (SQLException err) {
                JOptionPane.showMessageDialog(null, "Erro ao fechar a conexão de salvamento " + err);
            }
        }
    }

}
