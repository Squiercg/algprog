#include <stdio.h>

int main(void)
{
  int i=0 , j=0, k=0, cont=0;
  char s1[30], s2[4];

  scanf(" %[^\n]",s1);
  scanf("%s",s2);

  while(s1[i]!='\0') {
    if(s1[i]==s2[j]) {
      k=i;
      while( (s1[i]==s2[j]) && s1[i]!='\0') {
	i++;
	j++;
      }
      if(s2[i]=='\0')
	cont++;
      j=0;
      i=k+1;
    }
    i++;
  }

  printf("contador: %d\n",cont);

  return 0;
}
