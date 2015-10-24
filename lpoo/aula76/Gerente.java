package aula76;

public class Gerente extends Funcionario implements Autenticavel {
	
	public Gerente
	(
			String nome, 
			String sobrenome,
			String meuAtributoDeGerente
	) {
		super(nome, sobrenome);
		setMeuAtributoDeGerente(meuAtributoDeGerente);
	}
	
	private String meuAtributoDeGerente;

	public String getMeuAtributoDeGerente() {
		return meuAtributoDeGerente;
	}

	public void setMeuAtributoDeGerente(String meuAtributoDeGerente) {
		this.meuAtributoDeGerente = meuAtributoDeGerente;
	}
	
	@Override
	public boolean autentica(String login, String senha) {
		return true;
	}
}
