/****************************************************/
/* Augusto Ribas                                    */
/* Trabalho 1 Introdução a Bioinformatica           */
/* Professor(a): Said                               */
/****************************************************/

#include <iostream>
#include "Classes.h"


/****************************************************/
/* Funções auxiliares                               */
/****************************************************/

int main (int argc, char* argv[]) {

  /* <nome executavel> [-g,-l,-s] -u <arquivo 1a. sequencia> -v <arquivo 2a. sequencia> -i <w(a,a)> -d <w(a,b)> -e <w(-,b) ou w(a,-)>
  Nas duas linhas acima, -g, -l e -s correspondem ao tipo de alinhamento desejado (global,local e semi-global, respectivamente). 
  Ja sobre os parametros -i, -d e -e, eles correspondem aos valores atribuıdos pela funcao de pontuacao para colunas com caracteres iguais,
  diferentes e espaco, respectivamente.
  */

  int tipo_alinhamento, iguais, diferente, espaco;
  char arquivo1, arquivo2;

  for(int i=0; i<argc; i++) {
    std::cout << "Argumento " << i << " : " << argv[i] << "\n";
  }

  if(argv[1]=="-g")
    tipo_alinhamento=0;
  else if(argv[1]=="-l")
    tipo_alinhamento=1;
  else
    tipo_alinhamento=2;

  




  Rectangle rect;
  rect.set_values (3,4);
  std::cout << "area: " << rect.area() << "\n";
  return 0;
}

