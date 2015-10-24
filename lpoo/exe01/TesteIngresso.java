import java.util.Scanner;

public class TesteIngresso {

    public static void main(String[] args) {
	Scanner scanner = new Scanner(System.in);

	Ingresso ingressoteste = new Ingresso();
	System.out.print("Entre com o valor do ingresso:");
	ingressoteste.setValor(scanner.nextFloat());
	ingressoteste.imprimeValor();

	System.out.print("Entre com true para meia e false para inteira:");
	Normal normalteste = new Normal(ingressoteste.getValor(),scanner.nextBoolean());
	normalteste.imprimeValor();

	System.out.print("Entre com o valor adicional do ingresso:");
	Vip vipteste = new Vip(ingressoteste.getValor(),scanner.nextFloat());
	vipteste.imprimeValor();

	System.out.print("Entre com o numero de pessoas:");
	Inferior inferiorteste = new Inferior(vipteste,scanner.nextInt());
	inferiorteste.imprimeValor();

	System.out.print("Entre com true para comida no camarote ou false para camarote sem comida:");
	Superior superiorteste = new Superior(vipteste,scanner.nextBoolean());
	superiorteste.imprimeValor();

	//Todas as instancias criadas, testando cast para cima, o pai aceita todo mundo.

	Ingresso castTest1;

	castTest1=normalteste;
	castTest1=vipteste;
	castTest1=inferiorteste;
	castTest1=superiorteste;

	//Mas o contrario da erro de compilacao, vou deixar comentado para evitar o erro de compilacao

	/*
	Superior castTest2;

	castTest2=vipteste;
	***      Mensagem de erro      ****
	********************************************
TesteIngresso.java:42: error: incompatible types
	castTest2=vipteste;
	          ^
  required: Superior
  found:    Vip
1 error
make: ** [TesteIngresso.class] Erro 1
***************************************************

	*/

	/*Esse seria outro cast possivel, onde forçamos com o casting.
Isso é possivel (sem erro de compilação), mas vai falhar na hora que tentarmos usar o metodo imprimeValor, ja que tanto
vip como superior tem seus proprios métodos, mas o metodo de Superior é diferente do método do vip.
	Superior castTest3;

	castTest3 = (Superior)vipteste;

	castTest3.imprimeValor();
	*/


	System.out.println("Fim");
    }

}