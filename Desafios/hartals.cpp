#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
	int c, casos,tempo,partidos, p, s, contagem;
	int intervalos[100], simulacao[3650];

	scanf("%d",&casos);

	for(c=0;c<casos;c++){
		scanf("\n%d",&tempo);
		scanf("\n%d",&partidos);


		for(p=0;p<partidos;p++){
			scanf("\n%d",&intervalos[p]);
		}


		for(s=0;s<tempo;s++){
			simulacao[s]=0;
		}


		for(p=0;p<partidos;p++){
			for(s=intervalos[p]-1;s<tempo;s+=intervalos[p]){
				if((s%7!=5) && (s%7!=6)) {
					simulacao[s]=1;
				}
			}			
		}

		contagem=0;

		for(s=0;s<tempo;s++){
			if(simulacao[s]==1)
				contagem++;
		}

		cout << contagem << "\n";

	}

	return 0;
}