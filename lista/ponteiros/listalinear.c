#include <stdio.h>
#include <stdlib.h>


typedef struct nos{
    int valor;
    struct nos *prox;
}Tiponos;

typedef struct lista{
     Tiponos *comeco;
    int tamanho;
}Lista;

void FLVazia(Lista *lista){
    lista->comeco = NULL;
    lista->tamanho=0;
}

int vazia(Lista lista){
    return lista.comeco == NULL;
}

void Insere(int item,int posicao,Lista *lista){
    if(posicao>lista->tamanho){
        printf("Use o outro metodo para inserir um item no fim");
    }else{
        Tiponos *novoItem = malloc(sizeof(Tiponos));
        novoItem->valor=item;
        if(posicao==1){
            novoItem->prox=lista->comeco;
            lista->comeco=novoItem;
        }else{
            int auxiliar =2;
            Tiponos *novoNo;
            novoNo = lista->comeco;
        }
    }
}

void InsereFim(int item,Lista *lista){

//    while (lista->prox!="null"){          ERROS DE GRAVAÇÃO
  //      lista->prox=lista->prox->prox;
 //   }
   // lista *novo = (lista*)malloc(sizeof(lista)*item);
  //  novo->prox="null";
  //  novo->valor=item;
  if(vazia(*lista)){ //verifica se a lista esta vazia, pois se estiver vazia entao o fim é o primeiro item
      lista->comeco=malloc(sizeof(Tiponos));
      lista->comeco->valor=item;
      lista->comeco->prox=NULL;
  }else{
      Tiponos *atual = lista->comeco;
      while(atual->prox!=NULL){//rodo os dados ate encontrar o fim
            atual=atual->prox;
      }
      Tiponos *novoItem = malloc(sizeof(Tiponos));//aloco espaço para novo item
      atual->prox=novoItem;//faco o item atual apontar para esse item criado
      novoItem->valor=item;
      novoItem->prox=NULL;
  }
  lista->tamanho++;//aumento o tamanho da lista
}

int main() {
    lista lista;
    int item=1;
    InsereFim(item,&lista);
    item=2;
    InsereFim(item,&lista);
    item=3;
    InsereFim(item,&lista);
}
