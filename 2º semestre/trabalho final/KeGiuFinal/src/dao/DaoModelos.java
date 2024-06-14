/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dao;

import conexao.Conexao;
import java.io.ByteArrayInputStream;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JOptionPane;
import model.modelos;
import java.sql.Blob;
import javax.imageio.ImageIO;
import model.encomendaDados;

/**
 *
 * @author giuli
 */
public class DaoModelos {

    Connection con = null;
    PreparedStatement pstm = null;

    public List<modelos> getModelos() {
        List<modelos> lista = new ArrayList<>();
        ResultSet rs = null;
        con = new Conexao().getConexao();

        try {
            pstm = con.prepareStatement("SELECT * FROM modelos LEFT JOIN modelosimagem ON modelos.molde = modelosImagem.modelo where modelos.tamanho = 'XS'");
            rs = this.pstm.executeQuery();
            if (rs.next()) {
                do {
                    modelos m = new modelos();
                    m.molde = rs.getString("molde");
                    m.tecidoTam = rs.getInt("tecido_tamanho");
                    m.codMateriais = rs.getInt("acessorios_necessarios");
                    m.horasTrab = rs.getInt("horas_trabalho");
                    m.tamanho = rs.getString("tamanho");
                    Blob blob = rs.getBlob("imagem");
                    try {
                        byte[] img = blob.getBytes(1, (int) blob.length());
                        m.imagem = ImageIO.read(new ByteArrayInputStream(img));
                    } catch (Exception e) {
                        System.out.println(e);
                    }

                    lista.add(m);

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

    public List<modelos> getFiltrarModelos(String filtrando) {
        List<modelos> lista = new ArrayList<>();
        ResultSet rs = null;
        con = new Conexao().getConexao();
        filtrando = "SELECT * FROM modelos LEFT JOIN modelosimagem ON modelos.molde = modelosImagem.modelo where modelos.tamanho = 'XS' and modelos.molde LIKE " + filtrando;

        try {
            pstm = con.prepareStatement(filtrando);
            rs = this.pstm.executeQuery();
            if (rs.next()) {
                do {
                    modelos m = new modelos();
                    m.molde = rs.getString("molde");
                    m.tecidoTam = rs.getInt("tecido_tamanho");
                    m.codMateriais = rs.getInt("acessorios_necessarios");
                    m.horasTrab = rs.getInt("horas_trabalho");
                    m.tamanho = rs.getString("tamanho");
                    Blob blob = rs.getBlob("imagem");
                    try {
                        byte[] img = blob.getBytes(1, (int) blob.length());
                        m.imagem = ImageIO.read(new ByteArrayInputStream(img));
                    } catch (Exception e) {
                        System.out.println(e);
                    }

                    lista.add(m);

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

    public void getOModelo() {
        ResultSet rs = null;
        con = new Conexao().getConexao();
        String mod = "SELECT * FROM modelos where modelos.tamanho = '" + encomendaDados.tamanho + "' and modelos.molde = '" + encomendaDados.Modelo + "'";

        try {
            pstm = con.prepareStatement(mod);
            rs = this.pstm.executeQuery();
            if (rs.next()) {
                do {
                    encomendaDados.quantT = rs.getInt("tecido_tamanho");
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
    }

    public modelos getOModelo2(String tamanho) {
        ResultSet rs = null;
        con = new Conexao().getConexao();
        String mod = "SELECT * FROM modelos where modelos.tamanho = '" + tamanho + "' and modelos.molde = '" + encomendaDados.Modelo + "'";

        modelos mode = new modelos();
        
        try {
            pstm = con.prepareStatement(mod);
            rs = this.pstm.executeQuery();
            if (rs.next()) {
                do {
                    mode.horasTrab = rs.getInt("horas_trabalho");
                    mode.tecidoTam = rs.getInt("tecido_tamanho");

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
        return mode;
    }
}
