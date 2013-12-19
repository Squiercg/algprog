
/*
 * Esse programa vai pegar um valor N, e vai fazer um vetor 
 * de variavies booleanas do tamanho de N-1
 * Dai ele vai ficar sorteando um valor ao acaso entre 0 e N.
 * E uma vez que o valor é sorteado, o indice do vetor booleano dele
 * é preenchido com verdadeiro.
 * Assim o programa vai iterar até que todos os valores tenham sido
 * sorteados uma vez.
 * Assim ele vai rodar no minimo N vezes, e no maximo infinito.
 * Mas em média ele vai rodar um pouco mais de N.
 */

public class CouponCollector {

	public static void main(String[] args) {
		int N = Integer.parseInt(args[0]);
		boolean[] found = new boolean[N];
		int cardcnt = 0, valcnt = 0;
		while(valcnt < N) {
			int val = (int) (Math.random() * N);
			cardcnt++;
			if (!found[val]) {
				valcnt++;
				found[val]=true;
			}
		}
		System.out.println(cardcnt);
	}

}
