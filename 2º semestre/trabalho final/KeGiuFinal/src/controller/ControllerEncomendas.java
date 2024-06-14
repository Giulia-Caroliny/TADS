/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controller;

import dao.DaoEncomenda;
import dao.DaoEstoque;

/**
 *
 * @author giuli
 */
public class ControllerEncomendas {
      
    DaoEncomenda dao = new DaoEncomenda();
    DaoEstoque daoE = new DaoEstoque();
    
    
    public void FinalizarEncomenda() {
        dao.Encomendar();
        daoE.AtualizarEstoque(0);        
    }
    
}
