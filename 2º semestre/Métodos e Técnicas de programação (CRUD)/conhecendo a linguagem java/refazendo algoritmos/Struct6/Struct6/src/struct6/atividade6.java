package struct6;
import java.util.Scanner;
import model.Salario.Endereco;
import model.Salario.Cadastro;

public class atividade6 {
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        Cadastro[] cadastros = new Cadastro[7];
        int pessoaMaiorIdade = 0;
        int contadorMasculino = 0;
        int contadorSalarioMaior1000 = 0;
        int identidadeBusca;

        
        for (int i = 0; i < 7; i++) {
            cadastros[i] = new Cadastro();

            System.out.println("Entre com os dados do cadastro " + (i + 1) + ":");
            
            System.out.print("Nome: ");
            cadastros[i].nome = scanner.nextLine();

            System.out.print("Salario: ");
            cadastros[i].salario = scanner.nextFloat();
            scanner.nextLine();

            cadastros[i].endereco = new Endereco();
            
            System.out.println("Endereco:");
            
            System.out.print("Rua: ");
            cadastros[i].endereco.rua = scanner.nextLine();
            
            System.out.print("Bairro: ");
            cadastros[i].endereco.bairro = scanner.nextLine();
            
            System.out.print("CEP: ");
            cadastros[i].endereco.cep = scanner.nextLine();
            
            System.out.print("Cidade: ");
            cadastros[i].endereco.cidade = scanner.nextLine();
            
            System.out.print("Estado: ");
            cadastros[i].endereco.estado = scanner.nextLine();

            System.out.print("Identidade: ");
            cadastros[i].identidade = scanner.nextInt();
            scanner.nextLine();

            System.out.print("CPF: ");
            cadastros[i].cpf = scanner.nextLine();
            
            System.out.print("Estado Civil: ");
            cadastros[i].estadoCivil = scanner.nextLine();
            
            System.out.print("Telefone: ");
            cadastros[i].telefone = scanner.nextLine();
            
            System.out.print("Idade: ");
            cadastros[i].idade = scanner.nextInt();
            scanner.nextLine();
            
            System.out.print("Sexo (M/F): ");
            cadastros[i].sexo = scanner.next().charAt(0);

            System.out.println();
        }

        for (int i = 1; i < 7; i++) {
            if (cadastros[i].idade > cadastros[pessoaMaiorIdade].idade) {
                pessoaMaiorIdade = i;
            }
        }

        for (int i = 0; i < 7; i++) {
            if (cadastros[i].sexo == 'M' || cadastros[i].sexo == 'm') {
                contadorMasculino++;
            }
        }

        for (int i = 0; i < 7; i++) {
            if (cadastros[i].salario > 1000) {
                contadorSalarioMaior1000++;
            }
        }

        System.out.println("\nPessoa com maior idade:");
        System.out.println("Nome: " + cadastros[pessoaMaiorIdade].nome);
        System.out.println("Identidade: " + cadastros[pessoaMaiorIdade].identidade);

        System.out.println("\nPessoas do sexo masculino: " + contadorMasculino);
        System.out.println("Pessoas com salario maior que 1000: " + contadorSalarioMaior1000);

        System.out.print("\nDigite a identidade da pessoa a ser buscada: ");
        identidadeBusca = scanner.nextInt();
        boolean encontrou = false;

        for (Cadastro cadastro : cadastros) {
            
            if (cadastro.identidade == identidadeBusca) {
                System.out.println("Pessoa encontrada:");
                System.out.println("Nome: " + cadastro.nome);
                System.out.println("Salario: " + cadastro.salario);
                encontrou = true;
                break;
            }
        }

        if (!encontrou) {
            System.out.println("Pessoa com identidade " + identidadeBusca + " não encontrada.");
        }
    }
}