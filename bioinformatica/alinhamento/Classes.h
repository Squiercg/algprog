/****************************************************/
/* Augusto Ribas                                    */
/* Trabalho 1 Introdução a Bioinformatica           */
/* Professor(a): Said                               */
/****************************************************/

#include <iostream>
#include <string>

using namespace std;

#ifndef Classes_h
#define Classes_h

class Sequencia {
public:
	string sequencia;
	string identificador;
	string outros;

	Sequencia(char* arquivo);
	int tamanho();

};

class Alinhamento {
public:
	Sequencia* seq1;
	Sequencia* seq2;
	string alinhamento1;
	string alinhamento2;
	int** matriz_score;
	int linhas;
	int colunas;
	int igual;
	int diferente;
	int espaco;
	int tipo;
	int similaridade;

	Alinhamento(Sequencia* seq1, Sequencia* seq2, char tipo ,int igual, int diferente, int espaco);	
	void imprime_matriz();
	void imprime_alinhamento();

private:
	void inicia_matriz_g();
	void preenche_matriz_g(Sequencia* seq1, Sequencia* seq2);
	void volta_matriz_g(Sequencia* seq1, Sequencia* seq2);

	void inicia_matriz_l();
	void preenche_matriz_l(Sequencia* seq1, Sequencia* seq2);
	void volta_matriz_l(Sequencia* seq1, Sequencia* seq2);

	void inicia_matriz_s();
	void preenche_matriz_s(Sequencia* seq1, Sequencia* seq2);
	void volta_matriz_s(Sequencia* seq1, Sequencia* seq2);
};



#endif