#include <iostream>
using namespace std;


class Matriz_Caracteristicas{
public:
    int linhas;
    int colunas;
    int** matriz;

    Matriz_Caracteristicas(int lin, int col) {
        this->linhas = lin;
        this->colunas = col;

        int i,j;
        this->matriz = new int*[this->linhas];
        for(i = 0; i < this->linhas; i++)
            this->matriz[i] = new int[this->colunas];

        for(i=0;i<this->linhas;i++){
            for(j=0;j<this->colunas;j++){
                cin >> this->matriz[i][j];
            }
        }
    } //Fim do construtor

    void imprime_matriz(){
        int i, j;
        for(i=0;i<this->linhas;i++){
            for(j=0;j<this->colunas;j++){
                cout << this->matriz[i][j] <<" ";
            }
            cout << "\n";
        }
    }

    bool permite_filogenia() {
        int i , j ;
        bool saida = true;

        for(i=0;i<(this->colunas-1);i++) {
            for(j=i+1;j<this->colunas;j++){
                if(intersecao_vazia(i,j)==false){
                    if(subconjunto(i,j)==false && subconjunto(j,i)==false) {
                        saida=false;
                    }
                }
            }
        }

        return saida;
    }

private:
    bool intersecao_vazia(int a, int b) {
        int i;
        for(i=0;i<this->linhas;i++) {
            if(this->matriz[i][a]==1 && this->matriz[i][b] == 1)
                return true;
        }
        return false;
    }

    //O "a" é um subconjunto de "b"?
    bool subconjunto(int a, int b) {
        int i;
        for(i=0;i<this->linhas;i++) {
            if(this->matriz[i][a]==1 && this->matriz[i][b] == 0)
                return false;
        }
        return true;
    }



};

int main(void) {
    int i,j;
    cin >> i;
    cin >> j;
    cout << "i: " << i << " j: "<< j << "\n";

    Matriz_Caracteristicas* matriz = new Matriz_Caracteristicas(i,j);

    matriz->imprime_matriz();
    if(matriz->permite_filogenia()) {
        cout << "filogenia perfeita existe\n";

    } else {
        cout << "filogenia perfeita nao existe\n";
    }

    cout << "Hello World!" << "\n";
}



