package aula76;

public class Engenheiro extends Funcionario {
	private String meuAtributoDeEngenheiro;
	
	public Engenheiro
	(
			String nome, 
			String sobrenome,
			String meuAtributoDeEngenheiro
	) {
		super(nome, sobrenome);
		setMeuAtributoDeEngenheiro(meuAtributoDeEngenheiro);
	}

	public String getMeuAtributoDeEngenheiro() {
		return meuAtributoDeEngenheiro;
	}

	public void setMeuAtributoDeEngenheiro(String meuAtributoDeEngenheiro) {
		this.meuAtributoDeEngenheiro = meuAtributoDeEngenheiro;
	}


	
	
}
