
public class Binary {

	public static void main(String[] args) {
		int N = Integer.parseInt(args[0]);
		int v = 1;
		
		while (v <= N/2)
			v=2*v;
		
		// Agora v é a maior potencia de 2
		
		int n = N;
		
		System.out.println("Decimal : " + N);
		
		System.out.print("Binario : ");
		
		while(v>0) {
			if (n<v) {
				System.out.print(0);
			} else {
				System.out.print(1);
				n-= v;
			}
			v=v/2;	
		}

	}

}
