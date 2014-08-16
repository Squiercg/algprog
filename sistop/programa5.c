/*
Augusto Ribas
Doglas Sorgatto
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void forkMultiple(int n) {
  int i;
  pid_t pid; 
  pid=getpid();

  for(i=0;i<n;i++) {
    if(pid!=0) {
      pid = fork();
      wait(NULL);
    }

    if(pid==0) {
      while(1){
	printf("Filho ");
      }
    }

  }
}

int main(int argc, char const *argv[]) {

  int n;
  printf("Entre com a quantidade de filhos: ");
  scanf("%d",&n);

  forkMultiple(n);

  /*
  while(n>0){
    wait(NULL);
    n--;
  }
  */
  printf("\nPai\n");

  return 0;
}
