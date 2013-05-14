#include <stdio.h>

/**/

int main(void)
{
  int dia , mes , ano , bissexto ;

  scanf("%d %d %d", &dia , &mes , &ano);

  if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
    bissexto = 1;
  else
    bissexto = 0;

  /* Janeiro tem 31 dias */
  if(mes == 1) {

    dia = dia + 1;

    if(dia / 31 > 0) {
      dia = dia % 31;
      mes = mes + 1;
    }
  } else {

  /*Fevereiro 28 (ou 29 dias nos anos bissextos)*/
    if(mes == 2) {
      dia = dia + 1;

      if(bissexto == 1) {

	if(dia / 29 > 0 ) {
	  dia = dia % 29;
	  mes = mes + 1;
	}

      }
      else {

	if(dia / 28 > 0 ) {
	  dia = dia % 28;
	  mes = mes + 1;
	}

      }
    } else {

  /*Março tem 31 dias*/
      if(mes == 3) {
	dia = dia + 1;
	if(dia / 31 > 0) {
	  dia = dia % 31;
	  mes = mes + 1;
	}
      } else {

  /*Abril tem 30 dias*/
	if(mes == 4) {
	  dia = dia + 1;
	  if(dia / 30 > 0) {
	    dia = dia % 30;
	    mes = mes + 1;
	  }
	} else {

  /*Maio tem 31 dias*/
	  if(mes == 5) {
	    dia = dia + 1;
	    if(dia / 31 > 0) {
	      dia = dia % 31;
	      mes = mes + 1;
	    }
	  } else {

  /*Junho tem 30 dias*/
	    if(mes == 6) {
	      dia = dia + 1;
	      if(dia / 30 > 0) {
		dia = dia % 30;
		mes = mes + 1;
	      }
	    } else {

  /*Julho tem 31 dias*/
	      if(mes == 7) {
		dia = dia + 1;
		if(dia / 31 > 0) {
		  dia = dia % 31;
		  mes = mes + 1;
		}
	      } else {

  /*Agosto tem 31 dias*/
		if(mes == 8) {
		  dia = dia + 1;
		  if(dia / 31 > 0) {
		    dia = dia % 31;
		    mes = mes + 1;
		  }
		} else {

  /*Setembro tem 30 dias */
		  if(mes == 9) {
		    dia = dia + 1;
		    if(dia / 30 > 0) {
		      dia = dia % 30;
		      mes = mes + 1;
		    }
		  } else {

  /*Outubro tem 31 dias*/
		    if(mes == 10) {
		      dia = dia + 1;
		      if(dia / 31 > 0) {
			dia = dia % 31;
			mes = mes + 1;
		      }
		    } else {

  /*Novembro tem 30 dias*/
		      if(mes == 11) {
			dia = dia + 1;
			if(dia / 30 > 0) {
			  dia = dia % 30;
			  mes = mes + 1;
			}
		      } else {

  /* Dezembro tem 31 dias*/

			dia = dia + 1;
			if(dia / 31 > 0) {
			  dia = dia % 31;
			  mes = 1;
			  ano = ano + 1;
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }

  printf("%d %d %d\n", dia , mes , ano );

  return 0;
}
