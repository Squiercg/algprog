package aula75;

public class Ingresso {
	private double valorInicial;
	
	
	public Ingresso(double valorInicial) {
		setValorInicial(valorInicial);
	}

	public double getValorInicial() {
		return valorInicial;
	}

	public void setValorInicial(double valorInicial) {
		this.valorInicial = valorInicial;
	}
	
	public void imprimeValor() {
		System.out.println("Valor inicial: " + getValorInicial());
	}
}
