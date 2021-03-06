/*
 *Algoritimos de programação 2
 *Trabalho 02
 *Aluno: Augusto Cesar de Aquino Ribas
 */

#include <stdio.h>
#include <limits.h>

/*Struct para registrar os dados, cada unidade contem uma aresta(dois numeros inteiros) e seu peso(Um ponto flutuante)*/
typedef struct {
  int aresta[2];
  float peso;
} grafo;

/*Funcao auxiliar para encontrar a aresta de menor peso num vetor de arestas, ela retornar o indice deste*/
int menorpeso(grafo floresta[],int n){
  int indice,i;
  float menor;

  indice=0;
  menor=floresta[indice].peso;

  i=1;
  while(i<n) {
    if(menor>floresta[i].peso){
      indice=i;
      menor=floresta[i].peso;
    }
    i++;
  }

  return indice;
}

/*Remove uma aresta de um vetor de arestas que formam um grafo*/
int removearesta(grafo floresta[],int aresta,int n){
  int i;

  for(i=aresta;i<(n-1);i++){
    floresta[i]=floresta[i+1];
  }

  return n-1;

}

/*Essa função une dois vertices de um grafo. A informacao de conecao fica reservada num vetor a parte,
esse é o algoritimo quick-union*/
void uniao(int p, int q , int vetor[] , int n) {
  int pid , qid , i;

  pid = vetor[p];
  qid = vetor[q];

  for (i = 0; i < n; i++) {
    if (vetor[i] == pid) {
      vetor[i] = qid;
    }
  }

}

/*Essa funcao testa se dois vertices estao conectados, ela funciona a partir do vetor usado na funcao acima, que
mantem registro das unioes formadas pelas arestas*/
int conectado(int p, int q, int vetor[]) {

  if(vetor[p]==vetor[q]) {
    /*printf("Existe um caminho\n");*/
    return 1;
  } else {
    /*printf("Não existe um caminho\n");*/
    return 0;
  }

}

/*Ordena o grafo pela primera aresta, desempatando pela segunda aresta*/
void ordenagrafo(grafo arvore[],int n) {
  int i,j;
  grafo aux;

  for(i=1;i<n;i++) {
    aux=arvore[i];
    j=i-1;
    while(j>=0 && (arvore[j].aresta[0]>aux.aresta[0] || (arvore[j].aresta[0]==aux.aresta[0] && arvore[j].aresta[1]>aux.aresta[1]))) {
      arvore[j+1]=arvore[j];
      j=j-1;
    }
    arvore[j+1]=aux;
  }

}


/*Esse algoritimo é baseado na solucao de krustal para o problema do minimum spanning tree*/
int main(void) {
  int k, f, i, vetor[100], a, vezes, q;
  float peso;

  grafo floresta[100], arvore[100];
  scanf("%d",&vezes);

  for(q=0;q<vezes;q++) {


/*Primeiro recebemos o numero de vertices*/
    scanf("%d",&k);

/*Preparamos um vetor para manter registro das unioes no grafo*/
    for(i=0;i<k;i++) {
      vetor[i]=i;
    }

/*Recebemos as arestas ate ser enviado uma aresta de 0 para 0 com peso 0*/
    f=0;
    scanf("%d %d %f",&floresta[f].aresta[0],&floresta[f].aresta[1],&floresta[f].peso);
    while(floresta[f].aresta[0]!=0 && floresta[f].aresta[1]!=0 && floresta[f].peso !=0){
      f++;
      scanf("%d %d %f",&floresta[f].aresta[0],&floresta[f].aresta[1],&floresta[f].peso);
    }

/*Conferindo a entrada de dados
  printf("%d\n",f);

  for(i=0;i<f;i++){
    printf("%d %d %f\n",floresta[i].aresta[0],floresta[i].aresta[1],floresta[i].peso);
  }
*/

/*O algoritimo funciona da seguinte forma.
Chamamos o grafo inicial de floresta, e criamos um grafo vaziu(sem arestas) e chamaos esse de arvore
Dai pegamos a aresta de menor peso da floresta, vemos se os dois vertices estao conectados, se não adicionamos a arvore,
caso contrario discartamos essa aresta, e repetimos isso até a flores ficar vazia*/
    a=0;

/*Então até acabar as arestas da floresta*/
    while(f>0){

/*Selecionamos a menor*/
      i=menorpeso(floresta,f);

/*Testamos se estao conectados*/
      if(conectado(floresta[i].aresta[0]-1,floresta[i].aresta[1]-1,vetor)==0){
      /*Se estiver conectado nos unimos os dois vertices*/
	uniao(floresta[i].aresta[0]-1,floresta[i].aresta[1]-1, vetor, k);
      /*Adicionamos a arvore*/
	arvore[a]=floresta[i];
	a++;
      }

/*E antes de começar a proxima iteracao, removemos a aresta apos o devido processamento*/
      f=removearesta(floresta,i,f);

    }

  /*Ordenamos o grafo pelas arestas*/
    ordenagrafo(arvore,a);

/*E aqui imprimimos o resultado*/
    peso=0;
    /*    printf("Imprimindo arvore\n");*/
    for(i=0;i<a;i++){
      printf("%d %d\n",arvore[i].aresta[0],arvore[i].aresta[1]);
      peso=peso+arvore[i].peso;
    }
    printf("Peso final = %.3f\n\n",peso);

  }

  return 0;
}
