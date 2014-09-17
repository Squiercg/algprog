package aula6;

public class Funcionario {
	private String nome;
	private String sobrenome;
	
	public Funcionario(){};
	
	public Funcionario(String nome, String sobrenome){
		setNome(nome);
		setSobrenome(sobrenome);
	}
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getSobrenome() {
		return sobrenome;
	}
	public void setSobrenome(String sobrenome) {
		this.sobrenome = sobrenome;
	}
	
}
