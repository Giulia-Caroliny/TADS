/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dao;

import conexao.Conexao;
import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.sql.Blob;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import javax.imageio.ImageIO;
import javax.swing.JOptionPane;
import model.Itens;
import model.encomendaDados;
import model.estoque;
import view.FrmReservar;
import view.FrmAlterarItens;

/**
 * mudar nos dao System.out.println(e);
 *
 * @author giuli
 */
public class DaoEstoque {

    Connection con = null;
    PreparedStatement pstm = null;

    public List<estoque> getItens() {
        List<estoque> lista = new ArrayList<>();
        ResultSet rs = null;
        con = new Conexao().getConexao();

        try {
            pstm = con.prepareStatement("SELECT * FROM `itens` ORDER BY descricao");
            rs = this.pstm.executeQuery();
            if (rs.next()) {
                do {
                    estoque i = new estoque();
                    i.codItem = rs.getInt("codigo_itens");
                    i.quant = rs.getInt("quantidade");
                    i.nome = rs.getString("nome");
                    i.descricao = rs.getString("descricao");
                    i.valorUni = rs.getFloat("valor_unidade");
                    Blob blob = rs.getBlob("imagem");
                    try {
                        byte[] img = blob.getBytes(1, (int) blob.length());
                        i.imagem = (BufferedImage) ImageIO.read(new ByteArrayInputStream(img));
                    } catch (Exception e) {
                        System.out.println(e);
                    }

                    lista.add(i);

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

    public List<estoque> getFiltrarItens(String filtro) {
        List<estoque> lista = new ArrayList<>();
        ResultSet rs = null;
        filtro = "SELECT * FROM itens where descricao LIKE " + filtro;
        con = new Conexao().getConexao();

        try {
            pstm = con.prepareStatement(filtro);
            rs = this.pstm.executeQuery();
            if (rs.next()) {
                do {
                    estoque i = new estoque();
                    i.codItem = rs.getInt("codigo_itens");
                    i.quant = rs.getInt("quantidade");
                    i.nome = rs.getString("nome");
                    i.descricao = rs.getString("descricao");
                    i.valorUni = rs.getFloat("valor_unidade");
                    Blob blob = rs.getBlob("imagem");
                    try {
                        byte[] img = blob.getBytes(1, (int) blob.length());
                        i.imagem = (BufferedImage) ImageIO.read(new ByteArrayInputStream(img));
                    } catch (Exception e) {
                        System.out.println(e);
                    }

                    lista.add(i);

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

    public void cadastrarItens() { //cadastrar itens
        con = new Conexao().getConexao();

        try {
            pstm = con.prepareStatement("INSERT INTO `itens` (`nome`, `descricao`, `quantidade`, `valor_unidade`, `imagem`) VALUES (?,?,?,?,?)");
            pstm.setString(1, Itens.nome);
            pstm.setString(2, Itens.descricao);
            pstm.setInt(3, Itens.quant);
            pstm.setFloat(4, Itens.valorUni);
            pstm.setBlob(5, FrmAlterarItens.fis, FrmAlterarItens.tam);
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

    public void AtualizarEstoque(int tipo) {
        con = new Conexao().getConexao();

        switch (tipo) {
            case 0: //Encomendas
                try {
                pstm = con.prepareStatement("UPDATE itens SET quantidade = quantidade - ? WHERE codigo_itens = ?");
                pstm.setInt(1, encomendaDados.quantT);
                pstm.setInt(2, encomendaDados.codTecido);
                this.pstm.execute();

                pstm = con.prepareStatement("UPDATE itens SET quantidade = quantidade - ? WHERE codigo_itens = ?");
                pstm.setInt(1, encomendaDados.quantT);
                pstm.setInt(2, encomendaDados.codItens);
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
            break;
            case 1: //Reservas
                try {
                pstm = con.prepareStatement("UPDATE itens SET quantidade = quantidade - ? WHERE codigo_itens = ?");
                pstm.setInt(1, FrmReservar.quant);
                pstm.setInt(2, FrmReservar.cod);
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
            break;
            default: //Atualizações no estoque
                try {
                pstm = con.prepareStatement("UPDATE itens SET nome = ?, descricao = ?, quantidade = ?, valor_unidade = ?, imagem = ? WHERE codigo_itens = ?");
                pstm.setString(1, Itens.nome);
                pstm.setString(2, Itens.descricao);
                pstm.setInt(3, Itens.quant);
                pstm.setFloat(4, Itens.valorUni);
                pstm.setBlob(5, FrmAlterarItens.fis, FrmAlterarItens.tam);
                pstm.setInt(6, Itens.cod);
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
            break;
        }
    }

    public void excluirItens(int id) {
        con = new Conexao().getConexao();

        try {
            pstm = con.prepareStatement("DELETE FROM itens WHERE `itens`.`codigo_itens` = ?");
            pstm.setInt(1, id);
            pstm.executeUpdate();

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

    public void valorT(int id) {
        con = new Conexao().getConexao();
        ResultSet rs = null;

        try {
            pstm = con.prepareStatement("SELECT * FROM itens WHERE `itens`.`codigo_itens` = ?");
            pstm.setInt(1, id);
            rs = this.pstm.executeQuery();

            if (rs.next()) {
                Itens.cod = rs.getInt("codigo_itens");
                Itens.quant = rs.getInt("quantidade");
                Itens.nome = rs.getString("nome");
                Itens.descricao = rs.getString("descricao");
                Itens.valorUni = rs.getFloat("valor_unidade");
                Blob blob = rs.getBlob("imagem");
                try {
                    byte[] img = blob.getBytes(1, (int) blob.length());
                    Itens.imagem = (BufferedImage) ImageIO.read(new ByteArrayInputStream(img));
                } catch (Exception e) {
                    System.out.println(e);
                }
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
}
