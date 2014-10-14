#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <queue>
#include "Classes.h"

/*Tabela(s) de página, onde cada linha da tabela de página deve ter pelo menos o campo número do quadro,
bit de validade e bit de modificaçaoo. Fique a vontade para adicionar outros campos que você achar conveniente;*/

/*Lista de quadros livres, que informa, para cada quadro da memória, se ele está livre ou ocupado;*/

/*Vetor memória, que éum vetor de bytes que armazenar de fato as páginas de cada processo;*/

/*Vetor ou matriz disco, que deve simular o conteúdo do disco de cada processo. Para simplificar a programaçao,
assuma que todo o espaço de endereçamento virtual de cada processo está preenchido.
O conteúdo do espaço de endereçamento virtual pode ser gerado de maneira aleatria.*/

void TabelaPaginaInvertida::inicializa_quadros_livres() {
  for(int i = 0 ; i < this->nQuadros ; i++)
    this->quadros_livres[i] = true;
}

bool TabelaPaginaInvertida::pagina_esta_mapeada(int numeroprocesso,int pagina){
	int i;
	
	/*Pergunto se a pagina esta mapeada, se nao procuro um quadro livre*/
	for(i=0; i < (this->nQuadros) ;i++) {
		if(this->linha[i].processo==numeroprocesso && 
			this->linha[i].pagina==pagina && 
			this->linha[i].bitvalidade==true) {
			return true;
		}
	}
	return false;
}

int TabelaPaginaInvertida::procura_quadro_livre(){
	int i;

	for(i = 0; i<(this->nQuadros); i++){
		if(this->quadros_livres[i] == true) {
			return i;
		}
	}
	return -1;
}

int TabelaPaginaInvertida::descobre_quadro(int numeroprocesso,int pagina){
	int i, quadro;

	for(i=0; i < (this->nQuadros) ;i++) {
		if(this->linha[i].processo==numeroprocesso && 
			this->linha[i].pagina==pagina && 
			this->linha[i].bitvalidade==true) {
			quadro=i;
			i=this->nQuadros;
		}
	}
	return quadro;
}


void TabelaPaginaInvertida::insere_pagina(int numeroprocesso,int pagina, int quadro, char* memoria, char** disco){
	int i;

	quadros_livres[quadro]=false;

	//Se o quadro é valido e foi modificado, devemos sobrescrevelo no disco
	if(this->linha[quadro].bitvalidade==true && this->linha[quadro].bitmodificacao==true) {		
		for(i = 0 ; i < (pow(2,this->q)) ; i++) {		
		disco[this->linha[quadro].processo][(int) (i+(pow(2,this->q)*this->linha[quadro].pagina))]=memoria[(int) (i+(pow(2,this->q)*quadro))];
		}
		this->linha[quadro].bitmodificacao==false;
	}

	//Depois paginamos
	this->linha[quadro].pagina=pagina;
	this->linha[quadro].processo=numeroprocesso;
	this->linha[quadro].bitvalidade=true;

	//E subimos o conteudo do disco para a memoria
	for(i = 0 ; i < (pow(2,this->q)) ; i++) {
		memoria[(int) (i+(pow(2,this->q)*quadro))]=disco[numeroprocesso][(int) (i+(pow(2,this->q)*pagina))];
	}
}

void TabelaPaginaInvertida::escreve_endereco(int numeroprocesso,int pagina,int endereco ,char entrada ,char* memoria){
	int i, quadro, deslocamento;

	for(i=0; i < (this->nQuadros) ;i++) {
		if(this->linha[i].processo==numeroprocesso && 
			this->linha[i].pagina==pagina && 
			this->linha[i].bitvalidade==true) {
			quadro=i;
		}
	}
	deslocamento = endereco % (int)pow(2,this->q);
	memoria[quadro+deslocamento]=entrada;

	this->linha[quadro].bitmodificacao=true;
}

void TabelaPaginaInvertida::remove_pagina(int numeroprocesso,int pagina, char* memoria, char** disco){
	//Se o quadro é valido e foi modificado, devemos sobrescrevelo no disco

	int i, quadro;

	for(i=0; i < (this->nQuadros) ;i++) {
		if(this->linha[i].processo==numeroprocesso && 
			this->linha[i].pagina==pagina && 
			this->linha[i].bitvalidade==true) {
			quadro=i;
		}
	}

	if(this->linha[quadro].bitvalidade==true && this->linha[quadro].bitmodificacao==true) {		
		for(i = 0 ; i < (pow(2,this->q)) ; i++) {		
		disco[this->linha[quadro].processo][(int) (i+(pow(2,this->q)*this->linha[quadro].pagina))]=memoria[(int) (i+(pow(2,this->q)*quadro))];
		}
		this->linha[quadro].bitmodificacao==false;
	}

	this->quadros_livres[quadro]=false;
	this->linha[quadro].bitvalidade=false;

	//Apenas a titulo de debug, remover.
	for(i = 0 ; i < (pow(2,this->q)) ; i++) {
		memoria[(int) (i+(pow(2,this->q)*quadro))] = '-';
	}


}

void TabelaPaginaInvertida::imprime_pagina(int numeroprocesso, int pagina, char* memoria){
	int i , quadro;

	for(i=0; i < (this->nQuadros) ;i++) {
		if(this->linha[i].processo==numeroprocesso && 
			this->linha[i].pagina==pagina && 
			this->linha[i].bitvalidade==true) {
			quadro=i;
		}
	}

	for(i=pow(2,this->q)*quadro;i<(pow(2,this->q)*(quadro+1));i++) {
		std::cout << memoria[i];
	}
}

void TabelaPaginaInvertida::imprime_tabela_pagina(){
	int i;

	for(i=0; i < (this->nQuadros) ;i++) {
		std::cout << "Linha: ";
		std::cout << i;
		std::cout << " Processo: ";
		std::cout << this->linha[i].processo;
		std::cout << " Pagina: "; 
		std::cout << this->linha[i].pagina;
		std::cout << " Validade: ";
		std::cout << this->linha[i].bitvalidade;
		std::cout << " Modificação: ";
		std::cout << this->linha[i].bitmodificacao;
		std::cout << "\n";
	}
}





void FIFO::insere_na_fila(int valor) {
  this->fila.push(valor);
}

int FIFO::remove_da_fila() {
  int valor = -1;
  if(!this->fila.empty()) {
    valor = this->fila.front();
    this->fila.pop();
  }
  return valor;
}

void FIFO::remove_da_fila(int elemento) {
  if(!this->fila.empty()) {
    if(elemento == this->fila.front()) {
      this->fila.pop();
    }
    else {
      int primeiro = remove_da_fila();
      insere_na_fila(primeiro);
      while(this->fila.front() != primeiro) {
        if(this->fila.front() == elemento) {
          this->fila.pop();
        }
        else {
          insere_na_fila(remove_da_fila());
        }
      }
    }
  }
}