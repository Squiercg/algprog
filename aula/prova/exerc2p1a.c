#include <stdio.h>

/* Esse programa imprime o primeiro, segundo e terceiro lugar entre n competidores.
O vencedor é aquele que tem mais medalhas de ouro, o criterio de desempate para numero igual
de medalhas de outro é o número de medalhas de prata, em caso de empate para medalhas de prata, sera
comparado o número de medalhas de bronze */

int main(void)
{
  int v1o , v2o, v3o, v1p, v2p, v3p, v1b, v2b, v3b, id1, id2, id3, i, n, pais, ouro, prata, bronze;

  printf("n: ");
  scanf("%d", &n);

  v1o = 0;
  v2o = 0;
  v3o = 0;
  v1p = 0;
  v2p = 0;
  v3p = 0;
  v1b = 0;
  v2b = 0;
  v3b = 0;
  id1 = 0;
  id2 = 0;
  id3 = 0;

  printf("Pais, ouro, prata e bronze: ");
  for(i=1 ; i<=n ; i++) {

    scanf("%d %d %d %d", &pais, &ouro, &prata, &bronze);

    if( (ouro>v1o) || (ouro==v1o && prata>v1p) || (ouro==v1o && prata==v1p && bronze>v1b) ) {

    /* Nesse caso eu transfiro o segundo lugar para o terceiro*/
    id3 = id2;
    v3o = v2o;
    v3p = v2p;
    v3b = v2b;
    /* O primeiro lugar para o segundo*/
    id2 = id1;
    v2o = v1o;
    v2p = v1p;
    v2b = v1b;
    /* Então eu modifico os dados do primeiro */
    id1 = pais;
    v1o = ouro;
    v1p = prata;
    v1b = bronze;

    } else {

      if( (ouro>v2o) || (ouro==v2o && prata>v2p) || (ouro==v2o && prata==v2p && bronze>v2b) ) {

    /* Nesse caso eu transfiro o segundo lugar para o terceiro*/
	id3 = id2;
	v3o = v2o;
	v3p = v2p;
	v3b = v2b;
    /* O primeiro lugar para o segundo*/
	id2 = pais;
	v2o = ouro;
	v2p = prata;
	v2b = bronze;

      } else {

	if( (ouro>v3o) || (ouro==v3o && prata>v3p) || (ouro==v3o && prata==v3p && bronze>v3b) ) {
    /* Nesse caso eu substituo o terceiro lugar */
	  id3 = pais;
	  v3o = ouro;
	  v3p = prata;
	  v3b = bronze;

	}

      }
    }

  }

  printf("Primeiro: %d, segundo: %d e terceiro: %d.\n", id1, id2, id3);
  return 0;

}
