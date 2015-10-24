package model;

public class Date {
	private int Dia;
	private int Mes;
	private int Ano;
	
	public Date(int dia, int mes, int ano){
		this.setDia(dia);
		this.setMes(mes);
		this.setAno(ano);
	}
	
	public void displayDate(){
		System.out.println(this.getDia() + "/" + this.getMes() + "/" + this.getAno());
	}

	public int getDia() {
		return this.Dia;
	}

	public void setDia(int dia) {
		this.Dia = dia;
	}

	public int getMes() {
		return this.Mes;
	}

	public void setMes(int mes) {
		this.Mes = mes;
	}
	
	public int getAno() {
		return this.Ano;
	}	

	public void setAno(int ano) {
		this.Ano = ano;
	}
	
	public String toString(){
		return this.getDia() + "/" + this.getMes() + "/" + this.getAno();
	}
}
