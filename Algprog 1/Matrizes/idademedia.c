#include <stdio.h>

int main(void) {

  int idade[100]={0}, velhos , novos , i , n; 
    float media;

    scanf("%d",&n);

    for(i=0;i<n;i++) {
      scanf("%d",&idade[i]);
    }

    media=0;

    for(i=0;i<n;i++) {
      media = media + idade[i];
    }

    media = media / (float) n;

    velhos=0;
    novos=0;

    for(i=0;i<n;i++) {
      if(idade[i]>media) {
	velhos++;
      } else {
	novos++;
      }
    }

    printf("Mais velhos: %d\n",velhos);
    printf("Mais novos: %d\n",novos);

  return 0;
}
