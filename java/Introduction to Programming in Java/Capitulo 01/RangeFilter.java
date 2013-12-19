
public class RangeFilter {

	/**
	 * Imprime os número dentro do intervalo de entrada
	 */
	public static void main(String[] args) {
		int lo = Integer.parseInt(args[0]);
		int hi = Integer.parseInt(args[1]);
		while(!StdIn.isEmpty()) {
			int t = StdIn.readInt();
			if (t >= lo && t<=hi) {
				StdOut.print(t + "");
			}
		}
		StdOut.println();
	}
}
