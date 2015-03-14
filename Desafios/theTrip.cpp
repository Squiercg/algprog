#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
	double media, recebido, pago , desvio;
	int i, n, estudantes[1000],reais,centavos,total;

	cin >> n;

	while(n!=0){

		for(i=0;i<n;i++){
			scanf("%d.%d",&reais,&centavos);
			estudantes[i]=reais*100+centavos;
		}

		total=0;
		for(i=0;i<n;i++){
			total+=estudantes[i];
		}

		media = ((double) total) / n;

		recebido = 0;
		pago = 0;

		for (i = 0; i < n; i++) {
			desvio = estudantes[i] - media;
			if (desvio < 0) {
				recebido += -((int) desvio) / 100.0;
			} else {
				pago += ((int) desvio) / 100.0;
			}
		}

		 if(recebido>pago)
		 	printf("$%.2lf\n",recebido);
		 else
		 	printf("$%.2lf\n",pago);


		cin >> n;

	}







}
