package controller;

import dao.DaoMarca;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JOptionPane;
import model.Marca;

/**
 *
 * @author giulia
 */
public class ControllerMarca {
    DaoMarca dao = new DaoMarca();
    List<Marca> lista=  new ArrayList<Marca>();
    List<String> marcas= new ArrayList<String>();
    
    public void inserirMarca(Marca m)
    {
        if(!m.descricao.equals(""))
        {
            dao.salvarMarca(m);
            JOptionPane.showMessageDialog(null,"Marca salvo com sucesso!!!");
        }
        else
        {
            JOptionPane.showMessageDialog(null, "Todos os campos devem ser preenchidos");
        }
    }
    
     public void alterarMarca(Marca m)
    {
        if(!m.descricao.equals("") && m.id!=0)
        {
            dao.editarMarca(m);
            JOptionPane.showMessageDialog(null,"Marca alterada com sucesso!!!");
        }
        else
        {
            JOptionPane.showMessageDialog(null, "Todos os campos devem ser preenchidos");
        }
    }
     
     public void delMarca(int id)
    {
        int op = JOptionPane.showConfirmDialog(null, "Você tem certeza que quer excluir a marca"+id,"Certeza?",JOptionPane.YES_NO_OPTION);
       switch(op)
       {
           case 0:
               dao.excluirMarca(id);
               JOptionPane.showMessageDialog(null, "Excluído com sucesso!!!");
                            
               break;
           case 1:
               JOptionPane.showMessageDialog(null, "Exclusão cancelada");
               break;
       }
    } 
    public List<Marca> getUpdateMarcas()
    {
        lista.clear();
        lista = dao.getMarcas();
        return lista;
    }
    public List<String> carregaCombo()
    {
        marcas.clear();
        marcas = dao.carregaComboBox();
        return marcas;
    }
    public int getIdMarcaByDescricao(String descricao)
    {
          return dao.getIdMarcaByDescricao(descricao);
    }
    public String getDescricaoMarcaById(int id)
    {
         return dao.getDescricaoMarcaById(id);
    }
}
