
public class coupon {
	
	public static int uniform(int N) {
		return (int) (Math.random() * N);
	}
	
	public static int collect(int N) {
		boolean[] found = new boolean[N];
		int cardcnt = 0 , valcnt = 0;
		while (valcnt < N) {
			int val = uniform(N);
			cardcnt++;
			if(!found[val]) valcnt++;
			found[val] = true;
		}
		return cardcnt;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int N = Integer.parseInt(args[0]);
		int count = collect(N);
		StdOut.println(count);
	}
}
