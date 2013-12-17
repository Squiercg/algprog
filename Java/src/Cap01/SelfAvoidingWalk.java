package Cap01;

public class SelfAvoidingWalk {

	/**
	 * http://en.wikipedia.org/wiki/Self-avoiding_walk
	 * N = Tamanho da matriz a caminhar (Quadrada)
	 * T = Número de iterações
	 * deadEnds = Número de iterações que resultam em Caminhos sem saida
	 * a[][] = Matriz booleana N*N, registra interseções percorridas
	 * x,y =  posição atual
	 * r = Número aleatorio entre 0 e 1
	 */
	public static void main(String[] args) {
		int N = Integer.parseInt(args[0]);
		int T = Integer.parseInt(args[1]);
		int deadEnds = 0;
		
		for(int t = 0; t<T; t++) {
			boolean[][] a = new boolean[N][N];
			int x=N/2, y=N/2;
			while((x>0 && x<N-1) && (y>0 && y<N-1)) {
				a[x][y]=true;
				//teste para um caminho sem volta
				if (a[x-1][y] && a[x+1][y] && a[x] [y-1] && a[x][y+1]) {
					deadEnds++; 
					break;
				}
				//Caso o caminho não seja sem volta, damos mais um passo
				double r = Math.random();
				
				if     (r<0.25) {if(!a[x+1][y]) x++;}
				else if(r<0.50) {if(!a[x-1][y]) x--;}
				else if(r<0.75) {if(!a[x][y+1]) y++;}
				else if(r<1.00) {if(!a[x][y-1]) y--;}
			}
		}
		System.out.println(100*deadEnds/T + "% of dead Ends");
	}
}
