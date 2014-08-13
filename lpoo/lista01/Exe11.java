public class Exe11 {

    public static void main(String[] args) {
	int n = Integer.parseInt(args[0]);
	int x=1;
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=i;j++){
		System.out.print(x*j+" ");
	    }
	    System.out.print("\n");
	    x=x+1;
	}
    }
}