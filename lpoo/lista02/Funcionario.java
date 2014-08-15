/*
 *Funcionario
 *******************
 *nome: String
 *departamento: String
 *salario: double
 *dataEntrada: String
 *rg: String
 ********************
 *void recebeAumento
 *double  calculaGanho
 *void mostra
 */

class Funcionario {

    String nome;
    String departamento;
    double salario;
    String dataEntrada;
    String rg;

    void recebeAumento(double aumento) {
	this.salario = this.salario + aumento;
    }

    double  calculaGanhoAnual() {
	double ganhoAnual = salario * 12;
	return ganhoAnual;
    }

    void mostra() {
	System.out.println("Nome: " + nome );
	System.out.println("Departamento: " + departamento );
	System.out.println("Salario: " + salario );
	System.out.println("Data de entrada: " + dataEntrada );
	System.out.println("RG: " + rg );
    }


}