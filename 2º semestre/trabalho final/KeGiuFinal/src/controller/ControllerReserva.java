/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controller;
import dao.DaoReserva;
import dao.DaoEstoque;
import java.util.List;
import java.util.ArrayList;
import model.reserva;

/**
 *
 * @author giuli
 */
public class ControllerReserva {
    
    DaoReserva dao = new DaoReserva();
    DaoEstoque daoE = new DaoEstoque();
    List<reserva> lista = new ArrayList<>();
    
    public List<reserva> getUpdateReservas() {
        lista.clear();
        lista = dao.getReservas();
        return lista;
    }
    
    public List<reserva> getFiltroReservas(String filtro) {
        lista.clear();
        lista = dao.getFiltrarreserva(filtro);
        return lista;
    }
    
    public void reservar(){
        dao.Reservar();
        daoE.AtualizarEstoque(1);
    }
}
