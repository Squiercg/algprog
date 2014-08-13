public class Exe10 {

    public static void main(String[] args) {
	/**/
	int n = Integer.parseInt(args[0]);

	System.out.println("Começando x em "+n);
	while(n>1) {
	    if(n%2==0){
		n=n/2;
	    }else{
		n=3*n+1;
	    }
	    System.out.println(n);
	}
    }

}
