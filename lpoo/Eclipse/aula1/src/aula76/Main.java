package aula76;

public class Main {

	public static void main(String[] args) {
		Autenticavel d = new Diretor("nome", "sobrenome", "meu");
		Autenticavel g = new Gerente("nome", "sobrenome", "meu");
		
		System.out.println(d);
		System.out.println(g);

	}

}
