#include <stdio.h> 

int main(void)
{
  int i, j, l , c, m , n , matriz[200][200], saida=0;

  scanf("%d %d",&n , &m);

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      scanf("%d",&matriz[i][j]);
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      for(l=i;l<n;l++){
	for(c=i;c<m;c++){

	  if((l!=i)||(c!=j)) {

	      if(matriz[i][j]==matriz[l][c]){
		saida=1;
	      }

	    }
	}
      }
    }
  }

  if(saida==1)
    printf("yes\n");
  else
    printf("no\n");

  return 0;
}
