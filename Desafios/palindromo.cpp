#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int dec_to_binario(int n,int vetor[]){
  int tamanho=0;

  while(n>0){
    vetor[tamanho]=n%2;
    n=n/2;
    tamanho++;
  }

  return tamanho;
}

int testa_palindromo(int tamanho, int vetor[]) {

  int palindromo=1, inicio, fim;

  fim=tamanho-1;
  inicio=0;

  while(tamanho>=1) {
    if(vetor[inicio]!=vetor[fim]) {
      palindromo=0;
      tamanho=0;
    }
    tamanho=tamanho-2;
    inicio++;
    fim--;
  }

  return palindromo;

}


int main(){

  int vetor[100];
  int i, tamanho, n;


  scanf("%d",&n);

  while(n!=0){    

    tamanho=dec_to_binario(n,vetor);

    /*
    for(i=0;i<tamanho;i++)
      cout << vetor[i];    
    cout << "\n";
    */

    if(testa_palindromo(tamanho,vetor)==1)
      cout << "Numero " << n <<  " e palindromo\n";
    else 
      cout << "Numero " << n <<  " nao e palindromo\n";

    scanf("%d",&n);
  }



  return 0;
}


