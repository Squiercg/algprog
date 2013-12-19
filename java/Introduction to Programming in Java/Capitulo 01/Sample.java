
public class Sample {

	/**
	 * M = Tamanho da amostra
	 * N = Variação
	 * perm[] = permutação de 0 a N-1
	 */
	public static void main(String[] args) {
		int M = Integer.parseInt(args[0]);
		int N = Integer.parseInt(args[1]);
		int[] perm = new int[N];
		
		//inicializando perm[]
		for(int j = 0 ; j < N ; j++) {
			perm[j]=j;
		}
		
		//Tomando uma amostra
		for(int i = 0; i < M ; i++){
			int r = i + (int) (Math.random() * (N-i));
			int t = perm[r];
			perm[r] = perm[i];
			perm[i] = t;
		}
		
		for(int i = 0 ; i < M ; i++) {
			System.out.print(perm[i] + " ");
		}
		System.out.println();
		

	}

}
