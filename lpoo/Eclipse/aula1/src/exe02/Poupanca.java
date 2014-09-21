package exe02;

public class Poupanca extends Conta {	
	private double saldo;

	public Poupanca(String nome, int cpf, int agencia, int conta) {
		super(nome, cpf, agencia, conta);
		this.setSaldo((float) 0.0);
	}
	
	public String getNome() {
		return getPessoa().getNome();
	}
	
	public int getCpf() {
		return getPessoa().getCpf();
	}

	public double getSaldo() {
		return saldo;
	}

	public void setSaldo(double saldo) {
		this.saldo = saldo;
	}

}
