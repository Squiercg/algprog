#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  int T, N,pontos_total,i,empates,pontos,total;
  char pais[11];

  cin >> T;
  cin >> N;

  while(!(T==0 && N==0)){  

    pontos_total = 3*N;
    total=0;

    for(i=0;i<T;i++){
      scanf("%s %d",pais,&pontos);
      total+=pontos;
    }

    empates=pontos_total-total;

   	cout << empates;

    cin >> T;
    cin >> N; 

    if(!(T==0 && N==0))
      cout << "\n"; 

  }

}