//
//  nos.c
//
//

#include <stdio.h>
#include <stdlib.h>


#define true 1
#define false 0

#define T 2
#define MAX_CHAVES 2 * T
#define MAX_FILHOS  2 * T + 1
#define MIN_OCUP  T-1


struct no_arvoreB {
    int num_chaves;
    int chaves[MAX_CHAVES];
    struct no_arvoreB *filhos[MAX_FILHOS];
};

typedef struct no_arvoreB arvoreB;

void pre_ordem(arvoreB *raiz)
{
  int i;
  if(raiz!=NULL){

  for(i=0;i<raiz->num_chaves;i++) {

    printf("%d ",raiz->chaves[i]);
    pre_ordem(raiz->filhos[i]);
    }

    if(raiz->filhos[i+1]!=NULL && i==raiz->num_chaves) {
      pre_ordem(raiz->filhos[i+1]);
    }
  }
}




int busca_binaria(arvoreB *no, int info)
{
  int i;

  for(i=0;i<raiz->num_chaves && info<=raiz->chave[i];i++);

  return i;


}

int busca(arvoreB *raiz, int info)
{
  int n;

  n=busca_binaria(raiz,info);

  if(raiz->chave[n]==info && n<raiz->num_chaves) {
    return raiz->chave[n];
  } else {





}


//Insere uma chave e o ponteiro para o filho da direita em um nó
void insere_chave(arvoreB *raiz, int info, arvoreB *filhodir)
{
    int k, pos;
    
    pos = busca_binaria(raiz, info);
    k = raiz->num_chaves;
    
    while (k > pos && info < raiz->chaves[k-1])
    {
        raiz->chaves[k] = raiz->chaves[k-1];
        raiz->filhos[k+1] = raiz->filhos[k];
        k--;
    }
    raiz->chaves[pos] = info;
    raiz->filhos[pos+1] = filhodir;
    raiz->num_chaves++;
}

//Realiza a busca do nó para inserir a chave e faz as subdivisões quando necessárias
arvoreB *insere(arvoreB *raiz, int info, int *h, int *info_retorno)
{
    int i, j, pos, info_mediano, aux;
    arvoreB *temp, *filho_dir;
    if (raiz == NULL)
    {
        *h = true;
        *info_retorno = info;
        return(NULL);
    }
    else {
        pos = busca_binaria(raiz,info);
        if (raiz->num_chaves > pos && raiz->chaves[pos] == info)
        {
            printf("Chave já contida na Árvore");
            *h = false;
        }
        else {
            filho_dir = insere(raiz->filhos[pos],info,h,info_retorno);
            if (*h)  {
                if (raiz->num_chaves < MAX_CHAVES)
                {
                    insere_chave(raiz, *info_retorno, filho_dir);
                    *h = false;
                }
                else {
                    temp = (arvoreB *) malloc (sizeof(arvoreB));
                    temp->num_chaves = 0;
                    
                    
                    for (i = 0; i < MAX_FILHOS; i++)
                        temp->filhos[i] = NULL;
                    
                    
                    if(pos <= MIN_OCUP){
                        info_mediano = raiz->chaves[MIN_OCUP];
                        for (i = MIN_OCUP; i > pos; i--) {
                            raiz->chaves[i] = raiz->chaves[i-1];
                        }
                        raiz->chaves[pos] = info;
                    }
                    else
                        if (pos == MIN_OCUP+1) {
                            info_mediano = info;
                        }else{
                            info_mediano = raiz->chaves[MIN_OCUP+1];
                            raiz->chaves[MIN_OCUP+1] = info;
                            for (i = MIN_OCUP+2; i < MAX_CHAVES -1; i++) {
                                raiz->chaves[i] = raiz->chaves[i+1];
                            }

                        }
                    
                    
                    temp->filhos[0] = raiz->filhos[MIN_OCUP+1];
                    for (i = MIN_OCUP + 1; i < MAX_CHAVES; i++){
                        
                        insere_chave(temp, raiz->chaves[i], raiz->filhos[i+1]);
                    }
                    
                   
                    for (i = MIN_OCUP+1; i<MAX_CHAVES; i++)
                    {
                        raiz->chaves[i] = 0;
                        raiz->filhos[i+1] = NULL;
                    }
                    raiz->num_chaves = MIN_OCUP+1;
                    
                    *info_retorno = info_mediano;
                    return(temp);
                }
            }
        }
    }
    return temp;
}

arvoreB *insere_arvoreB(arvoreB *raiz, int info)
{
    int h;
    int info_retorno, i;
    arvoreB *filho_dir, *nova_raiz;
    
    filho_dir = insere(raiz,info,&h,&info_retorno);
    if (h)
    {
        nova_raiz = (arvoreB *) malloc (sizeof(arvoreB));
        nova_raiz->num_chaves = 1;
        nova_raiz->chaves[0] = info_retorno;
        nova_raiz->filhos[0] = raiz;
        nova_raiz->filhos[1] = filho_dir;
        for (i = 2; i <= MAX_CHAVES; i++)
            nova_raiz->filhos[i] = NULL;
        return(nova_raiz);
    }
    else return(raiz);
}

int main(void){
    
    arvoreB *arv = NULL;
    
    arv = insere_arvoreB(arv, 10);
    pre_ordem(arv);
    arv = insere_arvoreB(arv, 300);
    pre_ordem(arv);
    arv = insere_arvoreB(arv, 100);
    pre_ordem(arv);
    arv = insere_arvoreB(arv, 30);
    pre_ordem(arv);
    arv = insere_arvoreB(arv, 11);
    pre_ordem(arv);
    arv = insere_arvoreB(arv, 77);
    
    pre_ordem(arv);
    
    return 0;
}

