/****************************************************/
/* Augusto Ribas                                    */
/* Trabalho 1 Introdução a Bioinformatica           */
/* Professor(a): Said                               */
/****************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "Classes.h"

using namespace std;

int main (int argc, char* argv[]) {

  int igual, diferente, espaco, i, arq1, arq2;
  char tipo_alinhamento;
     

  for(i=0;i<argc;i++) {
    if(string(argv[1])==("-g")) {
      tipo_alinhamento='g';
      i=argc;
    }
    if(string(argv[1])==("-l")) {
      tipo_alinhamento='l';
      i=argc;
    }
    if(string(argv[1])==("-s")) {
      tipo_alinhamento='s';
      i=argc;
    }
  }
  

  for(i=0; string(argv[i])!=("-u") ;i++);
  arq1=i+1;
  for(i=0; string(argv[i])!=("-v") ;i++);
  arq2=i+1;

  for(i=0; string(argv[i])!=("-i") ;i++);
  sscanf (argv[i+1],"%d",&igual);

  for(i=0; string(argv[i])!=("-d") ;i++);
  sscanf (argv[i+1],"%d",&diferente);

  for(i=0; string(argv[i])!=("-e") ;i++);
  sscanf (argv[11],"%d",&espaco);

  Sequencia* seq1 = new Sequencia(argv[arq1]);
  Sequencia* seq2 = new Sequencia(argv[arq2]);

  Alinhamento* alinhamento = new Alinhamento(seq1,seq2,tipo_alinhamento,igual,diferente,espaco);
   
}