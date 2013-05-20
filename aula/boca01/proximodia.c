#include <stdio.h>

int main (void)
{
  int dia, mes, ano, pdia, pmes, pano, bissexto;
  scanf ("%d %d %d", &dia, &mes, &ano);

  if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
    bissexto = 29;
  else
    bissexto = 28;

  if((dia==bissexto&&mes==2)||(dia==30&&(mes==4||mes==6||mes==9||mes==11))||dia==31)
    pdia=1;
  else
    pdia=dia+1;

    if(pdia==1)
      pmes=mes+1;
    else
      pmes=mes;

    if(pmes==13)
      pano=ano+1;
    else
      pano=ano;

    if(pmes==13)
      pmes=1;

    printf ("%d %d %d\n", pdia, pmes , pano);

    return 0;
}
