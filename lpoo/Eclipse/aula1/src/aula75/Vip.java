package aula75;

public class Vip extends Ingresso {
	private double valorAdicional;
	
	public Vip(double valorInicial, double valorAdicional) {
		super(valorInicial);
		setValorAdicional(valorAdicional);
	}

	public double getValorAdicional() {
		return valorAdicional;
	}

	public void setValorAdicional(double valorAdicional) {
		this.valorAdicional = valorAdicional;
	}
	
	@Override
	public void imprimeValor() {
		super.imprimeValor();
		System.out.println("Valor com acréscimo: " + (getValorInicial() + getValorAdicional()));
	}
}
