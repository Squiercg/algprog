import java.util.Scanner;
import javax.swing.JOptionPane;

public class Teclado {

	private Scanner scanner;

	public Teclado() {
		scanner = new Scanner(System.in);
	}
	
	public int leInteiroS(String s){
		System.out.println(s);
		int valor = scanner.nextInt();
		scanner.nextLine();
		return valor;
	}

	public int leInteiroS(){
		int valor = scanner.nextInt();
		scanner.nextLine();
		return valor;
	}

	public String leStringS(String s){
		System.out.println(s);
		String cadeia = scanner.nextLine();
		scanner.nextLine();
		return  cadeia;
	}

	public float leFloatS(String s){
		System.out.println(s);
		float valor = scanner.nextFloat();
		scanner.nextLine();
		return valor;
	}

	public double leDoubleS(String s){
		System.out.println(s);
		double valor = scanner.nextDouble();
		return valor;	
	}

	public int leInteiroJ(String s){
		int valor = Integer.parseInt(JOptionPane.showInputDialog(s));
		return valor;
	}


}