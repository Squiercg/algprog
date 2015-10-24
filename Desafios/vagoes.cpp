#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int bubblesort(int trem[], int vagoes) {
  int i , j , aux, contagem;
  contagem=0;

  for(i=0;i<vagoes-1;i++) {
    for(j=0;j<vagoes-i-1;j++) {
      if(trem[j]>trem[j+1]) {
	aux=trem[j];
	trem[j]=trem[j+1];
	trem[j+1]=aux;
	contagem++;
      }
    }
  }

  return contagem;

}

int main(){
  int i, c, casos, n, trem[50],trocas;


  scanf("%d",&casos);

  for(c=0;c<casos;c++) {
    scanf("\n%d",&n);

    for(i=0;i<n;i++){
      scanf("\n%d",&trem[i]);
    }
	    
    trocas=bubblesort(trem, n);

    cout << "Optimal train swapping takes " << trocas << " swaps.\n";

  }	    



  return 0;

}
