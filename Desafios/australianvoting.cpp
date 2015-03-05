#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct {
    char nome[81];
    int votos;    
} candidato;

int main(){
    candidato candidatos[20];
    int matriz[1000][20], casos_teste, n , i, linha;
    char temp;

    cin >> casos_teste;

    while(casos_teste>0) {
        cin >> n;

        for(i=0;i<n;i++){
            scanf("%s",candidatos[i].nome);
            candidatos[i].votos=0;
        }

        linha=0;

        cout << "antes da matriz\n";

        while(scanf("%c", &temp)!='\n'){
            for(i=0;i<n;i++){
                scanf("%d",&matriz[linha][i]);
            }
            linha++;
            cout << "entrou\n";
        }







        casos_teste--;
        cout << "teste com sucesso \n";
    }




    return 0;
} 