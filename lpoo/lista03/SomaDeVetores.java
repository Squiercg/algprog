import java.util.Scanner;

public class SomaDeVetores {
	private static void soma(int a[], int b[],int c[],int n) {
		for(int i=0;i<n;i++){
			c[i]=a[i]+b[i];
		}
	}



	public static void main(String[] args){
		// int[] a,b,c;
		int n;
		int a[], b[], c[];

		Scanner scanner = new Scanner(System.in);

		System.out.println("Digite um inteiro");
		n = scanner.nextInt();


		a = new int[n];
		b = new int[n];
		c = new int[n];

		System.out.println("Valores de A e B");
		for(int i = 0; i<n ; i++) {
			System.out.printf("A%d:",i);
			a[i]=scanner.nextInt();
			System.out.printf("B%d:",i);
			b[i]=scanner.nextInt();
		}

		soma(a,b,c,n);

		for(int i = 0; i<n ; i++) {
			System.out.printf("%d:",c[i]);
		}
		System.out.println();

		

	}



}