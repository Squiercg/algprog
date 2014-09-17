package aula6;

public class Diretor extends Funcionario implements Autenticavel {
	private String meuAtributoDeDiretor;
		

	public Diretor(
			String nome, 
			String sobrenome,
			String meuAtributoDeDiretor) {
		super(nome, sobrenome);
		setMeuAtributoDeDiretor(meuAtributoDeDiretor);
	}

	public String getMeuAtributoDeDiretor() {
		return meuAtributoDeDiretor;
	}

	public void setMeuAtributoDeDiretor(String meuAtributoDeDiretor) {
		this.meuAtributoDeDiretor = meuAtributoDeDiretor;
	}
	
	public boolean autentica(String login, String senha) {
		if(senha.equals("123456")) {
			return true;
		}
		return false;		
	}
	
	

}
