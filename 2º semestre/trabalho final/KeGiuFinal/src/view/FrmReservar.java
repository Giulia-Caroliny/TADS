/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JInternalFrame.java to edit this template
 */
package view;

import controller.ControllerEstoque;
import controller.ControllerReserva;
import java.awt.Image;
import java.util.List;
import javax.swing.ImageIcon;
import javax.swing.JOptionPane;
import static javax.swing.JOptionPane.YES_NO_OPTION;
import javax.swing.plaf.basic.BasicInternalFrameUI;
import javax.swing.table.DefaultTableModel;
import model.estoque;


/**
 *
 * @author giuli
 */
public class FrmReservar extends javax.swing.JInternalFrame {
    
    static ControllerEstoque controller = new ControllerEstoque();
    private static List <estoque> listaItens;
    public static int cod;
    public static int quant;
    
    private static String filtro;

    /**
     * Creates new form FrmReservar
     */
    public FrmReservar() {
        initComponents();
        
        preencherTabelas();
        
        lblValorFinal.setText("0,00");
        
        BasicInternalFrameUI bui = (BasicInternalFrameUI) this.getUI();
        bui.setNorthPane(null);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        lblReservar = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jtReservaItens = new javax.swing.JTable();
        cbxFiltro = new javax.swing.JComboBox<>();
        btnFiltrar = new javax.swing.JButton();
        lblItem = new javax.swing.JLabel();
        lblQuantidade = new javax.swing.JLabel();
        txtItem = new javax.swing.JTextField();
        cbxQtde = new javax.swing.JComboBox<>();
        btnSalvar = new javax.swing.JButton();
        lblImagemItem = new javax.swing.JLabel();
        btnCancelar = new javax.swing.JButton();
        lblImagem = new javax.swing.JLabel();
        lblValor = new javax.swing.JLabel();
        lblValorFinal = new javax.swing.JLabel();

        setMaximumSize(new java.awt.Dimension(539, 418));
        setMinimumSize(new java.awt.Dimension(539, 418));
        setPreferredSize(new java.awt.Dimension(539, 418));
        getContentPane().setLayout(null);

        lblReservar.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        lblReservar.setText("Reservar materiais");
        getContentPane().add(lblReservar);
        lblReservar.setBounds(77, 6, 220, 20);

        jtReservaItens.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null}
            },
            new String [] {
                "Foto", "Item", "Valor unitário"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jtReservaItens.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                jtReservaItensMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(jtReservaItens);

        getContentPane().add(jScrollPane1);
        jScrollPane1.setBounds(34, 40, 348, 174);

        cbxFiltro.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "--Selecionar--", "Tecido", "Agulha", "Botão", "Linha", "Colas/Adesivos", "Fitas", "Paêtes/Lantejoulas", "Bastidor", "Viés", "Ziper", "Outros" }));
        getContentPane().add(cbxFiltro);
        cbxFiltro.setBounds(402, 70, 110, 22);

        btnFiltrar.setText("Filtrar");
        btnFiltrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnFiltrarActionPerformed(evt);
            }
        });
        getContentPane().add(btnFiltrar);
        btnFiltrar.setBounds(423, 103, 72, 23);

        lblItem.setText("Item:");
        getContentPane().add(lblItem);
        lblItem.setBounds(178, 257, 27, 16);

        lblQuantidade.setText("Quantidade:");
        getContentPane().add(lblQuantidade);
        lblQuantidade.setBounds(178, 306, 65, 16);
        getContentPane().add(txtItem);
        txtItem.setBounds(231, 254, 110, 22);

        cbxQtde.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "1", "2", "3", "4", "5", "10", "20", "30", "40", "50" }));
        getContentPane().add(cbxQtde);
        cbxQtde.setBounds(269, 300, 72, 22);

        btnSalvar.setText("Salvar Pedido");
        btnSalvar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnSalvarActionPerformed(evt);
            }
        });
        getContentPane().add(btnSalvar);
        btnSalvar.setBounds(382, 254, 120, 23);
        getContentPane().add(lblImagemItem);
        lblImagemItem.setBounds(30, 230, 130, 130);

        btnCancelar.setText("Cancelar");
        btnCancelar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCancelarActionPerformed(evt);
            }
        });
        getContentPane().add(btnCancelar);
        btnCancelar.setBounds(382, 299, 120, 23);

        lblImagem.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagens/reservar.png"))); // NOI18N
        getContentPane().add(lblImagem);
        lblImagem.setBounds(30, 200, 170, 190);

        lblValor.setText("Valor: ");
        getContentPane().add(lblValor);
        lblValor.setBounds(400, 200, 37, 16);
        getContentPane().add(lblValorFinal);
        lblValorFinal.setBounds(440, 200, 70, 16);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnCancelarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCancelarActionPerformed
        if (JOptionPane.showConfirmDialog(this, "Deseja descartar as alterações feitas?", "Cancelar reserva", YES_NO_OPTION) == JOptionPane.YES_OPTION) {
            this.dispose();
        }
    }//GEN-LAST:event_btnCancelarActionPerformed

    private void btnFiltrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnFiltrarActionPerformed
        filtro = "'%" + cbxFiltro.getSelectedItem().toString() +"%'";
        
        switch (filtro) {
            case "'--Selecionar--'" -> JOptionPane.showMessageDialog(this, "Selecione um filtro.");
            case "'Tudo'" -> preencherTabelas();
            default -> preencherTabelasFiltro(filtro);
        }
    }//GEN-LAST:event_btnFiltrarActionPerformed

    private void jtReservaItensMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jtReservaItensMouseClicked
        Float valor = listaItens.get(jtReservaItens.getSelectedRow()).valorUni;
        int quanti = Integer.parseInt(cbxQtde.getSelectedItem().toString());
        
        txtItem.setText(listaItens.get(jtReservaItens.getSelectedRow()).nome);
        lblValorFinal.setText(String.valueOf((Math.round(quanti * valor * 100)) / 100));
        
        try {
            lblImagemItem.setIcon(new ImageIcon((Image) listaItens.get(jtReservaItens.getSelectedRow()).imagem));            
        } catch (Exception e) {
            System.out.println(e);
        }
    }//GEN-LAST:event_jtReservaItensMouseClicked

    private void btnSalvarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnSalvarActionPerformed
        ControllerReserva controllerR = new ControllerReserva();
        
        cod = listaItens.get(jtReservaItens.getSelectedRow()).codItem;
        quant = Integer.parseInt(cbxQtde.getSelectedItem().toString());
        
        controllerR.reservar();
    }//GEN-LAST:event_btnSalvarActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnCancelar;
    private javax.swing.JButton btnFiltrar;
    private javax.swing.JButton btnSalvar;
    private javax.swing.JComboBox<String> cbxFiltro;
    private javax.swing.JComboBox<String> cbxQtde;
    private javax.swing.JScrollPane jScrollPane1;
    private static javax.swing.JTable jtReservaItens;
    private javax.swing.JLabel lblImagem;
    private javax.swing.JLabel lblImagemItem;
    private javax.swing.JLabel lblItem;
    private javax.swing.JLabel lblQuantidade;
    private javax.swing.JLabel lblReservar;
    private javax.swing.JLabel lblValor;
    private static javax.swing.JLabel lblValorFinal;
    private javax.swing.JTextField txtItem;
    // End of variables declaration//GEN-END:variables

    private static void preencherTabelas (){
        DefaultTableModel tabelas = (DefaultTableModel) jtReservaItens.getModel();
        tabelas.setNumRows(0);
        
        listaItens = controller.getUpdateItens();
                
        Object colunas[] = new Object[3];
                
        for (int i = 0; i < listaItens.size(); i++) {
                                   
            colunas[0] = listaItens.get(i).imagem;
            colunas[1] = listaItens.get(i).nome;
            colunas[2] = listaItens.get(i).valorUni;
            
            tabelas.addRow(colunas);
        }
    }
    
    private static void preencherTabelasFiltro (String filtro){
        DefaultTableModel tabelas = (DefaultTableModel) jtReservaItens.getModel();
        tabelas.setNumRows(0);
        
        listaItens = controller.getFiltrarI(filtro);
                
        Object colunas[] = new Object[3];
                
        for (int i = 0; i < listaItens.size(); i++) {
                                   
            colunas[0] = listaItens.get(i).imagem;
            colunas[1] = listaItens.get(i).nome;
            colunas[2] = listaItens.get(i).valorUni;
            
            tabelas.addRow(colunas);
        }
    }
}
