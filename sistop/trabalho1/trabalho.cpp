/**********************************/
/* Augusto Ribas                  */
/* Thiago Machado                 */
/**********************************/



#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <queue>
#include "Classes.h"



/**********************************/
/* Funções de manipulação da fila */
/**********************************/

unsigned int descobre_p(unsigned int tamanho_p, unsigned int tamanho_d, unsigned int endereco_logico);

int quantidade_falha_pagina = 0;
int quantidade_acessos = 0;

int main() {

  int esquemaPaginacao , enderecamentoVirtual , enderacamentoFisico , tamanhoPagina , algoritmoSubstituicao ,
    nProcessos , nQuadros , i, j, numeroprocesso , el, pagina, quadro_livre, tamanho_p, tamanho_d;
  bool falha_de_pagina;
  char entrada;


/*1. Esquema de paginaçao:
Se 0, o esquema de paginaçao desejado é paginação de dois níveis.
Se 1, o esquema de paginaçao escolhido é paginaçao invertida.*/
  std::cout << "\nEsquema de paginação (0 Multinivel, 1 Paginação Invertida): ";
  //std::cin >> esquemaPaginacao;
  esquemaPaginacao=1;

/*2. Quantidade de bits do espaço de endereçamento virtual;*/
  std::cout << "\nQuantidade de bits do espaço de endereçamento virtual: ";
  //std::cin >> enderecamentoVirtual;
  enderecamentoVirtual=5;

/*3. Quantidade de bits do espaço de endereçamento físico;*/
 std::cout << "\nQuantidade de bits do espaço de endereçamento físico: ";
 //std::cin >> enderacamentoFisico;
 enderacamentoFisico=4;

/*4. Tamanho da página (em Kb);*/
 std::cout << "\nTamanho da página: ";
 //std::cin >> tamanhoPagina;
 //tamanhoPagina=tamanhoPagina*1024;
 tamanhoPagina=8;

/*5. Algoritmo de substituição de páginas:
• Se 1, utilizar algoritmo FIFO;
• Se 2, utilizar algoritmo LRU (implementado utilizando uma pilha).*/
 std::cout << "\nAlgoritmo de substituição de páginas (1: FIFO, 2:LRU): ";
 //std::cin >> algoritmoSubstituicao;
 algoritmoSubstituicao=2;

/*6. Quantidade de processos em execução. Por exemplo, se o valor recebido nesse campo for 3, deve existir os
processos com id 0, 1 e 2;*/
 std::cout << "\nQuantidade de processos em execução: ";
 //std::cin >> nProcessos;
 nProcessos=2;

/*7. Quantidade de quadros disponíveis.*/

 std::cout << "\nQuantidade de quadros disponíveis: ";
 //std::cin >> nQuadros;
 nQuadros=2;


 std::cout << "\nIniciando memoria e disco\n";
char* memoria = new char[nQuadros*(tamanhoPagina)];
for(i=0;i<nQuadros*tamanhoPagina;i++)
  memoria[i]='-';

char** disco = new char*[nProcessos];
for (i = 0; i < nProcessos; ++i)
  disco[i] = new char[(int) (pow(2,enderecamentoVirtual))];

for (i = 0; i < nProcessos; i++)
  for(j = 0; j < pow(2,enderecamentoVirtual); j++)
    disco[i][j]= (rand() % 25)+97;


std::cout << "\n ----------------------- \n"; 

tamanho_d=enderacamentoFisico-log2(nQuadros);
tamanho_p=enderecamentoVirtual-tamanho_d;

TabelaPaginaInvertida* tabelaPaginaInvertida = new TabelaPaginaInvertida(nQuadros,tamanho_p,tamanho_d);
FIFO* fifo = new FIFO();
LRU* lru = new LRU(nQuadros);

bool atividade = true;
int opcao=0;


 while(atividade) {

   std::cout << "\n\n\n\n";
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
   system("clear");
   

   switch(opcao){
   case 1:
   quantidade_acessos++;

   std::cout << "Digite o número do processo\n";
   std::cin >> numeroprocesso;
   std::cout << "Digite o endereco lógico que deseja acessar do processo \n";
   std::cin >> el;

   /**********************/

   pagina = descobre_p(tamanho_p, tamanho_d, el);
   quadro_livre = -1;
   falha_de_pagina = false;

   if(tabelaPaginaInvertida->pagina_esta_mapeada(numeroprocesso,pagina)==true) {
    if(algoritmoSubstituicao==2)
      lru->update_tempo(tabelaPaginaInvertida->descobre_quadro(numeroprocesso,pagina),quantidade_acessos);    
    std::cout << "Ta mapeado\n";
   } else {
    falha_de_pagina = true;
    quantidade_falha_pagina++;
   }

   if(falha_de_pagina){
    quadro_livre=tabelaPaginaInvertida->procura_quadro_livre();
    if(quadro_livre==-1) {
      if(algoritmoSubstituicao==1)
        quadro_livre=fifo->remove_da_fila();
      else
        quadro_livre=lru->remove_da_fila();
    }
    tabelaPaginaInvertida->insere_pagina(numeroprocesso,pagina,quadro_livre,memoria,disco);
    if(algoritmoSubstituicao==1)
      fifo->insere_na_fila(quadro_livre);
    else
      lru->insere_na_fila(quadro_livre,quantidade_acessos);

   }


   std::cout << "Fim da opção 1\n";
   break;

   case 2:
   quantidade_acessos++;

   std::cout << "Digite o número do processo\n";
   std::cin >> numeroprocesso;
   std::cout << "Digite o endereco lógico que deseja escrever \n";
   std::cin >> el;
   std::cout << "Digite o char que deve ser escrito la \n";
   std::cin >> entrada;

   quantidade_acessos++;

   pagina = descobre_p(tamanho_p, tamanho_d, el);
   quadro_livre = -1;
   falha_de_pagina = false;

   if(tabelaPaginaInvertida->pagina_esta_mapeada(numeroprocesso,pagina)==true) {
    if(algoritmoSubstituicao==2)
      lru->update_tempo(tabelaPaginaInvertida->descobre_quadro(numeroprocesso,pagina),quantidade_acessos);
    std::cout << "Ta mapeado\n";
   } else {
    falha_de_pagina = true;
    quantidade_falha_pagina++;
   }

   if(falha_de_pagina){
    quadro_livre=tabelaPaginaInvertida->procura_quadro_livre();
    if(quadro_livre==-1) {
      if(algoritmoSubstituicao==1)
        quadro_livre=fifo->remove_da_fila();
      else
        quadro_livre=lru->remove_da_fila();
    }
    std::cout << quadro_livre;
    tabelaPaginaInvertida->insere_pagina(numeroprocesso,pagina,quadro_livre,memoria,disco);
    if(algoritmoSubstituicao==1)
      fifo->insere_na_fila(quadro_livre);
    else
      lru->insere_na_fila(quadro_livre,quantidade_acessos);
   }

   tabelaPaginaInvertida->escreve_endereco(numeroprocesso,pagina,el,entrada,memoria);


   std::cout << "Fim da opção 2\n";
     
     break;
   case 3:
   quantidade_acessos++;
   std::cout << "Digite o número do processo\n";
   std::cin >> numeroprocesso;
   std::cout << "Digite o numero da pagina que deseja remover \n";
   std::cin >> pagina;

   if(tabelaPaginaInvertida->pagina_esta_mapeada(numeroprocesso,pagina)==true) {
    tabelaPaginaInvertida->remove_pagina(numeroprocesso,pagina,memoria,disco);
    if(algoritmoSubstituicao==1)
      fifo->remove_da_fila(tabelaPaginaInvertida->descobre_quadro(numeroprocesso,pagina));
    else
      lru->remove_da_fila(tabelaPaginaInvertida->descobre_quadro(numeroprocesso,pagina));

  } else {
    std::cout << "Pagina não esta mapeada\n";
  }

     break;
   case 4:
   tabelaPaginaInvertida->imprime_tabela_pagina();
   break;

   case 5:
     for(i=0;i<nProcessos;i++) {
      std::cout << "Processo ";
      std::cout << i;
      std::cout << "\n";
      for(j=0;j<pow(2,enderecamentoVirtual);j++){
        std::cout << disco[i][j];
      }
      std::cout << "\n";
    }
     break;

   case 6:
     std::cout << "Memoria Fisica:\n";
     for(i=0; i<nQuadros*tamanhoPagina; i++ )
     std::cout << memoria[i];
     std::cout << "\n\n";
   break;

   case 7:
   std::cout << "Quantidade de acessos: ";
   std::cout << quantidade_acessos;
   std::cout << "\n";
     break;
   case 8:
   std::cout << "Quantidade de falhas de pagina: ";
   std::cout << quantidade_falha_pagina;
   std::cout << "\n";
   break;

   case 9:
     atividade = false;
     break;

   default:
     std::cout << "Valor invalido\n";
     break;
   }
 }
 delete disco;
 delete memoria;
 delete tabelaPaginaInvertida;
 return 0;
}


/*Funções */
unsigned int descobre_p(unsigned int tamanho_p, unsigned int tamanho_d, unsigned int endereco_logico) {
  endereco_logico = endereco_logico >> tamanho_d;
  unsigned int operando = (pow(2,tamanho_p) - 1);
  return endereco_logico & operando;
}
