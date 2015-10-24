public class Data{
    private int dia;
    private int mes;
    private int ano;
    public Data(){
	this.setDia(1);
	this.setMes(1);
	this.setAno(2014);
    }


    public Data(int dia, int mes, int ano){
	this.setDia(dia);
	this.setMes(mes);
	this.setAno(ano);
    }

    public void setDia(int dia) {
	this.dia=dia;
    }

    public void setMes(int mes) {
	this.mes=mes;
    }

    public void setAno(int ano) {
	this.ano=ano;
    }

    public int getDia() {
	return this.dia;
    }

    public int getMes() {
	return this.mes;
    }

    public int getAno() {
	return this.ano;
    }

    public String toString() {
        return dia+":"+mes+":"+ano;  
    }




}
