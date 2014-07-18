#include <stdio.h>
#include <string.h>
void KMP (char pad[10], char txt[50]);

int main (void)
{
    char txt[50], pad[10];
    printf ("Entre com texto:\n");
    scanf (" %[^\n]", txt);
    printf ("Entre com o padrão: ");
    scanf (" %[^\n]", pad);
    KMP (pad, txt);
    return 0;
}
void KMP (char pad[10], char txt[50]){
    int i, j, k, d[10], m, n, teste;
    m = strlen(pad);
    n = strlen(txt);

    j = d[1] = 0;
    k = 1;
    while (k<m){
        if (pad[k]==pad[j]){
            k++;
            j++;
            d[k]=j;
        }
        else {
            if (j==0){
                k++;
                d[k]=0;
            }
            else
                j = d[j];
        }
    }

    i = j = 0;
    while ((i-j)<=(n-m)) {
        teste = 1;
        while (j<m && teste){
            if (txt[i]==pad[j]){
                i++;
                j++;
            }
            else
                teste = 0;
        }
        if (teste) {
            printf ("houve casamento em %d\n", i-m+1);
        }
        if (j==0)
            i++;
        else
            j = d[j];
    }
}
