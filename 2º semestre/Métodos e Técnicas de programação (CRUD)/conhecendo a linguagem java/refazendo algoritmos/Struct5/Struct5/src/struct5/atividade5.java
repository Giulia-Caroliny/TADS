package struct5;
import java.util.Scanner;
import model.Aluno;

public class atividade5 {
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        Aluno[] alunos = new Aluno[5];
        int alunoMaiorNotaProva1 = 0;
        int alunoMaiorMediaGeral = 0;
        int alunoMenorMediaGeral = 0;

        for (int i = 0; i < 5; i++) {
            alunos[i] = new Aluno();

            System.out.println("Entre com os dados do aluno " + (i + 1) + ":");
            System.out.print("Matrícula: ");
            alunos[i].matricula = scanner.nextInt();

            scanner.nextLine();

            System.out.print("Nome: ");
            alunos[i].nome = scanner.nextLine();

            System.out.print("Nota da primeira prova: ");
            alunos[i].notaProva1 = scanner.nextFloat();

            System.out.print("Nota da segunda prova: ");
            alunos[i].notaProva2 = scanner.nextFloat();

            System.out.print("Nota da terceira prova: ");
            alunos[i].notaProva3 = scanner.nextFloat();

            alunos[i].mediaGeral = (alunos[i].notaProva1 + alunos[i].notaProva2 + alunos[i].notaProva3) / 3;

            System.out.println();
        }

        for (int i = 1; i < 5; i++) {
            if (alunos[i].notaProva1 > alunos[alunoMaiorNotaProva1].notaProva1) {
                alunoMaiorNotaProva1 = i;
            }
        }

        for (int i = 1; i < 5; i++) {
            if (alunos[i].mediaGeral > alunos[alunoMaiorMediaGeral].mediaGeral) {
                alunoMaiorMediaGeral = i;
            }
        }

        for (int i = 1; i < 5; i++) {
            if (alunos[i].mediaGeral < alunos[alunoMenorMediaGeral].mediaGeral) {
                alunoMenorMediaGeral = i;
            }
        }

        System.out.println("\nRegistro dos alunos:");
        for (int i = 0; i < 5; i++) {
            System.out.println("Aluno: " + alunos[i].nome);
            System.out.println("Matrícula: " + alunos[i].matricula);
            System.out.println("Média Geral: " + alunos[i].mediaGeral);

            if (alunos[i].mediaGeral >= 7) {
                System.out.println("Situação: Aprovado");
            } else {
                System.out.println("Situação: Reprovado");
            }

            System.out.println();
        }

        System.out.println("Aluno com maior nota na primeira prova:");
        System.out.println("Nome: " + alunos[alunoMaiorNotaProva1].nome);
        System.out.println("Matricula: " + alunos[alunoMaiorNotaProva1].matricula);

    }
}