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
        novoItem->prox=NULL;
        if(posicao==1){
            novoItem->prox=lista->comeco;
            lista->comeco=novoItem;
        }else{
            int auxiliar =2;
            Tiponos *novoNo;
            novoNo = lista->comeco;

            while(auxiliar<posicao){//procurando a posição para a inserção
                novoNo = novoNo->prox;
                auxiliar++;
            }

            novoItem->prox=novoNo->prox;//insiro o item na posiçao e depois faço o nó apontar pra ele
            novoNo->prox=novoItem;
            lista->tamanho++;
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

void remover(int posicao,Lista *lista){
    if(posicao>lista->tamanho){
        printf("O item que voce quer remover nao existe");
    }else{
        if(posicao == 1){
            Tiponos *primeiroItem = lista->comeco;
            lista->comeco=lista->comeco->prox;//excluo a imenda com o primeiro item
            free(primeiroItem);//libero o espaço
            lista->tamanho--;
        }else{
            int auxiliar =2;
            Tiponos *novoNo = lista->comeco;
            while(auxiliar<posicao){//rodo até achar 1 antes do item que quero excluir
                auxiliar++;
                novoNo=novoNo->prox;
            }

            Tiponos *itemRemovido = novoNo->prox;//recebo o item que quero remover
            novoNo->prox=novoNo->prox->prox;//corto a linha que ligava aquele item
            free(itemRemovido);//libero o espaço dele
        }
    }

}

void imprime(Lista lista){
    Tiponos *no = lista.comeco;
    while(no!= NULL){
        printf("%d \n",no->valor);
        no=no->prox;
    }

}

int main() {
    Lista lista;
    FLVazia(&lista);
    imprime(lista);
    printf("\n vazia \n");

    InsereFim(3,&lista);

    InsereFim(2,&lista);

    Insere(1,2,&lista);

    InsereFim(0,&lista);
    imprime(lista);
    printf("\n inserindo \n");
    remover(2,&lista);
    imprime(lista);
}
