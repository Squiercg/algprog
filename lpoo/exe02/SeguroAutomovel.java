package exe02;

public class SeguroAutomovel implements Tributos {
	private String veiculo;
	private double valor;
	
	
	
	public SeguroAutomovel(String veiculo, double valor) {
		this.veiculo = veiculo;
		this.valor = valor;
	}
	public String getVeiculo() {
		return veiculo;
	}
	public void setVeiculo(String veiculo) {
		this.veiculo = veiculo;
	}
	public double getValor() {
		return valor;
	}
	public void setValor(double valor) {
		this.valor = valor;
	}
	
	public double tributos(){
		return this.getValor()*0.10;		
	}

}
