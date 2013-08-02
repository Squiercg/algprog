#include <stdio.h>
struct marca {
  int hh;
  int mm;
  int ss;
};

/* Recebe um registro marca que contém uma medida de tempo no formato
hh:mm:ss e devolve um registro com tempo atualizado em 1 segundo */
struct marca adicionaSegundo(struct marca tempo) {
  struct marca atualizado;
  atualizado.ss = tempo.ss + 1;

  if (atualizado.ss == 60) {
    atualizado.ss = 0;
    atualizado.mm = tempo.mm + 1;
    if (atualizado.mm == 60) {
      atualizado.mm = 0;
      atualizado.hh = tempo.hh + 1;
      if (atualizado.hh == 24)
	atualizado.hh = 0;
    } else {
      atualizado.hh = tempo.hh;
    }
  } else {
    atualizado.mm = tempo.mm;
    atualizado.hh = tempo.hh;
  }

  return atualizado;
}

/* Recebe uma medida de tempo no formato hh:mm:ss
e mostra esse tempo atualizado em 1 segundo */
int main(void)
{
  struct marca agora, novo;
  printf("Informe um horario (hh:mm:ss): ");
  scanf("%d:%d:%d", &agora.hh, &agora.mm, &agora.ss);

  novo = adicionaSegundo(agora);

  printf("Novo horário %02d:%02d:%02d\n", novo.hh, novo.mm, novo.ss);

  return 0;
}
