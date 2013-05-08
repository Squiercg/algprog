#include <stdio.h>

/*Pega 2 notas, tira a média e da o conceito resultante de acordo com tabela*/

int main(void)
{
  float n1 , n2 , resul;

  printf("Entre a nota 1 e nota 2: ");
  scanf("%f %f", &n1 , &n2 );

  resul = ( n1 + n2 ) / 2;

    if(resul >= 9.0) 
      printf("Para as notas %f e %f o conceito é A.\n", n1 , n2);
    else 
    if(resul >= 7.5 ) 
      printf("Para as notas %f e %f o conceito é B.\n", n1 , n2);
    else
    if(resul >= 6.0) 
      printf("Para as notas %f e %f o conceito é C.\n", n1 , n2);
    else
    if(resul >= 4.0) 
      printf("Para as notas %f e %f o conceito é D.\n", n1 , n2);
    else
      printf("Para as notas %f e %f o conceito é E.\n", n1 , n2);

    return 0;
}
