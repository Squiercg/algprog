
public class Newton {

	/**
	 * Função para calcular a raiz quadrada da uma entrada double.
	 */
	public static double sqrt(double c) {
		if (c < 0) { return Double.NaN; }
		double err = 1e-15;
		double t = c;
		while (Math.abs(t-c/t)> err*t) {
			t = (c/t+t)/2.0;
		}
		return t;
	}
	
	public static void main(String[] args) {
		int N = args.length;
		double[] a = new double[N];
		
		for (int i=0; i<N ; i++) {
			a[i]= Double.parseDouble(args[i]);
		}
		
		for (int i=0; i<N ; i++) {
			double x = sqrt(a[i]);
			StdOut.printf("Raiz quadrada de %5.2f é %4.2f\n",a[i],x);
		}
	}
}
