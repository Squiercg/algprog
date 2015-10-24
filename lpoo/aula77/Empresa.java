package aula77;

public class Empresa {

	private Funcionario[] funcionarios;
	private String nome;
	private String cnpj;
	private int count;

	public Empresa
	(
		int quantidadeDeFuncionarios,
		String nome,
		String cnpj
	) {
		funcionarios = 
		new Funcionario[quantidadeDeFuncionarios];
		this.nome = nome;
		this.cnpj = cnpj;
		this.count = 0;
	}

	public boolean adiciona (Funcionario f) {
		if(count < funcionarios.length) {
			funcionarios[count] = f;
			count++;
			return true;
		}
		return false;
	}

	public Funcionario[] getFuncionarios() {
		return funcionarios;
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

	public int getCount() {
		return count;
	}

	public void setCount(int count) {
		this.count = count;
	}
}