package aula77;

public class Funcionario {
	private String nome;
	private String cpf;
	private Float salario;

	public Funcionario
	(
		String nome, 
		String cpf, 
		Float salario) 
	{
		setNome(nome);
		setCpf(cpf);
		setSalario(salario);
	}
	public Funcionario(Funcionario funcionario) {
		nome = funcionario.nome;
		cpf = funcionario.cpf;
		salario = funcionario.salario;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public void setSalario(Float salario) {
		this.salario = salario;
	}

	public String getNome() {
		return nome;
	}

	public String getCpf() {
		return cpf;
	}

	public Float getSalario() {
		return salario;
	}
}