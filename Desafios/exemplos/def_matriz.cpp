#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Teste {
public:
	int n;
	int **matriz;
	Teste(int n){
		this->n=n;
		int i;
		this->matriz = new int*[this->n];
		for(i = 0; i < this->n; i++)
			this->matriz[i] = new int[this->n];		
	}
	void imprime_matriz(){
		int i,j;
		for(i=0;i<this->n;i++){
			for(j=0;j<this->n;j++){
				cout << this->matriz[i][j] << " ";
			}
		cout << "\n";
		}
	}
};



int main(void){
	

	Teste *a;

	a = new Teste(5);

	a->imprime_matriz();

	return 0;
}