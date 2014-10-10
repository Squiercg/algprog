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

void TabelaPaginaInvertida::imprime_conteudo(char* memoria) {
int i;

	std::cout << "\n";


	for(i = inicio; i < fim ; i++)
		std::cout << memoria[i];	

	std::cout << "\n";
}

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

 int Rectangle::area() {return width*height;}