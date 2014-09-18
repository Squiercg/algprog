public class Superior extends Vip {
    private boolean comida;

    public Superior(Vip inicio, boolean rango) {
	this.setValor(inicio.getValor());
	this.setAdicional(inicio.getAdicional());
	setComida(rango);
    }

    public void setComida(boolean rango){
	this.comida=rango;
    }

    public boolean getComida(){
	return this.comida;
    }

    @Override
	public void imprimeValor(){
	System.out.println(this.getValor()+this.getAdicional()+50.00);
    }

}