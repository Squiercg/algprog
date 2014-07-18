//Augusto Ribas
//Andre Furlan
//Thiago Machado


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101
#define DMAX 201
#define ZERO '0'
#define UM '1'
char colocar;



//armazena as chaves
struct chaves{
    char chave[DMAX];
};
typedef struct chaves registro;

//reg == NULL se nó é de desvio, reg != NULL se nó é folha
struct noDigital{
    struct noDigital* esq;
    struct noDigital* dir;
    char letra;
    int desvio;
    registro *reg;
};
typedef struct noDigital ArvDigital;

//aloca e inicializa um nó Desvio
ArvDigital* criaDesvio(){
    ArvDigital *raiz;
    raiz = (ArvDigital*)malloc(sizeof(ArvDigital));
    raiz->esq = raiz->dir = NULL;
    raiz->reg = NULL;
    return raiz;
}

//aloca e inicializa o registro para um nó folha
registro* criaRegistro(char chave[DMAX]){
    registro *reg;
    reg = (registro*)malloc(sizeof(registro));
    strcpy(reg->chave, chave);
    return reg;
}

//busca na árvore a chave a ser inserida, retornando -1 se ela não deve ser inserida (já se encontra, é prefixo, ou outra chave é prefixo dela), ou a posição que difere de outra chave já presente na árvore para o nó desvio
int busca(ArvDigital *raiz, char chave[DMAX]){
    
    ArvDigital *aux = raiz;
    int i, tamanho;
    
    //raiz nula
    if (raiz == NULL) {
        return -1;
    }
    
    tamanho = strlen(chave);
    
    //Alteramos aqui, para comparar a chave o char de interesse, e usando maior que para ir para a direita
    //percorre a árvore até encontraruma folha
    while (aux->reg == NULL) {
         //cuida para não comparar posição inexistente
        if (aux->desvio < tamanho && chave[aux->desvio] > aux->letra) {
            aux = aux->dir;
        }
        else{
            aux = aux->esq;
        }
    }
    i = 0;

    //encontra ponto onde as chaves diferem
    while (chave[i] != '\0' && aux->reg->chave[i] != '\0' && chave[i] == aux->reg->chave[i]) {
        i++;
    }

    if(chave[i] < aux->reg->chave[i]) {
      colocar=chave[i];
    } else {
      colocar = aux->reg->chave[i];
    }
    
    //verifica se chave é prefixo de aux->reg->chave
    if (chave[i] == '\0' && aux->reg->chave[i] != '\0') {
        printf("Chave %s é prefixo de %s!\n", chave, aux->reg->chave);
        return -1;
    }
    
    //verifica se aux->reg->chave é prefixo de chave
    if (chave[i] != '\0' && aux->reg->chave[i] == '\0') {
        printf("Chave %s é prefixo de %s!\n", aux->reg->chave, chave);
        return -1;
    }
    
    //verifica se chaves são iguais
    if (chave[i] == '\0' && aux->reg->chave[i] == '\0') {
        printf("Chave %s é igual a %s!\n", aux->reg->chave, chave);
        return -1;
    }
    
    return i;
}

//insere a chave na árvore
struct noDigital* insere(struct noDigital *raiz, char chave[DMAX]){
    
    ArvDigital *aux, *pai, *noDesvio, *noFolha;
    int posicao;
    
    //primeira chave da árvore
    if (raiz == NULL) {
        raiz = criaDesvio();
        raiz->reg = criaRegistro(chave);
        return raiz;
    }
    
    //demais chaves da árvore
    posicao = busca(raiz, chave);

    if( posicao != -1){
        noDesvio = criaDesvio();
        noDesvio->desvio = posicao;
	noDesvio->letra = colocar;

        noFolha = criaDesvio();
        noFolha->reg = criaRegistro(chave);
        
        aux = raiz;
        pai = NULL;
        
        //encontra posição a inserir o noDesvio novo, salvando pai
        while (aux->reg == NULL && (aux->desvio < posicao || (aux->desvio == posicao && noDesvio->letra < aux->letra) )) {
            pai = aux;
            if (chave[aux->desvio] <= noDesvio->letra) {
                aux = aux->esq;
            }
            else{
                aux = aux->dir;
            }
        }
        
        //se pai é nulo, novo noDesvio deve se tornar a raiz
        if (pai == NULL) {
            raiz = noDesvio;
        }else{
            //senão, atualizamos que noDesvio é novo filho esq/dir de pai
            if (chave[pai->desvio] <= aux->letra) {
                pai->esq = noDesvio;
            }else{
                pai->dir = noDesvio;
            }
        }
        //atualiza quem são os filhos esq/dir de noDesvio
        if (chave[posicao] <= noDesvio->letra) {
            noDesvio->esq = noFolha;
            noDesvio->dir = aux;
        }else{
            noDesvio->esq = aux;
            noDesvio->dir = noFolha;
        }
    }
    return raiz;
}

//impressão Pré-Ordem
void imprime(ArvDigital* arv)
{
    if(arv != NULL)
    {
        if(arv->reg != NULL)
            printf("%s\n", arv->reg->chave);
        else{
	  printf("Desvio: <%d> e letra <%c>\n ", arv->desvio+1,arv->letra);
        }
        imprime(arv->esq);
        imprime(arv->dir);
    }
}

//Função para validar a chave, confere se a chave so tem bases nitrogenadas e não letras esquisitas
int valida(char sequencia[]) {
  int i=0;

  while(sequencia[i]!='\0') {

  if( sequencia[i]!='a' &&
      sequencia[i]!='c' &&
      sequencia[i]!='t' &&
      sequencia[i]!='g' &&
      sequencia[i]!='A' &&
      sequencia[i]!='C' &&
      sequencia[i]!='T' &&
      sequencia[i]!='G') {
    return 0;
  }
  i++;

  }

    return 1;

}

//Função para padronizar chaves, para nunca misturar maiusculas com minusculas, dai estamos usando somente minusculas
void padroniza(char sequencia[]) {
  int i=0;

  while(sequencia[i]!='\0') {
    if(sequencia[i]=='A')
      sequencia[i]='a';
    if(sequencia[i]=='G')
      sequencia[i]='g';
    if(sequencia[i]=='C')
      sequencia[i]='c';
    if(sequencia[i]=='T')
      sequencia[i]='t';
    i++;
  }

}

int main(void){

    ArvDigital *arv = NULL;
    char chave[MAX], convertido[DMAX];
    int continua=1,n,i;

    do{
       scanf("%s", chave);
       continua=valida(chave);

       if(continua==1){
	 padroniza(chave);
	 arv = insere(arv,chave);
       }

    } while(continua==1);

    printf("Imprimindo arvore final\n\n");
    imprime(arv);

    return 0;
}
