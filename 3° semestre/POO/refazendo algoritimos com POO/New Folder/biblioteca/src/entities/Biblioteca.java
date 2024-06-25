/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entities;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author giuli
 */
public class Biblioteca {

    private String nome;
    private String horarioFuncionamento;
    private List<ItemBiblioteca> itens;

    public Biblioteca(String nome, String horarioFuncionamento) {
        this.nome = nome;
        this.horarioFuncionamento = horarioFuncionamento;
        this.itens = new ArrayList<>();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getHorarioFuncionamento() {
        return horarioFuncionamento;
    }

    public void setHorarioFuncionamento(String horarioFuncionamento) {
        this.horarioFuncionamento = horarioFuncionamento;
    }

    public boolean inserirItem(ItemBiblioteca item) {
        return itens.add(item);
    }

    public ItemBiblioteca consultarItem(String titulo) {
        for (ItemBiblioteca item : itens) {
            if (item.getTitulo().equals(titulo)) {
                return itens.get(itens.indexOf(item));
            }
        }
        return null;
    }

    public boolean excluirItem(String titulo) {
        for (ItemBiblioteca item : itens) {
            if (item.getTitulo().equals(titulo)) {
                return itens.remove(item);
            }
        }
        return false;
    }

    public void atualizarItem(String titulo, ItemBiblioteca itemAtualizado) {
        for (ItemBiblioteca item : itens) {
            if (item.getTitulo().equals(titulo)) {
                itens.remove(item);
                itens.add(itemAtualizado);
            }
        }
    }
}
