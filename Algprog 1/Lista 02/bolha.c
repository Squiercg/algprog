#include<stdio.h>


void bubble(int a[],int n) {
  int i,j,t;
  for(i=n-2;i>=0;i--) {
    for(j=0;j<=i;j++) {
      if(a[j]>a[j+1]) {
	t=a[j];
	a[j]=a[j+1];
	a[j+1]=t;
      }
    }
  }
}




int main(void)
{
  int a[100], n, i;


  printf("Entre com o tamanho do vetor: ");
  scanf("%d",&n);

  for( i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }

  bubble(a,n);


  for( i=0;i<=n-1;i++) {
      printf("%d ",a[i]);
  }

  printf("\n");

  return 0;

}
