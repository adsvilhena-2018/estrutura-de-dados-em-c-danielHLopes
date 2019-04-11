#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int *array[5];
    int *comeco;
    int *fim;
    int tamanho;
}Lista;

void esvaziar(Lista *fila){
    printf("esvaziar\n");
    for(int i=0;i<5;i++){
        fila->array[i]=NULL;
    }
    fila->comeco=-1;
    fila->fim=-10;
    fila->tamanho=0;
}
int vazia(Lista fila){
    return fila.comeco == -1;
}
/*int cheio(Lista fila){
    int x=0;
    for (int i = 0; i < 5; ++i) {
        if(fila.array[i]!=NULL){
            x++;
        }
    }
    if(x==5){
        return 1;
    }else return 0;
}*/
void enfileira(Lista *fila,int item){
    printf("aqui\n");
    if(vazia(*fila)){//faço o começo da minha lista na primeira posição
        printf("primeiro\n");
        fila->comeco=0;
        //printf("1\n");

        //printf("2\n");
        fila->array[0]=item;
        //printf("3\n");
        fila->tamanho=1;
        //printf("4\n");//testes
    }else{
        printf("outro\n");
        if(((fila->comeco==0)&&(fila->fim==5))^((fila->comeco-1)==fila->fim)){/*cheio(*fila)*/
            printf("Fila cheia\n");
        }else {
            if(fila->fim==-10){
                fila->fim=0;
            }
            int lugarAtual = fila->fim + 1;
            if(lugarAtual>5){
                lugarAtual=0;
            }
            fila->array[lugarAtual]=item;
            fila->fim=lugarAtual;
            fila->tamanho++;
        }
    }

}
void imprime(Lista fila){

    for (int i = 0; i < 5; ++i) {
        printf("%d \n",fila.array[i]);
    }
}
int main() {
    Lista fila;
    esvaziar(&fila);
    //imprime(fila);

    enfileira(&fila,9);
    enfileira(&fila,8);
    enfileira(&fila,7);
    enfileira(&fila,6);
    enfileira(&fila,5);
    enfileira(&fila,4);
    imprime(fila);
    return 0;
}
