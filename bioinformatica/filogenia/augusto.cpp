#include <iostream>
using namespace std;


class Matriz_Caracteristicas{
public:
  int linhas;
  int colunas;
  int** matriz;
  int* id_caracteristicas;

  Matriz_Caracteristicas(int lin, int col) {
    this->linhas = lin;
    this->colunas = col;
    int i,j;
    this->matriz = new int*[this->linhas];
    for(i = 0; i < this->linhas; i++)
      this->matriz[i] = new int[this->colunas];

    for(i=0;i<this->linhas;i++){
      for(j=0;j<this->colunas;j++){
	cin >> this->matriz[i][j];
      }
    }
  } //Fim do construtor

  void imprime_matriz(){
    int i, j;
    for(i=0;i<this->linhas;i++){
      for(j=0;j<this->colunas;j++){
	cout << this->matriz[i][j] <<" ";
      }
      cout << "\n";
    }
  }

  bool permite_filogenia() {
    int i , j;
    bool saida = true;

    for(i=0;i<(this->colunas-1);i++) {
      for(j=i+1;j<this->colunas;j++){
	if(intersecao_vazia(i,j)==false){
	  if(subconjunto(i,j)==false && subconjunto(j,i)==false) {
	    saida=false;
	  }
	}
      }
    }
    return saida;
  }

  void constroi_filogenia() {
    ordena_matriz();
  }




private:
  bool intersecao_vazia(int a, int b) {
    int i;
    for(i=0;i<this->linhas;i++) {
      if(this->matriz[i][a]==1 && this->matriz[i][b] == 1)
	return true;
    }
    return false;
  }

  //O "a" é um subconjunto de "b"?
  bool subconjunto(int a, int b) {
    int i;
    for(i=0;i<this->linhas;i++) {
      if(this->matriz[i][a]==1 && this->matriz[i][b] == 0)
	return false;
    }
    return true;
  }

  void ordena_matriz() {
    int i, j, k, aux_soma, aux_id;
    int* aux_coluna;
    int* soma;


    soma = new int[this->colunas];
    id_caracteristicas = new int[this->colunas];
    aux_coluna = new int[this->linhas];

    //iniciando o vetor
    for(i=0;i<this->colunas;i++) {
      soma[i]=0;
      id_caracteristicas[i]=i+1;
    }


    //somando as colunas
    for(i=0;i<this->colunas;i++){
      for(j=0;j<this->linhas;j++){
	soma[i]=soma[i]+this->matriz[j][i];
      }
    }
    //insertion sort para as colunas, usando o vetor soma de guia
    for(i=1;i<this->colunas;i++) {
      aux_soma=soma[i];
      aux_id=id_caracteristicas[i];
      for(k=0;k<this->linhas;k++)
	aux_coluna[k]=this->matriz[k][i];
      j=i-1;

      while(j>=0 && soma[j]<=aux_soma) {
	soma[j+1]=soma[j];
	id_caracteristicas[j+1]=id_caracteristicas[j];
	for(k=0;k<this->linhas;k++)
	  this->matriz[k][j+1]=this->matriz[k][j];
	j=j-1;
      }
      
      soma[j+1]=aux_soma;
      id_caracteristicas[j+1]=aux_id;
      for(k=0;k<this->linhas;k++)
	this->matriz[k][j+1]=aux_coluna[k];
    }
  }
};

int main(void) {
  int i,j;
  cin >> i;
  cin >> j;
  cout << "i: " << i << " j: "<< j << "\n";

  Matriz_Caracteristicas* matriz = new Matriz_Caracteristicas(i,j);

  //matriz->imprime_matriz();
  if(matriz->permite_filogenia()) {
    cout << "filogenia perfeita existe\n";
  } else {
    cout << "filogenia perfeita nao existe\n";
  }

  matriz->constroi_filogenia();
  matriz->imprime_matriz();

  cout << "Hello World!" << "\n";
}




