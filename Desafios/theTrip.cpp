#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
	float estudantes[1000], total, media, soma, aux, n;
	int i;

	cin >> n;

	while(n!=0){


		total=0;
		soma=0;

		for(i=0;i<n;i++){
			scanf("\n%f",&estudantes[i]);
			total+=estudantes[i];
		}

		media= total/n;
		media = floorf(media);


		for(i=0;i<n;i++){
			 aux = media - estudantes[i];
			 if(aux>0)
			 	soma+=aux;
		}
		printf("%.2f",soma);

		cin >> n;

		if(n!=0)
			cout << "\n";




	}







}
