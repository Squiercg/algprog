#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  int T, N,pontos_total,i,empates,pontos;
  char pais[100];

  cin >> T;
  cin >> N;

  while(T!=0 && N!=0){
    

    pontos_total = 3*N;
    empates=0;

    for(i=0;i<T;i++){
      scanf("%s %d",pais,&pontos);
      
      if(pontos%3!=0) {
        empates+=pontos%3;
        pontos_total-=(pontos/3)*3;
      } else {
        pontos_total-=pontos;
      }
    }

    

    if(empates<N){
    	cout << N << "\n";
	} else {
	    if(empates%2==0){
	    	cout << empates/2 << "\n";
	    } else {
	    	cout << empates << "\n";
	    }
	}

    cin >> T;
    cin >> N;    

  }
  return 0;
}