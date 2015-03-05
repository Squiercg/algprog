#include <iostream>

using namespace std;

int main()
{
  char aux;
  int campo[1000][1000], matriz[1000][1000];
  int i, j, l, c , field=1;

  cin >> l;
  cin >> c;

  while(l!=0 && c!=0) {

    for(i=0;i<l;i++) {
      for(j=0;j<c;j++) {
        cin >> aux;
        if(aux=='*')
          campo[i][j]=-1;
        else
          campo[i][j]=0;
      }
    }


    for(i=0;i<l;i++) {
      for(j=0;j<c;j++) {
          matriz[i][j]=0;          
      }
    }

    for(i=0;i<l;i++) {
      for(j=0;j<c;j++) {
        if(campo[i][j]==-1) {
          if(i>0 && j>0)
            matriz[i - 1][j - 1]++;
          if(i>0)
             matriz[i - 1][j    ]++;
          if(i>0 && j<(c))
            matriz[i - 1][j + 1]++;
          if(j>0)
            matriz[i    ][j - 1]++;
          if(j<(c))
            matriz[i    ][j + 1]++;
          if(i<(l) && j>0)
            matriz[i + 1][j - 1]++;
          if(i<(l))
            matriz[i + 1][j    ]++;
          if(i<(l) && j<(c))
            matriz[i + 1][j + 1]++;
        } 
      }
    }

    cout << "Field #" << field << ":\n";
    field++;

    for(i=0;i<l;i++) {
      for(j=0;j<c;j++) {
        if(campo[i][j]==-1)
          cout << '*';
        else
          cout << matriz[i][j];
      }
      cout << "\n";
    }

    cin >> l;
    cin >> c;
    
    if(l!=0 && c!=0)
      cout << "\n";
  }

  return 0;
}
