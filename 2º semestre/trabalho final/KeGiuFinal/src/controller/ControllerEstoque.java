/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controller;

import dao.DaoEstoque;
import java.util.ArrayList;
import java.util.List;
import model.estoque;

/**
 *
 * @author giuli
 */
public class ControllerEstoque {
      
    DaoEstoque dao = new DaoEstoque();
    List<estoque> lista = new ArrayList<>();
    
    public List<estoque> getUpdateItens() {
        lista.clear();
        lista = dao.getItens();
        return lista;
    }
    
    public void buscarValorT (int cod){
        dao.valorT(cod);
    }
    
    public List<estoque> getFiltrarI(String filtro) {
        lista.clear();
        lista = dao.getFiltrarItens(filtro);
        return lista;
    }  
    
    public void deletarItem (int id){
        dao.excluirItens(id);
    }
    
    public void salvarItem (){
        dao.cadastrarItens();
    }
    
    public void atualizar(int tipo){
        dao.AtualizarEstoque(tipo);
    }
    
}
