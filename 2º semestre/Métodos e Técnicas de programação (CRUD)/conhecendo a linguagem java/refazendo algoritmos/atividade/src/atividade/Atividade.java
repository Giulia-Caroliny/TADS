package atividade;

import model.Aluno;
import java.util.Scanner;
public class Atividade {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Aluno alunos[] = new Aluno[3];
        float media, somaMedia = 0, mediaTurma;
        
        for(int i = 0; i < 3; i ++){
            alunos[i] = new Aluno();
            
            System.out.println("Digite seu nome:");
            alunos[i].nome = sc.next();

            System.out.println("Insira a 1ª nota:");
            alunos[i].nota1 = sc.nextFloat();

            System.out.println("Insira a 2ª nota:");
            alunos[i].nota2 = sc.nextFloat();

            System.out.println("Insira a 3ª nota:");
            alunos[i].nota3 = sc.nextFloat();
            
        }
        
        for(int i = 0; i < 3; i++){
            alunos[i] = new Aluno();
            media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3)/3;
            somaMedia =+ media;

            if(media >= 6) System.out.println("O aluno " + alunos[i].nome + " foi aprovado!");
            else if(media < 6 && media >= 4) System.out.println("O aluno " + alunos[i].nome + " precisa de recuperação.");
            else System.out.println("O aluno " + alunos[i].nome + " foi reprovado.");
            
            System.out.println("Sua média foi: " + media);
        }
        
        mediaTurma = somaMedia/3;
        System.out.println("A média da turma é " + mediaTurma);
        
        sc.close();
    }
    
}
