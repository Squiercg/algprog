#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>


using namespace std;


int main(){

	int i, aux;
	vector<int> lista;
	
	cout << lista.size() << "\n";

	lista.push_back(1);
	lista.push_back(2);
	lista.push_back(3);

	for(i=0;i<lista.size();i++)
		cout << lista.at(i) << " ";
	cout << "\n";


	aux = lista.size();
	for(i=0;i<aux;i++){
		cout << lista.back() << " ";
		lista.pop_back();
	}
	cout << "\n";

	lista.push_back(1);
	lista.push_back(2);
	lista.push_back(3);

	aux = lista.size();
	for(i=0;i<aux;i++){
		cout << lista.at(0) << " ";
		lista.erase(lista.begin());
	}
	cout << "\n";

	vector<int> myvector;
	vector<int>::iterator it;
	it = myvector.begin();
	it = myvector.insert ( it , 1 );
	it = myvector.insert ( it , 2 );
	it = myvector.insert ( it , 3 );

	for(i=0;i<myvector.size();i++)
		cout << myvector.at(i) << " ";
	cout << "\n";

	return 0;
}