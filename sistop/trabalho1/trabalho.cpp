#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Classes.h"

int main() {

  int esquemaPaginacao , enderecamentoVirtual , enderacamentoFisico , tamanhoPagina , algoritmoSubstituicao ,
    nProcessos , nQuadros ;

/*1. Esquema de paginaçao:
Se 0, o esquema de paginaçao desejado é paginação de dois níveis.
Se 1, o esquema de paginaçao escolhido é paginaçao invertida.*/
  std::cout << "Esquema de paginação: ";
  std::cin >> esquemaPaginacao;


/*2. Quantidade de bits do espaço de endereçamento virtual;*/
  std::cout << "Quantidade de bits do espaço de endereçamento virtual: ";
  std::cin >> enderecamentoVirtual;

/*3. Quantidade de bits do espaço de endereçamento físico;*/
 std::cout << "Quantidade de bits do espaço de endereçamento físico: ";
 std::cin >> enderacamentoFisico;

/*4. Tamanho da página (em Kb);*/
 std::cout << "Tamanho da página: ";
 std::cin >> tamanhoPagina;

/*5. Algoritmo de substituição de páginas:
• Se 1, utilizar algoritmo FIFO;
• Se 2, utilizar algoritmo LRU (implementado utilizando uma pilha).*/
 std::cout << "Algoritmo de substituição de páginas: ";
 std::cin >> algoritmoSubstituicao;

/*6. Quantidade de processos em execução. Por exemplo, se o valor recebido nesse campo for 3, deve existir os
processos com id 0, 1 e 2;*/
 std::cout << "Quantidade de processos em execução: ";
 std::cin >> nProcessos;

/*7. Quantidade de quadros disponíveis.*/

 std::cout << "Quantidade de quadros disponíveis: ";
 std::cin >> nQuadros;

 std::cout << pow(2,enderecamentoVirtual);


 TabelaPagina* memoria = new TabelaPagina[nQuadros];

 std::cout << "\nHello World!\n";

 bool atividade = true;
 int opcao;



 while(atividade) {

   std::cout << "(1) Ler um endereço lógico de um processo\n";
   std::cout << "(2) Escrever um valor em um endereço lógico de um processo\n";
   std::cout << "(3) Remover da memória uma página de um processo\n";
   std::cout << "(4) Imprimir a(s) tabela(s) de página\n";
   std::cout << "(5) Imprimir o conteudo do espaço de endereçamento virtual de cada processo, lendo diretamente do disco\n";
   std::cout << "(6) Imprimir o conteúudo da memória física (byte por byte)\n";
   std::cout << "(7) Imprimir a quantidade de acessos realizados até o momento\n";
   std::cout << "(8) Imprimir a quantidade de falhas de página existentes até o momento\n";
   std::cout << "(9) Sair do programa\n";

   std::cout << "\nOdio1\n";
   std::cin >> opcao;
   std::cout << "\nOdio2\n";

   switch(opcao){
   case 1:
     std::cout << opcao;
     break;
   case 2:
     std::cout << opcao;
     break;
   case 3:
     std::cout << opcao;
     break;
   case 4:
     std::cout << opcao;
     break;
   case 5:
     std::cout << opcao;
     break;
   case 6:
     std::cout << opcao;
     break;
   case 7:
     std::cout << opcao;
     break;
   case 8:
     std::cout << opcao;
     break;
   case 9:
     std::cout << opcao;
     atividade = false;
     break;
   default:
     std::cout << "Valor invalido\n";
     atividade = false;
     break;
   }
 }
}
