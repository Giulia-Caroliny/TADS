package model;

public class Usuario {
public int id;
public String nome;
public String email;
public String senha;

public void cadastrarUsuario(int i,String n,String e,String s)
{
    id = i;
    nome = n;
    email = e;
    senha = s;
}
}
