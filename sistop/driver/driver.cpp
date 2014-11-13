#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
#define TAMANHO_LOTE 5

using namespace std;

void insertionsortR(int *vetor, int n) {
  int i, aux;

  if(n>1) {
    insertionsortR(vetor,n-1);
    aux=vetor[n-1];
    i=n-1;
    while(vetor[i-1]>aux && i>=0 ) {
      vetor[i]=vetor[i-1];
      i--;
     }
    vetor[i]=aux;
  }
}

class FCFS {
public:	
	vector<int> ordem_de_atendimento;
	int cabecote;
	int cilindros_percorridos;


	FCFS(const char* nome_arquivo_requisicoes, const char* nome_arquivo_cabecote) {
		this->cilindros_percorridos=0;

		vector<int> vetor_requisicoes;
		string valor_str;
		int valor, n;
		int vetor[TAMANHO_LOTE];


		ifstream arquivo(nome_arquivo_requisicoes);

		if (arquivo.is_open()) {
			while ( getline (arquivo,valor_str) ) {
				if(valor_str != "")
					vetor_requisicoes.push_back(atoi(valor_str.c_str()));
			}
			arquivo.close();
		} else {
			cout << "Não foi possível abrir o arquivo de requisicoes"; 
		}

		arquivo.open (nome_arquivo_cabecote, std::ifstream::in);

		if (arquivo.is_open()) {
			getline (arquivo,valor_str);
			this->cabecote=atoi(valor_str.c_str());
			arquivo.close();
		} else {
			cout << "Não foi possível abrir o arquivo com a posicao do cabecote"; 
		}

		while(vetor_requisicoes.size()) {
			n=0;
			for(int i=0;i<TAMANHO_LOTE && vetor_requisicoes.size()>0;i++){
				vetor[i]=vetor_requisicoes.at(0);				
				vetor_requisicoes.erase(vetor_requisicoes.begin());
				n++;
			}
			processa_lote(vetor,n);
		}
	}

private:
	void processa_lote(int* requisicoes, int n) {
		for (int i = 0; i < n; i++) {
			this->cilindros_percorridos += abs(requisicoes[i] - this->cabecote);
			this->ordem_de_atendimento.push_back(requisicoes[i]);
			this->cabecote = requisicoes[i];
		}
	}
};


class STFS {
public:	
	vector<int> ordem_de_atendimento;
	int cabecote;
	int cilindros_percorridos;


	STFS(const char* nome_arquivo_requisicoes, const char* nome_arquivo_cabecote) {
		this->cilindros_percorridos=0;

		vector<int> vetor_requisicoes;
		string valor_str;
		int valor, n;
		int vetor[TAMANHO_LOTE];


		ifstream arquivo(nome_arquivo_requisicoes);

		if (arquivo.is_open()) {
			while ( getline (arquivo,valor_str) ) {
				if(valor_str != "")
					vetor_requisicoes.push_back(atoi(valor_str.c_str()));
			}
			arquivo.close();
		} else {
			cout << "Não foi possível abrir o arquivo de requisicoes"; 
		}

		arquivo.open (nome_arquivo_cabecote, std::ifstream::in);

		if (arquivo.is_open()) {
			getline (arquivo,valor_str);
			this->cabecote=atoi(valor_str.c_str());
			arquivo.close();
		} else {
			cout << "Não foi possível abrir o arquivo com a posicao do cabecote"; 
		}

		while(vetor_requisicoes.size()) {
			n=0;
			for(int i=0;i<TAMANHO_LOTE && vetor_requisicoes.size()>0;i++){
				vetor[i]=vetor_requisicoes.at(0);				
				vetor_requisicoes.erase(vetor_requisicoes.begin());
				n++;
			}
			processa_lote(vetor,n);
		}
	}

private:
	void processa_lote(int *requisicoes, int n) {
		int posicao;
		while(n > 0){
			posicao = procura_mais_perto(requisicoes, n);
			this->cilindros_percorridos += abs(requisicoes[posicao]- this->cabecote);
			this->ordem_de_atendimento.push_back(requisicoes[posicao]);
			this->cabecote = requisicoes[posicao];
			for(int i = posicao; i < n; i++){
				requisicoes[i] = requisicoes[i + 1];
			}
			n--;
		}
	}

	int procura_mais_perto(int *requisicoes, int n){
		int i, saida = 0, distancia;
		distancia = abs(this->cabecote - requisicoes[0]);
		for (i = 1; i < n; i++){
			if(abs(this->cabecote - requisicoes[i]) < distancia){
				distancia = abs(this->cabecote - requisicoes[i]);
				saida = i;
			}
		}
		return saida;
	}
};

class C_SCAN {
public:	
	vector<int> ordem_de_atendimento;
	int cabecote;
	int cilindros_percorridos;


	C_SCAN(const char* nome_arquivo_requisicoes, const char* nome_arquivo_cabecote) {
		this->cilindros_percorridos=0;

		vector<int> vetor_requisicoes;
		string valor_str;
		int valor, n;
		int vetor[TAMANHO_LOTE];


		ifstream arquivo(nome_arquivo_requisicoes);

		if (arquivo.is_open()) {
			while ( getline (arquivo,valor_str) ) {
				if(valor_str != "")
					vetor_requisicoes.push_back(atoi(valor_str.c_str()));
			}
			arquivo.close();
		} else {
			cout << "Não foi possível abrir o arquivo de requisicoes"; 
		}

		arquivo.open (nome_arquivo_cabecote, std::ifstream::in);

		if (arquivo.is_open()) {
			getline (arquivo,valor_str);
			this->cabecote=atoi(valor_str.c_str());
			arquivo.close();
		} else {
			cout << "Não foi possível abrir o arquivo com a posicao do cabecote"; 
		}

		while(vetor_requisicoes.size()) {
			n=0;
			for(int i=0;i<TAMANHO_LOTE && vetor_requisicoes.size()>0;i++){
				vetor[i]=vetor_requisicoes.at(0);				
				vetor_requisicoes.erase(vetor_requisicoes.begin());
				n++;
			}
			insertionsortR(vetor,n);
			processa_lote(vetor,n);
		}
	}

private:
	void processa_lote(int* requisicoes, int n) {

		int i, m;

		for (i = 0; (requisicoes[i] < this->cabecote) && (i < n); i++);
	    m = i;

	    if(i == n) {
	    	i=n-1;
		    while (i >= 0){
		    	this->cilindros_percorridos += abs(this->cabecote - requisicoes[i]);
		    	this->ordem_de_atendimento.push_back(requisicoes[i]);
		    	this->cabecote = requisicoes[i];
		    	i--;
		    }

		} else {
			while (i >= 0){
		    	this->cilindros_percorridos += abs(this->cabecote - requisicoes[i]);
		    	this->ordem_de_atendimento.push_back(requisicoes[i]);
		    	this->cabecote = requisicoes[i];
		    	i--;
		    }

		    this->cilindros_percorridos += abs(this->cabecote - 0);
		    this->cilindros_percorridos += abs(this->cabecote - 1999);
		    this->cabecote=1999;
		    

		    i = n-1; //recebe o final do vetor;
		    while (i > m){
		    	this->cilindros_percorridos += abs(this->cabecote - requisicoes[i]);
		    	this->ordem_de_atendimento.push_back(requisicoes[i]);	    	
		    	this->cabecote = requisicoes[i];
		    	i--;
		    }
		}
	}
};

class C_LOOK {
public:	
	vector<int> ordem_de_atendimento;
	int cabecote;
	int cilindros_percorridos;


	C_LOOK(const char* nome_arquivo_requisicoes, const char* nome_arquivo_cabecote) {
		this->cilindros_percorridos=0;

		vector<int> vetor_requisicoes;
		string valor_str;
		int valor, n;
		int vetor[TAMANHO_LOTE];


		ifstream arquivo(nome_arquivo_requisicoes);

		if (arquivo.is_open()) {
			while ( getline (arquivo,valor_str) ) {
				if(valor_str != "")
					vetor_requisicoes.push_back(atoi(valor_str.c_str()));
			}
			arquivo.close();
		} else {
			cout << "Não foi possível abrir o arquivo de requisicoes"; 
		}

		arquivo.open (nome_arquivo_cabecote, std::ifstream::in);

		if (arquivo.is_open()) {
			getline (arquivo,valor_str);
			this->cabecote=atoi(valor_str.c_str());
			arquivo.close();
		} else {
			cout << "Não foi possível abrir o arquivo com a posicao do cabecote"; 
		}

		while(vetor_requisicoes.size()) {
			n=0;
			for(int i=0;i<TAMANHO_LOTE && vetor_requisicoes.size()>0;i++){
				vetor[i]=vetor_requisicoes.at(0);				
				vetor_requisicoes.erase(vetor_requisicoes.begin());
				n++;
			}
			insertionsortR(vetor,n);
			processa_lote(vetor,n);
		}
	}

private:
	void processa_lote(int* requisicoes, int n) {
		int i, m;

		for (i = 0; (requisicoes[i] < this->cabecote) && (i < n); i++);
	    m = i;

	    if(i == n) {
	    	i=n-1;
		    while (i >= 0){
		    	this->cilindros_percorridos += abs(this->cabecote - requisicoes[i]);
		    	this->ordem_de_atendimento.push_back(requisicoes[i]);
		    	this->cabecote = requisicoes[i];
		    	i--;
		    }

		} else {
			while (i >= 0){
		    	this->cilindros_percorridos += abs(this->cabecote - requisicoes[i]);
		    	this->ordem_de_atendimento.push_back(requisicoes[i]);
		    	this->cabecote = requisicoes[i];
		    	i--;
		    }

		    this->cilindros_percorridos += abs(this->cabecote - requisicoes[n-1]);
		    this->cabecote=requisicoes[n-1];		    

		    i = n-1; //recebe o final do vetor;
		    while (i > m){
		    	this->cilindros_percorridos += abs(this->cabecote - requisicoes[i]);
		    	this->ordem_de_atendimento.push_back(requisicoes[i]);	    	
		    	this->cabecote = requisicoes[i];
		    	i--;
		    }		    
		}

	}
};


 
int main() {
	int menor;
	const char *nome_arquivo_requisicoes="requisicoes.txt";
	const char *nome_arquivo_cabecote="cabecote.txt";

	FCFS* fcfs;
	fcfs = new FCFS(nome_arquivo_requisicoes,nome_arquivo_cabecote);

	cout << "Cilindos percorridos pelo FCFS: " << fcfs->cilindros_percorridos << "\n";

	/*
	for(int i=0; i < fcfs->ordem_de_atendimento.size(); i++)
		cout << fcfs->ordem_de_atendimento.at(i) << " ";
	cout << "\n";
	*/


	STFS* stfs;
	stfs = new STFS(nome_arquivo_requisicoes,nome_arquivo_cabecote);

	cout << "Cilindos percorridos pelo STFS: " << stfs->cilindros_percorridos << "\n";

	/*
	for(int i=0; i < stfs->ordem_de_atendimento.size(); i++)
		cout << stfs->ordem_de_atendimento.at(i) << " ";
	cout << "\n";
	*/


	C_SCAN* c_scan;
	c_scan = new C_SCAN(nome_arquivo_requisicoes,nome_arquivo_cabecote);

	cout << "Cilindos percorridos pelo C_SCAN: " << c_scan->cilindros_percorridos << "\n";

    /*
	for(int i=0; i < c_scan->ordem_de_atendimento.size(); i++)
		cout << c_scan->ordem_de_atendimento.at(i) << " ";
	cout << "\n";
	*/

	C_LOOK* c_look;
	c_look = new C_LOOK(nome_arquivo_requisicoes,nome_arquivo_cabecote);

	cout << "Cilindos percorridos pelo C_LOOK: " << c_look->cilindros_percorridos << "\n";


	/*
	for(int i=0; i < c_look->ordem_de_atendimento.size(); i++)
		cout << c_look->ordem_de_atendimento.at(i) << " ";
	cout << "\n";
	*/

	menor=min(fcfs->cilindros_percorridos,min(stfs->cilindros_percorridos,min(c_scan->cilindros_percorridos,c_look->cilindros_percorridos)));

	ofstream arquivo;
	arquivo.open (nome_arquivo_cabecote);

	if(menor==fcfs->cilindros_percorridos) {		
		cout << "O Melhor algoritimo foi FCFS\n";		
		arquivo << fcfs->cabecote;
	} else if(menor==stfs->cilindros_percorridos) {		
		cout << "O Melhor algoritimo foi STFS\n";
		arquivo << stfs->cabecote;
	}else if(menor==c_scan->cilindros_percorridos) {
		cout << "O Melhor algoritimo foi C-Scan\n";
		arquivo << c_scan->cabecote;
	} else {		
		cout << "O Melhor algoritimo foi C-Look\n";
		arquivo << c_look->cabecote;
	}
	arquivo.close();

	cout << "Fim do programa. Beep! Beep!" << endl;
}