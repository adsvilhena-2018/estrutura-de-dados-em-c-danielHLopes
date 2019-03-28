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

void desenfileira(Lista *fila){
    if(fila->tamanho==0){
        printf("Você está com uma fila vazia\n");
    }else{
            Tiponos *primeiroItem = fila->comeco;
            fila->comeco=fila->comeco->prox;//excluo a imenda com o primeiro item
            free(primeiroItem);//libero o espaço
            fila->tamanho--;
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
    Lista fila;
    FLVazia(&fila);
    imprime(fila);
    printf("\n vazia \n");
    desenfileira(&fila);
    enfileira(3, &fila);
    enfileira(2, &fila);
    enfileira(0, &fila);
    imprime(fila);
    printf("\n inserindo \n");
    desenfileira( &fila);
    imprime(fila);
}
