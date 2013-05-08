#include <stdio.h>

/**/

int main(void)
{
  float salario,aumento;

  printf("Entre com seu salario atual: ");
  scanf("%f",&salario);

  if(salario > 1500) {
    aumento = salario * 0.05;
  } else {
    if(salario > 700) {
      aumento = salario * 0.10;
    } else {
      if(salario > 280) {
	aumento = salario * 0.15;
      } else {
	aumento = salario * 0.20;
      }
    }
  }

  printf("Salario antes do reajuste: %f\n",salario);
  printf("O percentual de aumento aplicado: %f\n",aumento/salario);
  printf("O valor do aumento: %f\n",aumento);
  printf("O novo salario: %f\n",salario+aumento);

  return 0;
}
