package struct3;
import java.util.Scanner;
import model.Funcionario;

public class atividade3 {
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        Funcionario[] funcionarios = new Funcionario[2];
        double mediaF = 0;
        int contF = 0;
        int contM = 0;
        
        for (int i = 0; i < funcionarios.length; i++) {
            
            Funcionario funcionario = new Funcionario();
            System.out.println("Funcionário " + (i + 1));
            
            System.out.print("Nome: ");
            funcionario.nome = scanner.next();
            
            System.out.print("Sexo (M/F): ");
            funcionario.sexo = scanner.next();
            
            System.out.print("CPF: ");
            funcionario.cpf = scanner.next();
            
            System.out.print("Idade: ");
            funcionario.idade = scanner.nextInt();
            
            System.out.print("Salário: ");
            funcionario.salario = scanner.nextFloat();

            funcionarios[i] = funcionario;
            
            if( "F".equals(funcionarios[i].sexo) || "f".equals(funcionarios[i].sexo)){
                mediaF += funcionarios[i].idade;
                contF += 1;
            }
            if( "M".equals(funcionarios[i].sexo) || "m".equals(funcionarios[i].sexo)){
                contM += 1;}
        }

        Funcionario maisVelho = funcionarios[0];
        for (int i = 1; i < funcionarios.length; i++) {
            if (funcionarios[i].idade > maisVelho.idade) {
                maisVelho = funcionarios[i];
            }
        }
        
        System.out.println("Funcionário mais velho: " + maisVelho.nome);
        
        mediaF /= contF;
        System.out.println("A média é: " + mediaF);
        System.out.println("A quantidade de homens é:" +contM);
        
        Funcionario maiorSalario = funcionarios[0];
        
        for (int i = 1; i < funcionarios.length; i++) {
            if (funcionarios[i].salario > maiorSalario.salario) {
                maiorSalario = funcionarios[i];
            }
        }
        
        System.out.println("Funcionário com maior salário: " + maiorSalario.nome);
    }
}