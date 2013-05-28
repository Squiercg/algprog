#include <stdio.h>

/*Leia o id e altura das moças inscritas em um concurso de beleza.
Para cada moça existe uma linha contendo sua identificação e seu peso,
a ultima não contém nenhuma moça, contera a identificação 0, calcule e
escreva as duas maiores alturas e quantas moças pertencem a essas classes */

int main(void)
{
  int id , ac1 , ac2;
  float altura1 , altura2 , altura;


  altura1 = 0;
  altura2 = 0;
  ac1 = 0;
  ac2 = 0;

  scanf("%d %f", &id , &altura);

  while(id != 0) {
    if(altura>=altura2) {
      if(altura>=altura1) {

	if(altura==altura1) {
	  ac1++;
	} else {
	  ac2=ac1;
	  altura2=altura1;
	  ac1=1;
	  altura1 = altura;
	}

      } else {
	if(altura == altura2) {
	  ac2++;
	} else {
	  ac2=1;
	  altura2=altura;
	}
      }
    }
    scanf("%d %f", &id , &altura);
  }

  printf("Altura 1 = %f com %d e altura 2 = %f com %d.\n",altura1,ac1,altura2,ac2);

  return 0;
}
