#ifndef Classes_h
#define Classes_h


/*Tabela(s) de página, onde cada linha da tabela de página deve ter pelo menos o campo número do quadro,
bit de validade e bit de modificaçaoo. Fique a vontade para adicionar outros campos que você achar conveniente;*/

class TabelaPagina {
public:
	int numeroQuadro;
	bool bitvalidade;
	bool bitmodificacao;
};

class TabelaPaginaInvertida {
public:
	int processo;
	int pagina;
	int quadro;
	bool bitvalidade;
	bool bitmodificacao;
	int inicio;
	int fim;

TabelaPaginaInvertida(): bitvalidade(false),bitmodificacao(false){}
void imprime_conteudo(char* memoria);


};

/*Lista de quadros livres, que informa, para cada quadro da memória, se ele está livre ou ocupado;*/

/*Vetor memória, que é um vetor de bytes que armazenar de fato as páginas de cada processo;*/

/*Vetor ou matriz disco, que deve simular o conteúdo do disco de cada processo. Para simplificar a programaçao,
assuma que todo o espaço de endereçamento virtual de cada processo está preenchido.
O conteúdo do espaço de endereçamento virtual pode ser gerado de maneira aleatria.*/


class Rectangle {
    
  public:
  	int width, height;
    void set_values (int,int);
    int area(); 

};



#endif
