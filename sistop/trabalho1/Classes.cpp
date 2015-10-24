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


/*******************************************/
/* Funções Tabela pagina invertida        */
/******************************************/

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
	this->linha[quadro].bitmodificacao=false;

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
		this->linha[quadro].bitmodificacao=false;
	}

	this->quadros_livres[quadro]=true;
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

void TabelaPaginaInvertida::imprime_endereco(int numeroprocesso,int pagina,int endereco, char* memoria){
	int i, quadro, deslocamento;

	for(i=0; i < (this->nQuadros) ;i++) {
		if(this->linha[i].processo==numeroprocesso && 
			this->linha[i].pagina==pagina && 
			this->linha[i].bitvalidade==true) {
			quadro=i;
		}
	}
	deslocamento = endereco % (int)pow(2,this->q);
	std::cout << memoria[quadro+deslocamento];
	std::cout << "\n";

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

/**********************************/
/* Funções Para tabela multinivel */
/**********************************/

void TabelaPaginaMultinivel::inicializa_quadros_livres() {
  for(int i = 0 ; i < this->nQuadros ; i++)
    this->quadros_livres[i] = true;
}


bool TabelaPaginaMultinivel::pagina_esta_mapeada(int numeroprocesso,int pagina){
	int superior, inferior;
	superior = pagina / this->nivel_base;
	inferior = pagina % this->nivel_base;

	return this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].bitvalidade;
}
int TabelaPaginaMultinivel::procura_quadro_livre(){
	int i;

	for(i = 0; i<(this->nQuadros); i++){
		if(this->quadros_livres[i] == true) {
			return i;
		}
	}
	return -1;

}
int TabelaPaginaMultinivel::descobre_quadro(int numeroprocesso,int pagina){
	int i, quadro;

	for(i=0; i < (this->nQuadros) ;i++) {
		if(this->proc[i]==numeroprocesso && 
			this->pag[i]==pagina) {
			quadro=i;
			i=this->nQuadros;
		}
	}
	return quadro;
}
void TabelaPaginaMultinivel::insere_pagina(int numeroprocesso,int pagina, int quadro, char* memoria, char** disco){
	int i, superior, inferior;

	this->quadros_livres[quadro]=false;
	this->proc[quadro]=numeroprocesso;
	this->pag[quadro]=pagina;

	superior = pagina / this->nivel_base;
	inferior = pagina % this->nivel_base;

	//Se o quadro é valido e foi modificado, devemos sobrescrevelo no disco
	if(this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].bitmodificacao==true) {		
		for(i = 0 ; i < (pow(2,this->q)) ; i++) {		
		disco[this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].processo][(int) (i+(pow(2,this->q)*this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].pagina))]=memoria[(int) (i+(pow(2,this->q)*quadro))];
		}
		this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].bitmodificacao==false;
	}

	//Depois paginamos
	this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].pagina=pagina;
	this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].processo=numeroprocesso;
	this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].bitvalidade=true;
	this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].bitmodificacao=false;



	//E subimos o conteudo do disco para a memoria
	for(i = 0 ; i < (pow(2,this->q)) ; i++) {
		memoria[(int) (i+(pow(2,this->q)*quadro))]=disco[numeroprocesso][(int) (i+(pow(2,this->q)*pagina))];
	}

}
void TabelaPaginaMultinivel::escreve_endereco(int numeroprocesso,int pagina, int endereco, char entrada, char* memoria){
	int i, quadro, deslocamento, superior, inferior;

	superior = pagina / this->nivel_base;
	inferior = pagina % this->nivel_base;

	for(i=0; i < (this->nQuadros) ;i++) {
		if(this->proc[i]==numeroprocesso && 
			this->pag[i]==pagina) {
			quadro=i;
		}
	}
	deslocamento = endereco % (int)pow(2,this->q);
	memoria[quadro+deslocamento]=entrada;

	this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].bitmodificacao=true;

}
void TabelaPaginaMultinivel::remove_pagina(int numeroprocesso,int pagina, char* memoria, char** disco){

	//Se o quadro é valido e foi modificado, devemos sobrescrevelo no disco

	int i, quadro, superior, inferior;
	superior = pagina / this->nivel_base;
	inferior = pagina % this->nivel_base;

	for(i=0; i < (this->nQuadros) ;i++) {
		if(this->proc[i]==numeroprocesso && 
			this->pag[i]==pagina) {
			quadro=i;
		}
	}

	if(this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].bitvalidade==true && this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].bitmodificacao==true) {		
		for(i = 0 ; i < (pow(2,this->q)) ; i++) {		
		disco[this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].processo][(int) (i+(pow(2,this->q)*this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].pagina))]=memoria[(int) (i+(pow(2,this->q)*quadro))];
		}
		this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].bitmodificacao=false;
	}

	this->quadros_livres[quadro]=true;
	this->proc[quadro]=-1;
	this->pag[quadro]=-1;
	this->processo[numeroprocesso]->nivelbase[superior]->linha[inferior].bitvalidade=false;

	//Apenas a titulo de debug, remover.
	for(i = 0 ; i < (pow(2,this->q)) ; i++) {
		memoria[(int) (i+(pow(2,this->q)*quadro))] = '-';
	}

}

void TabelaPaginaMultinivel::imprime_endereco(int numeroprocesso,int pagina, int endereco, char* memoria){
	int i, quadro, deslocamento, superior, inferior;

	superior = pagina / this->nivel_base;
	inferior = pagina % this->nivel_base;

	for(i=0; i < (this->nQuadros) ;i++) {
		if(this->proc[i]==numeroprocesso && 
			this->pag[i]==pagina) {
			quadro=i;
		}
	}

	deslocamento = endereco % (int)pow(2,this->q);
	std::cout << memoria[quadro+deslocamento];
	std::cout << "\n";



}
void TabelaPaginaMultinivel::imprime_tabela_pagina(){

	int i,j,k;

	for(i=0; i < (this->nprocessos) ;i++) {
		for(j=0; j < (this->nivel_topo); j++) {
			for(k=0; k < (this->nivel_base); k++) {
				std::cout << "Processo: ";
				std::cout << i;
				std::cout << " Nivel topo: ";
				std::cout << j;
				std::cout << " Linha: ";
				std::cout << k;
				std::cout << this->processo[i]->nivelbase[j]->linha[k].processo;
				std::cout << " Pagina: "; 
				std::cout << this->processo[i]->nivelbase[j]->linha[k].pagina;
				std::cout << " Validade: ";
				std::cout << this->processo[i]->nivelbase[j]->linha[k].bitvalidade;
				std::cout << " Modificação: ";
				std::cout << this->processo[i]->nivelbase[j]->linha[k].bitmodificacao;
				std::cout << "\n";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
}


/**********************************/
/* Funções Algoritimo FIFO        */
/**********************************/




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


/**********************************/
/* Funções Algoritimo LRU         */
/**********************************/

void LRU::insere_na_fila(int valor, int quantidade_acessos) {
	this->quadro[this->ocupado]=valor;
	this->tempo[this->ocupado]=quantidade_acessos;
	this->ocupado++;
}

int LRU::remove_da_fila() {
	int quadro, tempo, i;

	quadro=0;
	tempo=this->tempo[0];

	for(i=1; i<this->nQuadros; i++) {
		if(tempo<this->tempo[i]) {
			quadro=this->quadro[i];
			tempo=this->tempo[i];
		}
	}

	for(i=quadro; i<this->nQuadros; i++) {
		this->tempo[i]=this->tempo[i+1];
		this->quadro[i]=this->quadro[i+1];		
	}	

	this->ocupado--;

	return quadro;
}

void LRU::remove_da_fila(int elemento) {
	int quadro, i;

	for(i=0; i<this->nQuadros; i++) {
		if(this->quadro[i]==elemento) {
			quadro=i;
		}
	}

	for(i=quadro; i<this->nQuadros; i++) {
		this->tempo[i]=this->tempo[i+1];
		this->quadro[i]=this->quadro[i+1];		
	}	

	this->ocupado--;


}

void LRU::update_tempo(int elemento, int quantidade_acessos){
	int quadro, i;

	for(i=0; i<this->nQuadros; i++) {
		if(this->quadro[i]==elemento) {
			quadro=i;
		}
	}
	this->tempo[i]==quantidade_acessos;

}