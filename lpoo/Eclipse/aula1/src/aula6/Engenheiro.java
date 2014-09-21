package aula6;

public class Engenheiro extends Funcionario {
	private String meusAtributosDeEngenheiro;
	
	

	public Engenheiro(
			String nome, 
			String sobrenome,
			String meusAtributosDeEngenheiro) {
		super(nome, sobrenome);
		setMeusAtributosDeEngenheiro(meusAtributosDeEngenheiro);
	}

	public String getMeusAtributosDeEngenheiro() {
		return meusAtributosDeEngenheiro;
	}
	
	public void setMeusAtributosDeEngenheiro(String meusAtributosDeEngenheiro) {
		this.meusAtributosDeEngenheiro = meusAtributosDeEngenheiro;
	}
	
	

}
