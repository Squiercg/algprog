#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(){

  int esquerda[31],direita[31];
  char lado;
  int i, tamanho, pares,n;


  while(scanf("%d",&n) != EOF){

    for(i=0;i<31;i++){
      esquerda[i]=0;
      direita[i]=0;
    }

    for(i=0;i<n;i++){
      scanf("\n%d %c",&tamanho,&lado);
      if(lado=='E')
	esquerda[tamanho-30]++;
      else
	direita[tamanho-30]++;
    }

    pares=0;
    for(i=0;i<31;i++) {
      while(esquerda[i]!=0 && direita[i]!=0){
	pares++;
	esquerda[i]--;
	direita[i]--;
      }
    }

    cout << pares << "\n";

  }

  return 0;




}





