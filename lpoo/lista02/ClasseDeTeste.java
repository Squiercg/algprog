import java.util.Scanner;
import javax.swing.JOptionPane;

public class ClasseDeTeste {
    public static void main(String[] args) {
	Funcionario funcionario = new Funcionario();
	/*
	funcionario.nome = "Zorobabel";
	funcionario.departamento = "FACOM";
	funcionario.salario = 1500;
	funcionario.dataEntrada = "15/08/1987";
	funcionario.rg = "12332112 SSP/MS";
	*/

	//	Scanner scanner = new Scanner(System.in);
	//	System.out.println("Digite um nome:");
	//	funcionario.nome=scanner.nextLine();


	funcionario.departamento = JOptionPane.showInputDialog("Digite o Nome");
	funcionario.departamento = JOptionPane.showInputDialog("Digite o Departamento");
	funcionario.departamento = JOptionPane.showInputDialog("Digite o Salario");
	funcionario.departamento = JOptionPane.showInputDialog("Digite a data de Entrada");
	funcionario.departamento = JOptionPane.showInputDialog("Digite o rg");

	Data data = new Data(26,05,2014);
	System.out.println(data);

	System.out.println("Nome: "+funcionario.nome + " da " + funcionario.departamento);
	JOptionPane.showMessageDialog(null,"departamento " + funcionario.departamento);

    }
}