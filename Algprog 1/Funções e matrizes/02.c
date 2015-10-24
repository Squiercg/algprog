#include <stdio.h>

#define MAX 100

void multmat(int A[MAX][MAX] , int B[MAX][MAX], int C[MAX][MAX], int n) {
  int i, j, k;

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      C[i][j]=0;
      for(k=0;k<n;k++){
	C[i][j]=C[i][j]+A[i][k]*B[k][j];
      }
    }
  }

}

int iguais(int n, int A[MAX][MAX], int B[MAX][MAX]) {
  int i, j, eq=1;

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(A[i][j]==B[i][j]){
	eq=0;
      }
    }
  }

  return eq;
}

int main(void)
{
  int A[MAX][MAX] , B[MAX][MAX], C[MAX][MAX], i, j,n,pot,k;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d",&A[i][j]);
    }
  }


  scanf("%d",&pot);

  multmat(A,A,B,n);

  for(k=2;k<=pot;k++){
    multmat(A,B,C,n);

    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
      B[i][j]=C[i][j];
      }
    }

  }

  printf("Iguais = %d\n",iguais(n,A,B));

  return 0;
}
