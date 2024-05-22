/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controller;

import dao.DaoNotebook;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JOptionPane;
import model.Notebook;

/**
 *
 * @author Afranio
 */
public class ControllerNotebook {
    DaoNotebook dao = new DaoNotebook();
    List<Notebook> lista= new ArrayList<Notebook>();
    public void inserirNotebook(Notebook n)
    {
        if(!n.modelo.equals("") && n.marca!=null && !n.serie.equals(""))
        {
            //dao.salvarNotebook(n);
            JOptionPane.showMessageDialog(null,"Notebook salvo com sucesso!!!");
        }
        else
        {
            JOptionPane.showMessageDialog(null, "Todos os campos devem ser preenchidos");
        }
    }
    
     public void alterarNotebook(Notebook n)
    {
        if(!n.modelo.equals("") && n.marca!=null && !n.serie.equals("") && n.id!=0)
        {
            //dao.editarNotebook(n);
            JOptionPane.showMessageDialog(null,"Notebook salvo com sucesso!!!");
        }
        else
        {
            JOptionPane.showMessageDialog(null, "Todos os campos devem ser preenchidos");
        }
    }
     
     public void delNotebook(int id)
    {
        int op = JOptionPane.showConfirmDialog(null, "Você tem certeza que quer excluir o notebook"+id,"Certeza?",JOptionPane.YES_NO_OPTION);
       switch(op)
       {
           case 0:
               //dao.excluirNotebook(id);
               JOptionPane.showMessageDialog(null, "Excluído com sucesso!!!");
                            
               break;
           case 1:
               JOptionPane.showMessageDialog(null, "Exclusão cancelada");
               break;
       }
    } 
    public List<Notebook> getUpdateNotebooks()
    {
        lista.clear();
        lista = dao.getNotebooks();
        return lista;
    }
}
