#ifndef Classes_h
#define Classes_h
#include <stdio.h>
#include <queue>


/*Tabela(s) de página, onde cada linha da tabela de página deve ter pelo menos o campo número do quadro,
bit de validade e bit de modificaçaoo. Fique a vontade para adicionar outros campos que você achar conveniente;*/


//Tabela de Pagina Invertida

class LinhaTPI {
public:
	int processo;
	int pagina;
	int quadro;
	bool bitvalidade;
	bool bitmodificacao;

	LinhaTPI(): bitvalidade(false),bitmodificacao(false){}
};

class TabelaPaginaInvertida {
public:
	LinhaTPI* linha;
	bool* quadros_livres;
	int nQuadros;
	int p;
	int q;

	TabelaPaginaInvertida(int nQuadros,int p, int q){
		this->nQuadros=nQuadros;
		this->p=p;
		this->q=q;
		linha = new LinhaTPI[nQuadros];
		quadros_livres = new bool[nQuadros];
		this->inicializa_quadros_livres();
	}

	void inicializa_quadros_livres();
	bool pagina_esta_mapeada(int numeroprocesso,int pagina);
	int procura_quadro_livre();
	int descobre_quadro(int numeroprocesso,int pagina);
	void insere_pagina(int numeroprocesso,int pagina, int quadro, char* memoria, char** disco);
	void escreve_endereco(int numeroprocesso,int pagina, int endereco, char entrada, char* memoria);
	void remove_pagina(int numeroprocesso,int pagina, char* memoria, char** disco);
	void imprime_pagina(int numeroprocesso, int pagina, char* memoria);
	void imprime_endereco(int numeroprocesso,int pagina, int endereco, char* memoria);
	void imprime_tabela_pagina();
};

/**********************************/
/* Tabela de Pagina Multinivel    */
/**********************************/

class LinhaTPM {
public:
	LinhaTPM* ponteiro;
	int processo;
	int pagina;
	int quadro;
	bool bitvalidade;
	bool bitmodificacao;

	LinhaTPM(): bitvalidade(false),bitmodificacao(false){}
};


class NivelBase {
public:
	LinhaTPM* linha;

	NivelBase(int n){
		this->linha = new LinhaTPM[n];
	}
};

class NivelTopo{
public:
	NivelBase** nivelbase;

	NivelTopo(int nivel_topo, int nivel_base) {
	this->nivelbase = new NivelBase* [nivel_topo];
	for(int i=0; i<nivel_topo; i++)
		this->nivelbase[i] = new NivelBase(nivel_base);
	}
	

};

class TabelaPaginaMultinivel {
public:	
	NivelTopo** processo;
	bool* quadros_livres;
	int* proc;
	int* pag;
	int nQuadros;
	int p;
	int q;
	int nprocessos;
	int nivel_topo;
	int nivel_base;

	TabelaPaginaMultinivel(int processos, int nQuadros,int p, int q){
		int i;

		this->nprocessos = processos;
		this->nivel_topo = pow(2, (p / 2));
		this->nivel_base = pow(2, (p - (p / 2)));

		this->processo = new NivelTopo* [processos];
		for(i=0; i<processos; i++)
			this->processo[i] = new NivelTopo(nivel_topo,nivel_base);

		this->nQuadros=nQuadros;
		this->p=p;
		this->q=q;		
		this->quadros_livres = new bool[nQuadros];
		this->proc = new int[nQuadros];
		this->pag = new int[nQuadros];
		this->inicializa_quadros_livres();
	}

	void inicializa_quadros_livres();
	bool pagina_esta_mapeada(int numeroprocesso,int pagina);
	int procura_quadro_livre();
	int descobre_quadro(int numeroprocesso,int pagina);
	void insere_pagina(int numeroprocesso,int pagina, int quadro, char* memoria, char** disco);
	void escreve_endereco(int numeroprocesso,int pagina, int endereco, char entrada, char* memoria);
	void remove_pagina(int numeroprocesso,int pagina, char* memoria, char** disco);	
	void imprime_endereco(int numeroprocesso,int pagina, int endereco, char* memoria);
	void imprime_tabela_pagina();
};





//FIFO

class FIFO {
public:
	std::queue<int> fila;

	void insere_na_fila(int elemento);
	int remove_da_fila();
	void remove_da_fila(int elemento);

};


class LRU {
public:
	int* quadro;
	int* tempo;
	int ocupado;
	int nQuadros;

	LRU(int nQuadros){
		this->quadro = new int[nQuadros];		
		this->tempo = new int[nQuadros];

		this->nQuadros = nQuadros;
		this->ocupado = 0;
		for(int i=0; i<nQuadros; i++){
			this->quadro[i]=-1;
			this->tempo[i]=-1;
		}
	}

	void insere_na_fila(int elemento, int quantidade_acessos);
	int remove_da_fila();
	void remove_da_fila(int elemento);
	void update_tempo(int quadro, int quantidade_acessos);

};

/*Lista de quadros livres, que informa, para cada quadro da memória, se ele está livre ou ocupado;*/

/*Vetor memória, que é um vetor de bytes que armazenar de fato as páginas de cada processo;*/

/*Vetor ou matriz disco, que deve simular o conteúdo do disco de cada processo. Para simplificar a programaçao,
assuma que todo o espaço de endereçamento virtual de cada processo está preenchido.
O conteúdo do espaço de endereçamento virtual pode ser gerado de maneira aleatria.*/

#endif
