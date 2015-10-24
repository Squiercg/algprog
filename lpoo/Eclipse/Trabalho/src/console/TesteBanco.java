package console;

import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class TesteBanco {
	private static Scanner entrada;
	private static String caminho;
	
	public static void main(String[] args) {
		// Crio o file para pegar o banco dinamicamente a partir do workspace
		File file = new File("TesteBanco.java");  
        caminho = file.getAbsolutePath().replaceAll("TesteBanco.java", "data/corridas.sqlite").replaceAll("\\\\", "/");
		
        int opcaoMenu = 0;
        while(opcaoMenu != 5)
        {
        	opcaoMenu = ListaMenuPrincipal();
        	switch(opcaoMenu)
        	{
        		default:
        			break;
        		case 1:
        			Operacoes(opcaoMenu);
        			break;
        		case 2:
        			Operacoes(opcaoMenu);
        			break;
        		case 3:
        			Operacoes(opcaoMenu);
        			break;
        		case 4:
        			Operacoes(opcaoMenu);
        			break;
        		case 5:
        			break;
        	}        	
        }
	}
	
	public static int ListaMenuPrincipal(){
		System.out.println(">> Menu Principal <<\n");
		System.out.println("1 - Corredores");
		System.out.println("2 - Inscrições");
		System.out.println("3 - Corridas");
		System.out.println("4 - Modalidades");
		System.out.println("5 - Sair");
		System.out.print("Opção: ");
		
		entrada = new Scanner(System.in);
		int op = entrada.nextInt();
		return op;
	}
	
	public static int ListaMenuOperacoes(int tipo){
		ArrayList<String> tipos = new ArrayList<String>();
		tipos.add("Corredores");
		tipos.add("Inscrições");
		tipos.add("Corridas");
		tipos.add("Modalidades");
		
		System.out.println(">> Menu de " + tipos.get(tipo-1) + " <<\n");
		System.out.println("1 - Criar");
		System.out.println("2 - Editar");
		System.out.println("3 - Listar");
		System.out.println("4 - Remover");
		System.out.println("0 - Voltar");
		System.out.print("Opção: ");
		
		int opcao = entrada.nextInt();
		return opcao;
	}
	
	public static void Operacoes(int tipo){
		int op = -1;
		Operacoes operacao = new Operacoes(caminho, tipo);
		while(op != 0){
			op = ListaMenuOperacoes(tipo);
			switch(op){
				default:
					break;
				case 1:
					operacao.Criar();
					break;
				case 2:
					operacao.Atualizar();
					break;
				case 3:
					operacao.Listar();
					break;
				case 4:
					operacao.Remover();
					break;
				case 0:
					break;			
			}
		}
	}	
}
