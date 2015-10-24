import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class leitura01 {

	/**
	 * Essa função le o arquivo teste01.txt e imprime os número contidos nele
	 * o primeiro elemento é o número de itens do arquivo.
	 */
	public static void main(String[] args) {
		
		int n=0;
		int[] vetor = new int[0];
		
		try {
			File arquivo = new File("teste01.txt");
			Scanner entrada = new Scanner(arquivo);
			
			n = entrada.nextInt();	
			
			vetor = new int[n];			
			
			for(int i=0; i<n ; i++) {
				vetor[i]=entrada.nextInt();
			}
			
			entrada.close();
		} catch (FileNotFoundException e) {
			System.out.println("Arquivo não encontrado");
        } 	
		
		for(int i=0; i<n ; i++) {
			System.out.println(vetor[i]);			
		}
		
		
	}
}
