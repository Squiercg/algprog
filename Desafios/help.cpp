#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>

using namespace std;


int main()
{
	int tempo, n, i,tentativas[26],corretas,tempo_total;
	char julgamento[30],problema;

	vector<char> problemas;
	std::vector<char>::iterator it;

	cin>>n;

	while(n!=0) {
		corretas=0;
		tempo_total=0;
		for(i=0;i<26;i++){
			tentativas[i]=0;
		}

		for(int i = 0; i < n; ++i){
			scanf("\n%c %d %s",&problema,&tempo,julgamento);

			if(strcmp(julgamento,"incorrect")==0){
				tentativas[problema-'A']++;
			} else {
				corretas++;
				tempo_total+=tempo+tentativas[problema-'A']*20;
			}
		}

		cout << corretas << " " << tempo_total << "\n";

		cin>>n;
	}




}