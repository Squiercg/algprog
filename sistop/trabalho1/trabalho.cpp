#include <iostream>
#include <math.h>
#include "Classes.h"
using namespace std;

int main() {
	int esquemaPaginacao , enderecamentoVirtual , enderacamentoFisico , tamanhoPagina , algoritmoSubstituicao , 
	nProcessos , nQuadros ;

/*1.	Esquema de paginaçao:
Se 0, o esquema de paginaçao desejado é paginação de dois níveis.
Se 1, o esquema de paginaçao escolhido é paginaçao invertida.*/
cout << "Esquema de paginação: ";
cin >> esquemaPaginacao;


/*2. Quantidade de bits do espaço de endereçamento virtual;*/
std::cout << "Quantidade de bits do espaço de endereçamento virtual: ";
cin >> enderecamentoVirtual;

/*3. Quantidade de bits do espaço de endereçamento físico;*/
std::cout << "Quantidade de bits do espaço de endereçamento físico: ";
cin >> enderacamentoFisico;

/*4. Tamanho da página (em Kb);*/
std::cout << "Tamanho da página: ";
cin >> tamanhoPagina;

/*5. Algoritmo de substituição de páginas:
• Se 1, utilizar algoritmo FIFO;
• Se 2, utilizar algoritmo LRU (implementado utilizando uma pilha).*/
std::cout << "Algoritmo de substituição de páginas: ";
cin >> algoritmoSubstituicao;

/*6. Quantidade de processos em execução. Por exemplo, se o valor recebido nesse campo for 3, deve existir os 
processos com id 0, 1 e 2;*/
std::cout << "Quantidade de processos em execução: ";
cin >> nProcessos;

/*7. Quantidade de quadros disponíveis.*/

std::cout << "Quantidade de quadros disponíveis: ";
cin >> nQuadros;

std::cout << pow(2,enderecamentoVirtual);


TabelaPagina* memoria = new TabelaPagina[nQuadros];


	std::cout << "Hello World!\n";

    Rectangle rect;
    rect.set_values (3,4);
    cout << "area: " << rect.area() << "\n";
    return 0;
}
