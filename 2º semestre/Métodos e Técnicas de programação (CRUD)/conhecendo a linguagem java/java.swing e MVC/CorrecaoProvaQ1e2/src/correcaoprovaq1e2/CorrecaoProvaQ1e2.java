package correcaoprovaq1e2;
import model.Tarefa;
import javax.swing.JOptionPane;


/**
 *
 * @author giuli
 */
public class CorrecaoProvaQ1e2 {

    public static void main(String[] args) {
        Tarefa[] task = new Tarefa[10];
        int op;
        int ID;
        int i = 0;
        op = Integer.parseInt(JOptionPane.showInputDialog(null,"1 - Adicionar nova tarefa.\n2 - Marcar tarefa como conluída.\n3 - Imprimir tarefas em abereto.\n4 - Sair."));
        switch(op){
            case 1:
                task[i] = new Tarefa();
                task[i].ID = Integer.parseInt(JOptionPane.showInputDialog(null,"ID da tarefa."));
                task[i].descricao = JOptionPane.showInputDialog(null,"Descrição da tarefa.");
                task[i].horaInicio = Integer.parseInt(JOptionPane.showInputDialog(null,"Horário de início da tarefa."));
                task[i].horaFim = Integer.parseInt(JOptionPane.showInputDialog(null,"Horário de enceramento da tarefa."));
                i++;
            break;
            case 2:
                int n;
                ID = Integer.parseInt(JOptionPane.showInputDialog(null,"ID da tarefa."));
                n = JOptionPane.showConfirmDialog(null,"Você tem certeza?", "Concluir tarefa", JOptionPane.YES_NO_OPTION);
                
                switch(n){
                    case 0:
                        for(int e = 0; e < 10; e++)
                        {
                            if(ID == task[e].ID) task[e].concluida = true;
                        }
                    break;
                    case 1:
                    break;
                }
            break;
            case 3:
                for(int e = 0; e < 10; e++)
                {
                    if(task[e].concluida == false) JOptionPane.showMessageDialog(null, "Descrição da tarefa: " + task[e].descricao);
                }
            break;
            case 4:
            break;
            default:
                JOptionPane.showMessageDialog(null,"Opção inválida.", "ERRO", JOptionPane.ERROR_MESSAGE);
            break;
        }
    }
    
}
