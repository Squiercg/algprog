public class Inferior extends Vip {

    private int pessoas;

    public Inferior() {
	setValor(0);
	setAdicional(0);
	setPessoas(pessoas);
    }

    public Inferior(Vip inicio, int pessoas) {
	this.setValor(inicio.getValor());
	this.setAdicional(inicio.getAdicional());
	setPessoas(pessoas);
    }

    public void setPessoas(int people) {
	this.pessoas=people;
    }

    public int getPessoas() {
	return this.pessoas;
    }
}