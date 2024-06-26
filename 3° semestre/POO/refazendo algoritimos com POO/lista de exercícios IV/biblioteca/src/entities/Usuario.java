/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entities;

/**
 *
 * @author giuli
 */
public class Usuario {

    private String nome;
    private String matricula;
    private int idade;

    /**
     * Construtor - Parâmetros: String, String e int
     *
     * @param nome String - nome do Usuário
     * @param matricula String - matrícula do Usuário
     * @param idade int - idade do Usuário
     */
    public Usuario(String nome, String matricula, int idade) {
        this.nome = nome;
        this.matricula = matricula;
        this.idade = idade;
    }

    /**
     * Método get do atributo nome
     *
     * @return String - nome do Usuário
     */
    public String getNome() {
        return nome;
    }

    /**
     * Método set do atributo nome
     *
     * @param nome String - nome a ser atribuído
     */
    public void setNome(String nome) {
        this.nome = nome;
    }

    /**
     * Método get do atributo matricula
     *
     * @return String - matricula do usuário
     */
    public String getMatricula() {
        return matricula;
    }

    /**
     * Método set do atributo matricula
     *
     * @param matricula String - matrícula a ser atribuída
     */
    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    /**
     * Método get do atributo idade
     *
     * @return int - idade do usuário
     */
    public int getIdade() {
        return idade;
    }

    /**
     * Método set do atributo idade
     *
     * @param idade int - idade a ser atribuída
     */
    public void setIdade(int idade) {
        this.idade = idade;
    }
}
