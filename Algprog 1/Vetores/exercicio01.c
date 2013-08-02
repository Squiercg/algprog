#include <stdio.h>

int main(void)
{
  int v1[100] , v2[100], v3[100] , n, m , i, j, k;

  printf("Entre com n e m: ");
  scanf("%d %d", &n , &m);

  printf("Vetor 1: ");
  for(i=0 ; i<n; i++) {
    scanf("%d",&v1[i]);
  }

  printf("Vetor 2: ");
  for(i=0 ; i<m ; i++) {
    scanf("%d", &v2[i]);
  }

  i=0; /* v1 */
  j=0; /* v2 */
  k=0; /* v3 */

  while(i<n && j<m) {
    if(v1[i]<v2[j]) {
      v3[k]=v1[i];
      i++;
    } else {
      if(v2[j]<v1[i]) {
	v3[k]=v2[j];
	j++;
      } else {
	v3[k]=v1[i];
	i++;
	j++;
      }
    }
    k++;
  }

  if(i==n) {

    while(j!=m) {
      v3[k]=v2[j];
      j++;
      k++;
    }

  } else {

    while(i!=n) {
      v3[k]=v1[i];
      i++;
      k++;
    }

  }

  printf("Vetor 3: ");
  for(i=0;i<k;i++) {
    printf("%d ",v3[i]);
  }
  printf("\n");

  return 0;
}

