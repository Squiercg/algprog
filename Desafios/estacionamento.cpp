#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>


using namespace std;

int main(){

	int acao, placa, i , contagem, presente;
	vector<int> estacionamento;
	vector<int> temporario;
	
	while(scanf("\n%d %d",&acao,&placa) != EOF) {
/*
		if(estacionamento.size()==0) {
			cout << "Estacionamento Vaziu";
		} else {
			cout << "Lista de carros: ";
			for(i=0;i<estacionamento.size();i++)
				cout << estacionamento.at(i) << " ";
		}
		cout << "\n";
*/
		//cout << estacionamento.size() << " de Tamanho\n";
		if(acao==1) {

			if(estacionamento.size()<10){
				estacionamento.push_back(placa);
				cout << "Carro estacionado" << "\n";
			} else {
				cout << "Nao ha vaga no estacionamento" << "\n";
			}
		} else {
			presente=0;

			for(i=0;i<estacionamento.size();i++){
				if(placa==estacionamento.at(i)){
					presente=1;
					i=estacionamento.size();
				}
			}

			if(presente==0){
				cout << "Carro nao encontrado" << "\n";
			} else {
				contagem=0;

				while(estacionamento.back() != placa){
					temporario.push_back(estacionamento.back());
					estacionamento.pop_back();
					contagem++;
				}

				estacionamento.pop_back();
				while(temporario.size()>0){
					estacionamento.push_back(temporario.back());
					temporario.pop_back();
				}
				

				printf("Carro liberado apos %d movimentos\n",contagem);
			}
		}
	}

	return 0;
}