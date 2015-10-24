package aula76;

public class Secretario extends Funcionario {
	private String meuAtributoDeSecretario;
	
	public Secretario
	(
			String nome, 
			String sobrenome, 
			String meuAtributoDeSecretario
	) {
		super(nome, sobrenome);
		setMeuAtributoDeSecretario(meuAtributoDeSecretario);
	}

	public String getMeuAtributoDeSecretario() {
		return meuAtributoDeSecretario;
	}

	public void setMeuAtributoDeSecretario(String meuAtributoDeSecretario) {
		this.meuAtributoDeSecretario = meuAtributoDeSecretario;
	}
}
