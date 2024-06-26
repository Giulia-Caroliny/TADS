/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entities;

/**
 *
 * @author giuli
 */
public class Revista extends ItemBiblioteca {

    private String mancheteCapa;
    private String mesAno;

    public String getMancheteCapa() {
        return mancheteCapa;
    }

    public void setMancheteCapa(String mancheteCapa) {
        this.mancheteCapa = mancheteCapa;
    }

    public String getMesAno() {
        return mesAno;
    }

    public void setMesAno(String mesAno) {
        this.mesAno = mesAno;
    }

    @Override
    public void exibir() {
        System.out.println("Revista: "
                + super.getTitulo()
                + "\nEditora: "
                + super.getEditora()
                + "\nManchete: "                
                + mancheteCapa
                + "\nMês/ano: "
                + mesAno);
    }
}
