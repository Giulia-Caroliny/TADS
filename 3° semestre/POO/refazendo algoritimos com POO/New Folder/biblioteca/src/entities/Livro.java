/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entities;

/**
 *
 * @author giuli
 */
public class Livro extends ItemBiblioteca implements Emprestavel {

    private String autor;
    private int ano;
    private boolean disponivel;

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    @Override
    public void exibir() {
        System.out.println("Livro: "
                + super.getTitulo()
                + "\nAutor: "
                + autor
                + "\nEditora: "
                + super.getEditora()
                + "\nAno: "
                + ano
                + "\nDisponível: "
                + ((disponivel) ? "sim" : "não"));
    }

    @Override
    public void emprestarItem() {
        disponivel = false;
    }

    @Override
    public void devolverItem() {
        disponivel = true;
    }
}
