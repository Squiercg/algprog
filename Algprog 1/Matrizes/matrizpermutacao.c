#include <stdio.h>

int main(void)
{
  int matriz[100][100] = {{0}} , n , i , j, um, perm=0 , V[100]={0};

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d",&matriz[i][j]);
    }
  }

  for(i=0;i<n;i++) {

    um=0;

    for(j=0;j<n;j++) {
      if( (matriz[i][j] == 0) || (matriz[i][j]==1) ) {

	if(matriz[i][j]==1) {
	  um++;
	  V[j]++;
	}

      } else 
	um=2;
    
    }
    if(um!=1){
	perm=1;
    }
  }


  for(i=0;i<n;i++) {
    if(V[i]!=1){
      perm=1;
    }
    
  }

  if(perm==0)
    printf("Permutação\n");
  else
    printf("Não é permutação\n");

  return 0;
}


