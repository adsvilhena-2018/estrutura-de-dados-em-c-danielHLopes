#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 5

typedef struct pilha{
    int array[TAMANHO_MAX];
    int topo;
    int tamanho;
}Lista;

void FLVazia(Lista *pilha){
    for(int i =0;i<5;i++){
        pilha->array[i]=NULL;
    }
    pilha->topo=NULL;
    pilha->tamanho=0;
}

int vazia(Lista pilha){
    return pilha.tamanho == 0;
}


void empilha(int item, Lista *pilha){
    if(vazia(*pilha)){ //verifica se a pilha esta vazia, pois se estiver vazia entao o topo é o primeiro item
        pilha->array[0]=item;
        pilha->topo=0;
        printf("%d topo \n",pilha->topo);
    }else{
        if(pilha->topo>=5){
            printf("pilha cheia\n");
        }else {
            int indice=pilha->topo + 1;
            pilha->array[indice] = item;
            pilha->topo++;
            printf("%d topo \n",pilha->topo);
        }
    }
    pilha->tamanho++;//aumento o tamanho da pilha
}

void desempilha(Lista *pilha){
    printf("desenfieirando\n");
    if(vazia(*pilha)){
        printf("Você está com uma pilha vazia\n");
    }else{
        printf("desenfieirando com item\n");
        printf("%d topo \n",pilha->topo);
        pilha->array[pilha->topo]=NULL;
        pilha->topo--;
        pilha->tamanho--;
        printf("%d topo depois\n",pilha->topo);
    }


}

void imprime(Lista pilha){
    int i = 0;
    printf("Imprimindo...\n");
    while(pilha.array[i] != NULL && i < TAMANHO_MAX) {
        printf("<%d>", pilha.array[i]);
        i++;
    }

}

void imprimeTamanho(Lista pilha){
    printf("\nO tamanho da pilha é %d \n", pilha.tamanho);
}

int main() {
    Lista pilha;
    FLVazia(&pilha);
    imprime(pilha);
    printf("\n vazia \n");
    desempilha(&pilha);

    empilha(3, &pilha);
    empilha(2, &pilha);
    empilha(1, &pilha);
    empilha(1, &pilha);
    empilha(1, &pilha);
    imprime(pilha);

    printf("\n inserindo \n");

    desempilha(&pilha);
    printf("%d\n",pilha.topo);

    imprime(pilha);

    imprimeTamanho(pilha);
}
