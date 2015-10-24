#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {

  printf("Comecando o processo pai\n");
  pid_t pid = fork();


  if(pid == 0) {
    printf("[filho] getpid() %d\n",getpid());
    printf("[filho] pid  %d\n",pid);

    printf("Sou o Filho!\n");



  } else {
    printf("[pai] getpid() %d\n",getpid());
    printf("[pai] pid  %d\n",pid);

    wait(NULL);
    printf("Sou o Pai\n ");

  }


  return 0;
}
