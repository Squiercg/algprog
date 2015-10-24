
public class Average {

	/**
	 * Sempre é preciso alguma mensagem para dizer que chegou ao fim
	 * os dados de entrada, nesse livro a convenção é ctrl+d
	 */
	public static void main(String[] args) {
		double sum = 0.0;
		int cnt = 0;
		StdOut.println("Entre com os valores: ");
		
		while(!StdIn.isEmpty()) {
			double value = StdIn.readDouble();
			sum += value;
			cnt++;
		}
		// É preciso dar um ctrl d para enviar um vaziu para o programa parar.
		double average = sum / cnt;
		StdOut.println("A média é " + average);
	}
}
