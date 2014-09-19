package exe02;

public class GerenciadorDeImpostoDeRenda {
	private double imposto;
	
	public GerenciadorDeImpostoDeRenda() {
		this.imposto = 0.0;
	}

	public double getImposto() {
		return imposto;
	}
	
	public void adiciona(Tributos tributavel){
		this.imposto+=tributavel.tributos();
	}
	
	

}
