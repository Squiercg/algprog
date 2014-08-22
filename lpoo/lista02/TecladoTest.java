public class TecladoTest {
	public static void main(String[] args) {

		Teclado teclado = new Teclado();

		int a = teclado.leInteiroS("Digite um inteiro");
		int b = teclado.leInteiroS();

		double valorDouble = teclado.leDoubleS("Digite um double");

		String cadeia = teclado.leStringS("Leia uma string");

		int c = teclado.leInteiroJ("Digite um inteiro");
		
		
	}

}