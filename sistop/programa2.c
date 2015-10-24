#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {

  printf("Comecando o processo pai\n");
  pid_t pid = fork();


  if(pid == 0) {
    printf("Sou filho e o valor de pid e %d\n",pid);
    printf("Meu getpid e %d\n",getpid());

    while(1){
      printf("Sou o Filho!\n");
      sleep(2);
    }

  } else {
    printf("Sou pai e o meu valor de pid e %d\n",pid);
    printf("Meu getpid e %d\n",getpid());
    while(1){
      printf("Sou o Pai\n ");
      sleep(2);
    }
  }


  return 0;
}
