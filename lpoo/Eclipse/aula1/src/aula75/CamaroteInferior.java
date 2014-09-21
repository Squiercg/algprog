package aula75;

public class CamaroteInferior extends Vip {
	private int quantidadeDePessoas;
		
	public CamaroteInferior(double valorInicial, double valorAdicional, int quantidadeDePessoas) {
		super(valorInicial, valorAdicional);
		setQuantidadeDePessoas(quantidadeDePessoas);
	}

	public int getQuantidadeDePessoas() {
		return quantidadeDePessoas;
	}

	public void setQuantidadeDePessoas(int quantidadeDePessoas) {
		this.quantidadeDePessoas = quantidadeDePessoas;
	}

}
