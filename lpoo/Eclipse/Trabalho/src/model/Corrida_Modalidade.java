package model;

public class Corrida_Modalidade {
	private int id_corrida;
	private int id_modalidade;
	
	public int getId_corrida() {
		return id_corrida;
	}
	public void setId_corrida(int id_corrida) {
		this.id_corrida = id_corrida;
	}
	public int getId_modalidade() {
		return id_modalidade;
	}
	public void setId_modalidade(int id_modalidade) {
		this.id_modalidade = id_modalidade;
	}
	
	public Corrida_Modalidade(int corrida, int modalidade){
		this.setId_corrida(corrida);
		this.setId_modalidade(modalidade);
	}
}
