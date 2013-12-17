package Cap01;

public class RandomInt {

	public static void main(String[] args) {
		int N = Integer.parseInt(args[0]);
		double r = Math.random(); //Valor aleatorio entre 0 e 1
		int n = (int) (r*N); //distribuição uniforme entre 0 e N-1
		System.out.println(n);
	}

}
