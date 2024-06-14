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
import model.reserva;
import model.encomendaDados;
import view.FrmReservar;

/**
 *
 * @author giuli
 */
public class DaoReserva {
    
    Connection con = null;
    PreparedStatement pstm = null;

    public List<reserva> getReservas() {
        List<reserva> lista = new ArrayList<>();
        ResultSet rs = null;
        con = new Conexao().getConexao();

        try {
            pstm = con.prepareStatement("SELECT * FROM reserva");
            rs = this.pstm.executeQuery();
            if (rs.next()) {
                do {
                    reserva r = new reserva();
                    r.codReserva = rs.getInt("codigo_reserva");
                    r.codItens = rs.getInt("codigo_item");
                    r.quant = rs.getInt("quantidade");
                    r.codCliente = rs.getInt("codigo_cliente");
                                        
                    lista.add(r);

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
    
    public List<reserva> getFiltrarreserva(String filtrando) {
        List<reserva> lista = new ArrayList<>();
        ResultSet rs = null;
        con = new Conexao().getConexao();
        filtrando = "SELECT * FROM reserva LEFT JOIN reservaimagem ON reserva.molde = reservaImagem.modelo where reserva.tamanho = 'XS' and reserva.molde LIKE " + filtrando;

        try {
            pstm = con.prepareStatement(filtrando);
            rs = this.pstm.executeQuery();
            if (rs.next()) {
                do {
                    reserva r = new reserva();
                    r.codReserva = rs.getInt("codigo_reserva");
                    r.codItens = rs.getInt("codigo_item");
                    r.quant = rs.getInt("quantidade");
                    r.codCliente = rs.getInt("codigo_cliente");
                    
                    lista.add(r);

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
    
    public void Reservar() {
        con = new Conexao().getConexao();

        try {
            pstm = con.prepareStatement("INSERT INTO reservar (codigo_item, quantidade, codigo_cliente) VALUES (?,?,?)");
            pstm.setInt(1, FrmReservar.cod);
            pstm.setInt(2, FrmReservar.quant);
            pstm.setInt(3, encomendaDados.codCliente);
            
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

    }

    
}
