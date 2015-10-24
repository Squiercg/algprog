public class Vip extends Ingresso {
    private float adicional;

    public Vip(){
	setValor(0);
	setAdicional(0);
    }

    public Vip(float x,float plus){
	setValor(x);
	setAdicional(plus);
    }

    public void setAdicional(float plus){
	this.adicional=plus;
    }

    public float getAdicional() {
	return this.adicional;
    }

    @Override
	public void imprimeValor(){
	System.out.println(this.getValor()+this.getAdicional());
    }
}