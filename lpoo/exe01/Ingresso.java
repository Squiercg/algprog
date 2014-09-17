public class Ingresso {

    private float valor;

    public Ingresso(float x){
	setValor(x);
    }

    public Ingresso(){
	setValor(0);
    }

    public void setValor(float x) {
	if(x>0) {
	    this.valor=x;
	} else {
	    this.valor=0;
	}
    }
    public float getValor() {
	return this.valor;
    }

    public void imprimeValor(){
	System.out.println(this.valor);
    }


}