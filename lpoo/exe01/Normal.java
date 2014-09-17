public class Normal extends Ingresso {

    private boolean meia;

    public Normal() {
	setValor(0);
	setMeia(false);
    }

    public Normal(float x, boolean tipo) {
	setValor(x);
	setMeia(tipo);
    }

    public void setMeia(boolean tipo){
	this.meia=tipo;
    }

    public boolean getMeia(){
	return this.meia;
    }

    @Override
	public void imprimeValor() {
	if(meia==true) {
	    System.out.println(0.5*this.getValor());
	} else {
	    System.out.println(this.getValor());
	}
    }
}