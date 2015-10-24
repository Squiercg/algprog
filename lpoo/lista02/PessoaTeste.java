public class PessoaTeste{
    public static void main(String[] args) {
	Pessoa pessoa = new Pessoa();

	pessoa.nome="Augusto Ribas";
	pessoa.idade=33;

	pessoa.fazAniversario();
	pessoa.fazAniversario();

	System.out.println("Nome: "+pessoa.nome+", idade: "+pessoa.idade);

    }
}