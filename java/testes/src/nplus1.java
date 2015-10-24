import java.util.Scanner;


public class nplus1 {
	
	public static int collatz(int n){
		 if(n!=1) {
			    if(n%2==0) {
			      n=n/2;
			    } else {
			      n=n*3+1;
			    }
			  }
			    return n;		
	}
	
	public static int seqcollatz(int n){
		int ciclo=1;

		  while(n!=1) {

		      n=collatz(n);
		      ciclo++;

		  }

		  return ciclo;		
	}
	
	public static void main(String[] args) {
		
		int a,b,i,ciclo,maior,x,y;

		Scanner leitor = new Scanner(System.in);
		
		while(leitor.hasNext()) {
			x=leitor.nextInt();
			y=leitor.nextInt();
			
			   if(x>y) {
				      a=y;
				      b=x;
				    } else {
				      a=x;
				      b=y;
				    }

				    maior=1;

				    for(i=a;i<=b;i++) {

				      ciclo=seqcollatz(i);

				      if(maior<ciclo) {
					maior=ciclo;
				      }

				    }

				    System.out.printf("%d %d %d\n",x ,y ,maior);
			
			
		}
		
		leitor.close();

	}

}
