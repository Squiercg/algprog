package Cap01;

public class factors {

	/**
	 * Fatora um número em fatores primos.
	 * Entrada: Um inteiro qualquer.
	 */
	public static void main(String[] args) {
		long N = Long.parseLong(args[0]);
		long n = N;
		
		for(int i=2; i<=n/i;i++) {
			// teste se i é um fator
			while(n%i==0){
				//jogue fora esse i
				n /=i;
				System.out.print(i + " ");
			}			
		}
		if (n>1) System.out.print(n);
		System.out.println();
	}
}
