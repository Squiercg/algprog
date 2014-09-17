package aula6;

public class Gerente extends Funcionario {
	private String meuAtributoDeGerente;
	
	public Gerente(
			String nome,
			String sobrenome,
			String meuAtributoDeGerente) {
		super(nome,sobrenome);
		setMeuAtributoDeGerente(meuAtributoDeGerente);		
	}

	public String getMeuAtributoDeGerente() {
		return meuAtributoDeGerente;
	}

	public void setMeuAtributoDeGerente(String meuAtributoDeGerente) {
		this.meuAtributoDeGerente = meuAtributoDeGerente;
	}
	
	public boolean autentica(String login, String senha) {
		return true;		
	}

}
