#include <stdio.h>
/*Esse programa recebe duas marcas de tempo e calcula o intervalo entre essas
marcas*/

/*Estrutura usado para armazenar tempos*/
struct tempo{
  int hh;
  int mm;
  int ss;
};

/*Essa função recebe dois tempo t1 e t2 e retorna o intervalo de tempo
decorrido entre esses dois tempo, usando a estrutura criada*/
struct tempo tempogasto(struct tempo t1, struct tempo t2) {
  struct tempo tg;

  tg.hh=t2.hh-t1.hh;
  if(tg.hh<0){
    tg.hh=-1*tg.hh;
  }

  tg.mm=t2.mm-t1.mm;

  if(tg.mm<0) {
    tg.hh=tg.hh-1;
    tg.mm=60+tg.mm;
  }

  tg.ss=t2.ss-t1.ss;

  if(tg.ss<0) {
    tg.mm=tg.mm-1;
    tg.ss=60+tg.ss;
  }
 

  return tg;

}

int main(void)
{
  struct tempo t1,t2,tgasto;

  /*Recebe dois tempos*/
  scanf("%d:%d:%d",&t1.hh,&t1.mm,&t1.ss);
  scanf("%d:%d:%d",&t2.hh,&t2.mm,&t2.ss);

  while( !(t1.hh==0 && t1.mm==0 && t1.ss==0 &&
	   t2.hh==0 && t2.mm==0 && t2.ss==0)) {

    /*Calcula o intervalo entre eles usando a função tempogasto*/
    tgasto=tempogasto(t1,t2);

    /*Imprime o resultado*/
    printf("%02d:%02d:%02d\n",tgasto.hh,tgasto.mm,tgasto.ss);

    /*Recebe dois novos tempos*/
    scanf("%d:%d:%d",&t1.hh,&t1.mm,&t1.ss);
    scanf("%d:%d:%d",&t2.hh,&t2.mm,&t2.ss);

  }

  return 0;
}
