#include <stdio.h>
#include <stdlib.h>


typedef struct nos{
    int valor;
    struct nos *ant;
}Tiponos;

typedef struct pilha{
    Tiponos *comeco;
    Tiponos *topo;
    int tamanho;
}Lista;

void FLVazia(Lista *pilha){
    pilha->comeco = NULL;
    pilha->topo = NULL;
    pilha->tamanho=0;
}

int vazia(Lista pilha){
    return pilha.comeco == NULL;
}


void enfileira(int item, Lista *pilha){
    if(vazia(*pilha)){ //verifica se a pilha esta vazia, pois se estiver vazia entao o topo é o primeiro item
        pilha->comeco=malloc(sizeof(Tiponos));
        pilha->comeco->valor=item;
        pilha->comeco->ant=NULL;
        pilha->topo=pilha->comeco;
    }else{
        Tiponos *novoItem = malloc(sizeof(Tiponos));
        novoItem->valor=item;
        novoItem->ant=pilha->topo;
        pilha->topo=novoItem;
    }
    pilha->tamanho++;//aumento o tamanho da pilha
}

void desenfileira(Lista *pilha){
    if(pilha->tamanho==0){
        printf("Você está com uma pilha vazia\n");
    }else{
        Tiponos *topoPilha = pilha->topo;
        pilha->topo=pilha->topo->ant;//excluo a imenda com o primeiro item
        free(topoPilha);//libero o espaço
        pilha->tamanho--;
    }


}

void imprime(Lista pilha){
    Tiponos *no = pilha.topo;
    while(no!= NULL){
        printf("%d \n",no->valor);
        no=no->ant;
    }

}

void imprimeTamanho(Lista pilha){
    printf("O tamanho da pilha é %d \n", pilha.tamanho);
}

int main() {
    Lista pilha;
    FLVazia(&pilha);
    imprime(pilha);
    printf("\n vazia \n");
    desenfileira(&pilha);
    enfileira(3, &pilha);
    enfileira(2, &pilha);
    enfileira(1, &pilha);
    imprime(pilha);
    printf("\n inserindo \n");
    desenfileira( &pilha);
    imprime(pilha);
    imprimeTamanho(pilha);
}
