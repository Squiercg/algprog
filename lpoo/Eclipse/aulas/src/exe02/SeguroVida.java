package exe02;

public class SeguroVida implements Tributos {
	private int cpf;
	private double valor;
	
	public SeguroVida(int cpf, double valor){
		this.setCpf(cpf);
		this.setValor(valor);		
	}
	
	public int getCpf() {
		return cpf;
	}
	public void setCpf(int cpf) {
		this.cpf = cpf;
	}
	public double getValor() {
		return valor;
	}
	public void setValor(double valor) {
		this.valor = valor;
	}
	
	public double tributos(){
		return this.getValor()*0.06;		
	}

}
