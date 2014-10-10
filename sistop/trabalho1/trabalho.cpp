#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <queue>
#include "Classes.h"

std::queue<int> fila;

/**********************************/
/* Funções de manipulação da fila */
/**********************************/
void insere_na_fila(int elemento);
int remove_da_fila();
void remove_da_fila(int elemento);


void inicializa_quadros_livres(bool* quadros_livres, int quantidade_de_quadros);
unsigned int descobre_p(unsigned int tamanho_p, unsigned int tamanho_d, unsigned int endereco_logico);

int main() {

  int esquemaPaginacao , enderecamentoVirtual , enderacamentoFisico , tamanhoPagina , algoritmoSubstituicao ,
    nProcessos , nQuadros , i, j, numeroprocesso , el, pagina, quadro_livre, tamanho_p, tamanho_d;
  bool falha_de_pagina;


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


 std::cout << "Iniciando memoria e disco\n";
char* memoria = new char[(tamanhoPagina*1024)/8];
for(i=0;i<(tamanhoPagina*1024)/8;i++)
  memoria[i]=(rand() % 25)+97;

char** disco = new char*[nProcessos];
for (i = 0; i < nProcessos; ++i)
  disco[i] = new char[(int) (pow(2,enderecamentoVirtual)/8)];

for (i = 0; i < nProcessos; i++)
  for(j = 0; j < (pow(2,enderecamentoVirtual)/8); j++)
    disco[i][j]= (rand() % 25)+97;


std::cout << "\n ----------------------- \n"; 

TabelaPaginaInvertida* tabelainvertida = new TabelaPaginaInvertida[nQuadros];
bool* quadros_livres = new bool[nQuadros];

bool atividade = true;
int opcao;



 while(atividade) {

   std::cout << "(1) Ler um endereço lógico de um processo\n";
   std::cout << "(2) Escrever um valor em um endereço lógico de um processo\n";
   std::cout << "(3) Remover da memória uma página de um processo\n";
   std::cout << "(4) Imprimir a(s) tabela(s) de página\n";
   std::cout << "(5) Imprimir o conteudo do espaço de endereçamento virtual de cada processo, lendo diretamente do disco\n";
   std::cout << "(6) Imprimir o conteúdo da memória física (byte por byte)\n";
   std::cout << "(7) Imprimir a quantidade de acessos realizados até o momento\n";
   std::cout << "(8) Imprimir a quantidade de falhas de página existentes até o momento\n";
   std::cout << "(9) Sair do programa\n"; 
   std::cin >> opcao;
   

   switch(opcao){
   case 1:
   std::cout << "Digite o número do processo\n";
   std::cin >> numeroprocesso;
   std::cout << "Digite o endereco lógico que deseja acessar do processo \n";
   std::cin >> el;

   /**********************/
   /*Início do seu código*/
   /**********************/

   
   tamanho_d=enderacamentoFisico-log2(nQuadros);
   tamanho_p=enderecamentoVirtual-tamanho_d;
    
   falha_de_pagina = false;
   pagina = descobre_p(tamanho_p, tamanho_d, el);
   quadro_livre = -1;

   /*Pergunto se a pagina esta mapeada, se nao procuro um quadro livre*/
   for(i=0;i<nQuadros;i++) {
    if(tabelainvertida[i].processo==numeroprocesso && 
       tabelainvertida[i].pagina==pagina && 
       tabelainvertida[i].bitvalidade==true) {
      tabelainvertida->imprime_conteudo(memoria);
    }    
    }


/*Falha de pagina, precisamos de um quadro para alocar os dados*/
    if(falha_de_pagina==true) {
      for(i=0; i<nQuadros; i++) {
        if(quadros_livres[i] == true) {
          /*Achei um quadro livre*/
          quadro_livre = i;
          break;
        }
      }
    }

     std::cout << "Fim da opção 1\n";
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
     std::cout << "Memoria Fisica:\n";
     for(i=0; i<(tamanhoPagina*1024)/8; i++ )
     std::cout << memoria[i];
     std::cout << "\n\n";
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










/*Funções */

/**********************************/
/* Funções de manipulação da fila */
/**********************************/
void insere_na_fila(int valor) {
  fila.push(valor);
}

int remove_da_fila() {
  int valor = -1;
  if(!fila.empty()) {
    valor = fila.front();
    fila.pop();
  }
  return valor;
}

void remove_da_fila(int elemento) {
  if(!fila.empty()) {
    if(elemento == fila.front()) {
      fila.pop();
    }
    else {
      int primeiro = remove_da_fila();
      insere_na_fila(primeiro);
      while(fila.front() != primeiro) {
        if(fila.front() == elemento) {
          fila.pop();
        }
        else {
          insere_na_fila(remove_da_fila());
        }
      }
    }
  }
}

/*************************************/
/* Funções de manipulação da memoria */
/*************************************/

void inicializa_quadros_livres(bool* quadros_livres, int quantidade_de_quadros) {
  for(int i = 0 ; i < quantidade_de_quadros ; i++)
    quadros_livres[i] = true;
}

unsigned int descobre_p(unsigned int tamanho_p, unsigned int tamanho_d, unsigned int endereco_logico) {
  endereco_logico = endereco_logico >> tamanho_d;
  unsigned int operando = (pow(2,tamanho_p) - 1);
  return endereco_logico & operando;
}
