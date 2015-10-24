#include <stdio.h>
struct marca {
  int hh;
  int mm;
  int ss;
};

/* Recebe um registro marca que contém uma medida de tempo no formato
hh:mm:ss e devolve o tempo neste registro atualizado em 1 segundo */
void adicionaSegundo(struct marca *tempo) {
  tempo->ss++;
  if (tempo->ss == 60) {
    tempo->ss = 0;
    tempo->mm++;
    if (tempo->mm == 60) {
      tempo->mm = 0;
      tempo->hh++;
      if (tempo->hh == 24)
	tempo->hh = 0;
    }
  }
}

/* Recebe uma medida de tempo no formato hh:mm:ss
e mostra esse tempo atualizado em 1 segundo */

int main(void)
{
  struct marca horario;
  printf("Informe um horario (hh:mm:ss): ");
  scanf("%d:%d:%d", &horario.hh, &horario.mm, &horario.ss);

  adicionaSegundo(&horario);

  printf("Novo horário %02d:%02d:%02d\n", horario.hh, horario.mm, horario.ss);

  return 0;
}
