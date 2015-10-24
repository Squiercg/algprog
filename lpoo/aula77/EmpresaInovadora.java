package aula77;

import java.util.ArrayList;

public class EmpresaInovadora {

	private ArrayList<Funcionario> funcionarios;
	private String nome;
	private String cnpj;
	private static int count = 0;

	public EmpresaInovadora
	(
		String nome,
		String cnpj
	) {
		funcionarios = 
		new ArrayList<Funcionario>();
		this.nome = nome;
		this.cnpj = cnpj;
	}

	public void adiciona (Funcionario f) {
		funcionarios.add(f);
		count++;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCnpj() {
		return cnpj;
	}

	public void setCnpj(String cnpj) {
		this.cnpj = cnpj;
	}

	public static int getCount() {
		return count;
	}	
}