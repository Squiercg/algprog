#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {

  printf("Comecando o processo pai\n");
  printf("Getpid: %d\n",getpid());
  
  fork();
  printf("Getpid: %d\n",getpid());

  fork();
  printf("Getpid: %d\n",getpid());


  return 0;
}
