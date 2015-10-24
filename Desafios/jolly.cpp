#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(){
  int n, a,b,saida,i;
  int vetor[3000];


  while(scanf("%d",&n) != EOF){
    for(i=0;i<n;i++)
      vetor[i]=0;

    saida=0;
    for(i=0;i<n;i++){
      if(i==0) {
	scanf("%d",&a);
      } else {
	scanf("%d",&b);
	vetor[abs(a-b)-1]=1;
	a=b;
      }
    }

    for(i=0;i<(n-1);i++){
      if(vetor[i]==0) {
	saida=1;
      }
    }

    if(saida==1)
      cout << "Not jolly" << "\n";
    else
      cout << "Jolly" << "\n";
  }

  return 0;
}
