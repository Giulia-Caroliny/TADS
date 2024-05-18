package view;

import javax.swing.JOptionPane;

/**
 *
 * @author giuli
 */

/*
String marca = cbxMarca.getSelectedItem().toString(); para pegar o item que foi selecionado
cbxMarca.setSelectedItem("sony");  para printar o que foi selecionado
*/
public class frmPrincipal extends javax.swing.JFrame {

    public frmPrincipal() {
        initComponents();
        this.setExtendedState(MAXIMIZED_BOTH);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        pDesktop = new javax.swing.JDesktopPane();
        MenuBarra = new javax.swing.JMenuBar();
        mCadastrar = new javax.swing.JMenu();
        imNotebook = new javax.swing.JMenuItem();
        imSair = new javax.swing.JMenuItem();
        mRelatorio = new javax.swing.JMenu();
        mUtil = new javax.swing.JMenu();
        imCalculadora = new javax.swing.JMenuItem();
        jSeparator1 = new javax.swing.JPopupMenu.Separator();
        immWindows = new javax.swing.JMenu();
        iimmBlocoNotas = new javax.swing.JMenuItem();
        mSair = new javax.swing.JMenu();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Loja de Notebooks");

        javax.swing.GroupLayout pDesktopLayout = new javax.swing.GroupLayout(pDesktop);
        pDesktop.setLayout(pDesktopLayout);
        pDesktopLayout.setHorizontalGroup(
            pDesktopLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        pDesktopLayout.setVerticalGroup(
            pDesktopLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 277, Short.MAX_VALUE)
        );

        mCadastrar.setText("Cadastrar");

        imNotebook.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_N, java.awt.event.InputEvent.ALT_DOWN_MASK));
        imNotebook.setText("Notebook");
        imNotebook.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                imNotebookActionPerformed(evt);
            }
        });
        mCadastrar.add(imNotebook);

        imSair.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_F4, java.awt.event.InputEvent.ALT_DOWN_MASK));
        imSair.setText("Sair");
        imSair.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                imSairActionPerformed(evt);
            }
        });
        mCadastrar.add(imSair);

        MenuBarra.add(mCadastrar);

        mRelatorio.setText("Relatórios");
        MenuBarra.add(mRelatorio);

        mUtil.setText("Utilidades");

        imCalculadora.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_C, java.awt.event.InputEvent.ALT_DOWN_MASK));
        imCalculadora.setText("Calculadora");
        imCalculadora.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                imCalculadoraActionPerformed(evt);
            }
        });
        mUtil.add(imCalculadora);
        mUtil.add(jSeparator1);

        immWindows.setText("Windows");

        iimmBlocoNotas.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_B, java.awt.event.InputEvent.ALT_DOWN_MASK));
        iimmBlocoNotas.setText("Bloco de Notas");
        iimmBlocoNotas.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                iimmBlocoNotasActionPerformed(evt);
            }
        });
        immWindows.add(iimmBlocoNotas);

        mUtil.add(immWindows);

        MenuBarra.add(mUtil);

        mSair.setText("Sair");
        mSair.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                mSairMouseClicked(evt);
            }
        });
        MenuBarra.add(mSair);

        setJMenuBar(MenuBarra);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(pDesktop)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(pDesktop)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void imNotebookActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_imNotebookActionPerformed
        cadNotebook cadnote = new cadNotebook();
        pDesktop.add(cadnote);
        cadnote.show();
    }//GEN-LAST:event_imNotebookActionPerformed

    private void imSairActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_imSairActionPerformed
        System.exit(0);
    }//GEN-LAST:event_imSairActionPerformed

    private void mSairMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_mSairMouseClicked
        System.exit(0);
    }//GEN-LAST:event_mSairMouseClicked

    private void imCalculadoraActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_imCalculadoraActionPerformed
        Calculadora cal = new Calculadora();
        pDesktop.add(cal);
        cal.show();
    }//GEN-LAST:event_imCalculadoraActionPerformed

    private void iimmBlocoNotasActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_iimmBlocoNotasActionPerformed
        try {
            Runtime.getRuntime().exec("cmd /c start /max notepad.exe");
        } catch (Exception erro) {
            JOptionPane.showMessageDialog(this, "Erro ao abrir Bloco de Notas" + erro);
        }
        
    }//GEN-LAST:event_iimmBlocoNotasActionPerformed

    public static void main(String args[]) {
       
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new frmPrincipal().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuBar MenuBarra;
    private javax.swing.JMenuItem iimmBlocoNotas;
    private javax.swing.JMenuItem imCalculadora;
    private javax.swing.JMenuItem imNotebook;
    private javax.swing.JMenuItem imSair;
    private javax.swing.JMenu immWindows;
    private javax.swing.JPopupMenu.Separator jSeparator1;
    private javax.swing.JMenu mCadastrar;
    private javax.swing.JMenu mRelatorio;
    private javax.swing.JMenu mSair;
    private javax.swing.JMenu mUtil;
    private javax.swing.JDesktopPane pDesktop;
    // End of variables declaration//GEN-END:variables
}
