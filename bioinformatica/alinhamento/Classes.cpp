/****************************************************/
/* Augusto Ribas                                    */
/* Trabalho 1 Introdução a Bioinformatica           */
/* Professor(a): Said                               */
/****************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <limits.h>

#include "Classes.h"

Sequencia::Sequencia(char* arquivo){

	this->sequencia="";
	string linha;
	ifstream myfile (arquivo);	

	if (myfile.is_open()) {

		getline (myfile,linha);

		this->identificador = linha.substr(1, linha.find(' '));
		this->outros = linha.substr(linha.find(' ')+1);

		while ( getline (myfile,linha) ) {			
			this->sequencia += linha;
		}

		if(this->sequencia.find('\n')!=-1){
		 cout << "achou \n";
		}

    myfile.close();
    } else {
    	cout << "Unable to open file"; 
    }

}

int Sequencia::tamanho(){
	return this->sequencia.size();
}

Alinhamento::Alinhamento(Sequencia* seq1, Sequencia* seq2,char tipo, int igual, int diferente, int espaco){
	this->seq1=seq1;
	this->seq2=seq2;
	this->alinhamento1 = "";
    this->alinhamento2 = "";
	this->linhas = (seq1->tamanho()+1);
	this->colunas = (seq2->tamanho()+1);
	this->igual=igual;
	this->diferente=diferente;
	this->espaco=espaco;
	this->tipo=tipo;

	if(this->tipo == 'g') {		
		inicia_matriz_g();
		preenche_matriz_g(seq1,seq2);
		volta_matriz_g(seq1,seq2);
	} else {
		if(this->tipo == 'l') {
			inicia_matriz_l();
			preenche_matriz_l(seq1,seq2);
			volta_matriz_l(seq1,seq2);
		} else {
			inicia_matriz_s();
			preenche_matriz_s(seq1,seq2);
			volta_matriz_s(seq1,seq2);
		}
	}

    //imprime_matriz();    
    imprime_alinhamento();

}

void Alinhamento::inicia_matriz_g(){
	int i;

	this->matriz_score = new int*[this->linhas];
	for(i = 0; i < this->linhas; i++)
		this->matriz_score[i] = new int[this->colunas];

	for (i = 0; i < this->linhas; i++)
		this->matriz_score[i][0] = i*this->espaco;

	for (i = 0; i < this->colunas; i++)
		this->matriz_score[0][i] = i*this->espaco;

}

void Alinhamento::preenche_matriz_g(Sequencia* seq1, Sequencia* seq2){

	int i,j,diagonal,esquerda,cima,maximo;

	for (i = 1; i < this->linhas; i++) {
		for (j = 1; j < this->colunas; j++) {
			diagonal = 0;

			if (seq1->sequencia.at(i-1)==seq2->sequencia.at(j - 1))
				diagonal = this->matriz_score[i - 1][ j - 1] + this->igual;
			else
				diagonal = this->matriz_score[i - 1][ j - 1] + this->diferente;

			esquerda = this->matriz_score[i][j-1] + this->espaco;
			cima = this->matriz_score[i-1][j] + this->espaco;

			maximo = max(max(diagonal, esquerda), cima);

			this->matriz_score[i][j] = maximo;
		}
    }

    this->similaridade = matriz_score[this->linhas-1][this->colunas-1];

}

void Alinhamento::volta_matriz_g(Sequencia* seq1, Sequencia* seq2){
    int m = seq1->tamanho();
    int n = seq2->tamanho();
    int diagonal;

    while (m > 0 && n > 0) {
    	diagonal = 0;
    	
    	if (seq1->sequencia.at(m - 1) == seq2->sequencia.at(n - 1))
    		diagonal = this->igual;
    	else
    		diagonal = this->diferente;

    	if (m > 0 && n > 0 && this->matriz_score[m][n] == this->matriz_score[m - 1][ n - 1] + diagonal) {
    		this->alinhamento1 = seq1->sequencia.at(m - 1) + this->alinhamento1;
    		this->alinhamento2 = seq2->sequencia.at(n - 1) + this->alinhamento2;    		
    		m = m - 1;
    		n = n - 1;
    	} else if (n > 0 && this->matriz_score[m][n] == this->matriz_score[m][n - 1] + this->espaco) {
    		this->alinhamento1 = '-' + this->alinhamento1;
    		this->alinhamento2 = seq2->sequencia.at(n - 1) + this->alinhamento2;    		
    		n = n - 1;
    	} else {
    		this->alinhamento1 = seq1->sequencia.at(m - 1) + this->alinhamento1;
    		this->alinhamento2 = '-' + this->alinhamento2;    		
    		m = m - 1;
    	}
    }

    while(n>0) {
    	this->alinhamento1 = '-' + this->alinhamento1;
    	this->alinhamento2 = seq2->sequencia.at(n - 1) + this->alinhamento2;    	
    	n = n - 1;
    }

    while(m>0) {
    	this->alinhamento1 = seq1->sequencia.at(m - 1) + this->alinhamento1;
    	this->alinhamento2 = '-' + this->alinhamento2;    	
    	m = m - 1;
    }

}

void Alinhamento::inicia_matriz_l(){
	int i;

	this->matriz_score = new int*[this->linhas];
	for(i = 0; i < this->linhas; i++)
		this->matriz_score[i] = new int[this->colunas];

	for (i = 0; i < this->linhas; i++)
		this->matriz_score[i][0] = 0;

	for (i = 0; i < this->colunas; i++)
		this->matriz_score[0][i] = 0;

}

void Alinhamento::preenche_matriz_l(Sequencia* seq1, Sequencia* seq2){

	int i,j,diagonal,esquerda,cima,maximo;
	this->similaridade=0;

	for (i = 1; i < this->linhas; i++) {
		for (j = 1; j < this->colunas; j++) {
			diagonal = 0;

			if (seq1->sequencia.at(i-1)==seq2->sequencia.at(j - 1))
				diagonal = this->matriz_score[i - 1][ j - 1] + this->igual;
			else
				diagonal = this->matriz_score[i - 1][ j - 1] + this->diferente;

			esquerda = this->matriz_score[i][j-1] + this->espaco;
			cima = this->matriz_score[i-1][j] + this->espaco;


			maximo = max(max(max(diagonal, esquerda), cima),0);
			this->matriz_score[i][j] = maximo;

			if(maximo>this->similaridade)
				this->similaridade=maximo;
		}
    }
}

void Alinhamento::volta_matriz_l(Sequencia* seq1, Sequencia* seq2){

	int i,j,k,l;
	for (i = 1; i < this->linhas; i++) {
		for (j = 1; j < this->colunas; j++) {
			if(this->matriz_score[i][j]==this->similaridade) {
				k=i;
				l=j;
			}
		}
	}

    int m = k;
    int n = l;
    int diagonal;      

    while (m > 0 && n > 0 && this->matriz_score[m][n]!=0) {
    	diagonal = 0;
    	
    	if (seq1->sequencia.at(m - 1) == seq2->sequencia.at(n - 1))
    		diagonal = this->igual;
    	else
    		diagonal = this->diferente;

    	if (m > 0 && n > 0 && this->matriz_score[m][n] == this->matriz_score[m - 1][ n - 1] + diagonal) {
    		this->alinhamento1 = seq2->sequencia.at(n - 1) + this->alinhamento1;
    		this->alinhamento2 = seq1->sequencia.at(m - 1) + this->alinhamento2;
    		m = m - 1;
    		n = n - 1;
    	} else if (n > 0 && this->matriz_score[m][n] == this->matriz_score[m][n - 1] + this->espaco) {
    		this->alinhamento1 = seq2->sequencia.at(n - 1) + this->alinhamento1;
    		this->alinhamento2 = '-' + this->alinhamento2;
    		n = n - 1;
    	} else {    	
    		this->alinhamento1 = '-' + this->alinhamento1;
    		this->alinhamento2 = seq1->sequencia.at(m - 1) + this->alinhamento2;
    		m = m - 1;
    	}
    }
}

void Alinhamento::inicia_matriz_s(){
	int i;

	this->matriz_score = new int*[this->linhas];
	for(i = 0; i < this->linhas; i++)
		this->matriz_score[i] = new int[this->colunas];

	for (i = 0; i < this->linhas; i++)
		this->matriz_score[i][0] = 0;

	for (i = 0; i < this->colunas; i++)
		this->matriz_score[0][i] = 0;

}

void Alinhamento::preenche_matriz_s(Sequencia* seq1, Sequencia* seq2){

	int i,j,diagonal,esquerda,cima,maximo;
	this->similaridade=INT_MIN;

	for (i = 1; i < this->linhas; i++) {
		for (j = 1; j < this->colunas; j++) {
			diagonal = 0;

			if (seq1->sequencia.at(i-1)==seq2->sequencia.at(j - 1))
				diagonal = this->matriz_score[i - 1][ j - 1] + this->igual;
			else
				diagonal = this->matriz_score[i - 1][ j - 1] + this->diferente;

			esquerda = this->matriz_score[i][j-1] + this->espaco;
			cima = this->matriz_score[i-1][j] + this->espaco;


			maximo = max(max(diagonal, esquerda), cima);
			this->matriz_score[i][j] = maximo;

			if(maximo>this->similaridade)
				this->similaridade=maximo;
		}
    }
}

void Alinhamento::volta_matriz_s(Sequencia* seq1, Sequencia* seq2){

	int i,j,k,l,m,n,diagonal,sim;
	sim=INT_MIN;

	for (i = 0; i < this->linhas; i++) {
		if(this->matriz_score[i][(this->colunas-1)]>sim) {
			sim=this->matriz_score[i][(this->colunas-1)];
			k=i;
			l=(this->colunas-1);
		}
	}

	for (j = 0; j < this->colunas; j++) {
		if(this->matriz_score[(this->linhas-1)][j]>sim) {
			sim=this->matriz_score[(this->linhas-1)][j];
			k=(this->linhas-1);
			l=j;
		}
	}

	if(k==(this->linhas-1)){
		for(i=this->colunas-1;i>l;i--) {
			this->alinhamento1 = seq2->sequencia.at(i - 1) + this->alinhamento1;
			this->alinhamento2 = '-' + this->alinhamento2;
		}
	}	

	if(l==(this->colunas-1)){
		for(i=this->linhas-1;i>k;i--){
			this->alinhamento1 = seq1->sequencia.at(i-1) + this->alinhamento1;
			this->alinhamento2 = '-' + this->alinhamento2;
		} 
    }

    m = k;
    n = l;
    diagonal;

    while (m > 0 && n > 0) {
    	diagonal = 0;
    	
    	if (seq1->sequencia.at(m - 1) == seq2->sequencia.at(n - 1))
    		diagonal = this->igual;
    	else
    		diagonal = this->diferente;

    	if (m > 0 && n > 0 && this->matriz_score[m][n] == this->matriz_score[m - 1][ n - 1] + diagonal) {
    		this->alinhamento1 = seq1->sequencia.at(m - 1) + this->alinhamento1;
    		this->alinhamento2 = seq2->sequencia.at(n - 1) + this->alinhamento2;    		
    		m = m - 1;
    		n = n - 1;
    	} else if (n > 0 && this->matriz_score[m][n] == this->matriz_score[m][n - 1] + this->espaco) {
    		this->alinhamento1 = '-' + this->alinhamento1;
    		this->alinhamento2 = seq2->sequencia.at(n - 1) + this->alinhamento2;    		
    		n = n - 1;
    	} else {
    		this->alinhamento1 = seq1->sequencia.at(m - 1) + this->alinhamento1;
    		this->alinhamento2 = '-' + this->alinhamento2;    		
    		m = m - 1;
    	}
    }

    while(n>0) {
    	this->alinhamento1 = '-' + this->alinhamento1;
    	this->alinhamento2 = seq2->sequencia.at(n - 1) + this->alinhamento2;    	
    	n = n - 1;
    }

    while(m>0) {
    	this->alinhamento1 = seq1->sequencia.at(m - 1) + this->alinhamento1;
    	this->alinhamento2 = '-' + this->alinhamento2;    	
    	m = m - 1;
    }

}

void Alinhamento::imprime_matriz(){
	int i, j;

	cout << "\nMatriz de scores\n";

	for (i = 0; i < this->linhas; i++) {
		for (j = 0; j < this->colunas; j++) {
			printf("%4d ",this->matriz_score[i][j]);
		}
		cout << "\n";
	}
	cout << "\n";
}

void Alinhamento::imprime_alinhamento(){
	int i,n,a;
	string nome1, nome2;

	/*Tratando os nomes*/

	if(this->seq1->identificador.size()>this->seq2->identificador.size()){
		nome1=this->seq1->identificador;
		nome2=this->seq2->identificador;
		for(i=0 ; i < (this->seq1->identificador.size()-this->seq2->identificador.size()) ; i++)
			nome2 += ' ';
	} else {
		nome1=this->seq1->identificador;
		nome2=this->seq2->identificador;
		for(i=0 ; i < (this->seq2->identificador.size()-this->seq1->identificador.size()) ; i++)
			nome1 += ' ';
	}


	n=0;
	do{

		n+=30;

		cout << "\n";
		cout << nome1 <<": ";
		for(i=(n-30); i < (this->alinhamento1.size()) && i<n; i++) {
			cout << this->alinhamento1.at(i);
		}

		cout << "\n";

		for(i=0 ; i < nome1.size()+2 ; i++) cout << ' ';
		for(i=(n-30) ; i < (this->alinhamento1.size()) && i<n ; i++) {
			if(this->alinhamento1.at(i)==this->alinhamento2.at(i) && this->alinhamento1.at(i) !='-' && this->alinhamento2.at(i) !='-')
				cout << "|";
			else if(this->alinhamento1.at(i)=='-' || this->alinhamento2.at(i)=='-')
				cout << " ";
			else
				cout << "!";
		}

		cout << "\n";
		cout << nome2 <<": ";
		for(i=(n-30); i < (this->alinhamento2.size()) && i<n; i++) {
			cout << this->alinhamento2.at(i);
		}

		cout << "\n";
		
	} while(n<this->alinhamento1.size());

	cout << "\nSimilaridade: " << this->similaridade << "\n";
}




