#include <stdio.h>

int main(void)
{
  int n, i, num, dado[6] = {0};

  scanf("%d",&n);

  for(i=1;i<=n;i++) {
    scanf("%d",&num);
    dado[num-1]++;
  }

  for(i=0;i<6;i++) {
    printf("%d: %.2f%%\n",i+1, (dado[i]/ (float) n) * 100);
  }


  return 0;
}