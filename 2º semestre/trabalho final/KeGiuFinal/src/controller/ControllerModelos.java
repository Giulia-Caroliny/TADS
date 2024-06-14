/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controller;

import dao.DaoModelos;
import java.util.ArrayList;
import java.util.List;
import model.modelos;

/**
 *
 * @author giuli
 */
public class ControllerModelos {
      
    DaoModelos dao = new DaoModelos();
    List<modelos> lista = new ArrayList<>();
        
    public List<modelos> getUpdateModelos() {
        lista.clear();
        lista = dao.getModelos();
        return lista;
    }
    
    public List<modelos> getFiltrarModelos(String filtros) {
        lista.clear();
        lista = dao.getFiltrarModelos(filtros);
        return lista;
    }
    
    public void encomendando(){
        dao.getOModelo();
    }
    
    public modelos valor(String tam){
        return dao.getOModelo2(tam);
    }
    
}
