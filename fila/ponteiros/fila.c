#include <stdio.h>
#include <stdlib.h>


typedef struct nos{
    int valor;
    struct nos *prox;
}Tiponos;

typedef struct fila{
    Tiponos *comeco;
    Tiponos *fim;
    int tamanho;
}Lista;

void FLVazia(Lista *fila){
    fila->comeco = NULL;
    fila->fim = NULL;
    fila->tamanho=0;
}

int vazia(Lista fila){
    return fila.comeco == NULL;
}


void enfileira(int item, Lista *fila){


    if(vazia(*fila)){ //verifica se a fila esta vazia, pois se estiver vazia entao o fim é o primeiro item
        fila->comeco=malloc(sizeof(Tiponos));
        fila->comeco->valor=item;
        fila->comeco->prox=NULL;
        fila->fim=fila->comeco;
    }else{
        Tiponos *final = fila->fim;
        Tiponos *novoItem = malloc(sizeof(Tiponos));
        novoItem->valor=item;
        novoItem->prox=NULL;
        final->prox=novoItem;
        fila->fim=novoItem;
    }
    fila->tamanho++;//aumento o tamanho da fila
}

void desenfileira(int posicao, Lista *fila){
    if(posicao>fila->tamanho){
        printf("O item que voce quer desenfileira nao existe");
    }else{
        if(posicao == 1){
            Tiponos *primeiroItem = fila->comeco;
            fila->comeco=fila->comeco->prox;//excluo a imenda com o primeiro item
            free(primeiroItem);//libero o espaço
            fila->tamanho--;
        }else{
            int auxiliar =2;
            Tiponos *novoNo = fila->comeco;
            while(auxiliar<posicao){//rodo até achar 1 antes do item que quero excluir
                auxiliar++;
                novoNo=novoNo->prox;
            }

            Tiponos *itemRemovido = novoNo->prox;//recebo o item que quero desenfileira
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

    enfileira(3, &lista);

    enfileira(2, &lista);


    enfileira(0, &lista);
    imprime(lista);
    printf("\n inserindo \n");
    desenfileira(2, &lista);
    imprime(lista);
}
