
public class RandomSeq {

	/**
	 * Gera uma sequencia de N números aleatorios entre 0 e 1
	 * com distribuição uniforme.
	 */
	public static void main(String[] args) {
		int N = Integer.parseInt(args[0]);
		
		for(int i = 0 ; i<N ; i++){
			System.out.println(Math.random());
		}
	}
}
