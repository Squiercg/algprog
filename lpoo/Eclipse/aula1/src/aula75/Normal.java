package aula75;

public class Normal extends Ingresso {
	private boolean meiaEntrada;
	
	public Normal(double valorInicial, boolean meiaEntrada) {
		super(valorInicial);
		setMeiaEntrada(meiaEntrada);
	}

	public boolean isMeiaEntrada() {
		return meiaEntrada;
	}

	public void setMeiaEntrada(boolean meiaEntrada) {
		this.meiaEntrada = meiaEntrada;
	}
}
