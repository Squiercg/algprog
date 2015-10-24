package console;

import java.sql.SQLException;
import java.util.Scanner;
import dao.*;
import model.*;

public class Operacoes {
	private String caminho;
	private Scanner entrada;
	private int tipo;
	
	public Operacoes(String caminhoArquivo, int tipo){
		this.caminho = caminhoArquivo;
		this.tipo = tipo;
		entrada = new Scanner(System.in);
	}	
	
	public void Criar(){
		switch(tipo){
			case 1:
				try{					
					CorredorDao corredorDao = new CorredorDao(caminho);
					Corredor corredor = new Corredor();
					System.out.print("Digite o nome: ");
					corredor.setNome(entrada.nextLine());
					System.out.print("Digite o CPF: ");
					corredor.setCpf(entrada.nextLine());
					System.out.print("Digite a data de nascimento(dd/MM/yyyy): ");
					String data[] = new String[3];
					data = entrada.nextLine().split("/");
					corredor.setData_de_nascimento(new Date(Integer.parseInt(data[0]), Integer.parseInt(data[1]), Integer.parseInt(data[2])));
					corredorDao.insert(corredor);
				}
				catch (SQLException e){
					System.out.println("Erro ao executar o comando: " + e.getMessage());
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
		}
	}
	
	public void Listar(){
		switch(tipo){
			case 1:
				try{					
					CorredorDao corredorDao = new CorredorDao(caminho);
					for(Corredor corredor : corredorDao.all()){
						System.out.println(corredor.toString());
					}
				}
				catch (SQLException e){
					System.out.println("Erro ao executar o comando: " + e.getMessage());
				}
				break;
			case 2:
				try{					
					InscricaoDao inscricaoDao = new InscricaoDao(caminho);
					for(Inscricao inscricao : inscricaoDao.all()){
						System.out.println(inscricao.toString());
					}
				}
				catch (SQLException e){
					System.out.println("Erro ao executar o comando: " + e.getMessage());
				}
				break;
			case 3:
				try{					
					CorridaDao corridaDao = new CorridaDao(caminho);
					for(Corrida corrida : corridaDao.all()){
						System.out.println(corrida.toString());
					}
				}
				catch (SQLException e){
					System.out.println("Erro ao executar o comando: " + e.getMessage());
				}
				break;
			case 4:
				try{					
					ModalidadeDao modalidadeDao = new ModalidadeDao(caminho);
					for(Modalidade modalidade : modalidadeDao.all()){
						System.out.println(modalidade.toString());
					}
				}
				catch (SQLException e){
					System.out.println("Erro ao executar o comando: " + e.getMessage());
				}
				break;
		}
	}
	
	public void Remover(){
		switch(tipo){
			case 1:
				try{					
					CorredorDao corredorDao = new CorredorDao(caminho);
					for(Corredor corredor : corredorDao.all()){
						System.out.println(corredor.toString());
					}
					System.out.print("Informe o id para exclusão: ");
					corredorDao.remove(entrada.nextInt());
				}
				catch (SQLException e){
					System.out.println("Erro ao executar o comando: " + e.getMessage());
				}
				break;
			case 2:
				try{					
					InscricaoDao inscricaoDao = new InscricaoDao(caminho);
					for(Inscricao inscricao : inscricaoDao.all()){
						System.out.println(inscricao.toString());
					}
					System.out.print("Informe o id para exclusão: ");
					inscricaoDao.remove(entrada.nextInt());
				}
				catch (SQLException e){
					System.out.println("Erro ao executar o comando: " + e.getMessage());
				}
				break;
			case 3:
				try{					
					CorridaDao corridaDao = new CorridaDao(caminho);
					for(Corrida corrida : corridaDao.all()){
						System.out.println(corrida.toString());
					}
					System.out.print("Informe o id para exclusão: ");
					corridaDao.remove(entrada.nextInt());
				}
				catch (SQLException e){
					System.out.println("Erro ao executar o comando: " + e.getMessage());
				}
				break;
			case 4:
				try{					
					ModalidadeDao modalidadeDao = new ModalidadeDao(caminho);
					for(Modalidade modalidade : modalidadeDao.all()){
						System.out.println(modalidade.toString());
					}
					System.out.print("Informe o id para exclusão: ");
					modalidadeDao.remove(entrada.nextInt());
				}
				catch (SQLException e){
					System.out.println("Erro ao executar o comando: " + e.getMessage());
				}
				break;
		}
	}
	
	public void Atualizar(){
		switch(tipo){
			case 1:
				try{					
					CorredorDao corredorDao = new CorredorDao(caminho);
					for(Corredor corredor : corredorDao.all()){
						System.out.println(corredor.toString());
					}
					String entradaConsole = "";
					System.out.print("Informe o id para atualização: ");
					entradaConsole = entrada.nextLine();
					int id = Integer.parseInt(entradaConsole);
					Corredor corredor = new Corredor();
					System.out.print("Digite o novo nome: ");
					entradaConsole = entrada.nextLine();
					corredor.setNome(entradaConsole.isEmpty() ? null : entradaConsole);
					System.out.print("Digite o novo CPF: ");
					entradaConsole = entrada.nextLine();
					corredor.setCpf(entradaConsole.isEmpty() ? null : entradaConsole);
					System.out.print("Digite a nova data de nascimento(dd/MM/yyyy): ");
					entradaConsole = entrada.nextLine();			
					if(!entradaConsole.isEmpty())
					{
						String data[] = new String[3];
						data = entradaConsole.split("/");
						corredor.setData_de_nascimento(new Date(Integer.parseInt(data[0]), Integer.parseInt(data[1]), Integer.parseInt(data[2])));
					}
					
					corredorDao.update(corredor, id);
				}
				catch (SQLException e){
					System.out.println("Erro ao executar o comando: " + e.getMessage());
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
		}
	}

}
