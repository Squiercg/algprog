#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
  int id;

  id=getpid();

  printf("Meu id eh: %d\n",id);

  while(1){
  }

  return 0;
}
