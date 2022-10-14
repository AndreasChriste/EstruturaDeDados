#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define INVALIDO -1
#define False 0
#define True 1

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
    //outros campos
}REGISTRO;

typedef struct{
    REGISTRO reg;
    int prox;
}ELEMENTO;

typedef struct{
    ELEMENTO A[MAX];
    int inicio;
    int disponivel;
}LISTA;

void inicializa(LISTA * l){
    int i;
    //insere o os valores ao qual o indica o proxima estrutura apontada pela estrutura atual
    for(i=0; i<MAX-1; i++){
        //neste caso de a estrutura na posição 0 aponta para a posição 1
        l->A[i].prox = i+1;
    }
    // o ultimo elemento aponta para um elemento inválido
    l->A[MAX-1].prox = INVALIDO;
    //o primeiro elemento não aponta para ningem
    l->inicio = INVALIDO;
    //identifica o índice do array que está disponivel
    l->disponivel = 0;
}

int tamanho(LISTA* l){
    //i recebe o índice do primeiro elemento válido
    int i = l->inicio;
    int tam = 0;
    //Enquanto o elemento analisado for diferente de INVALIDO (-1) realiza o incremento no tamanho e percorre pro proximo elemento
    while(i != INVALIDO){
        tam++;
        i = l->A[i].prox;
    }
}

void exibirLista(LISTA* l){
    //recebe o primeiro valor válido da lista
    int i = l->inicio;
    printf("Lista: \"");
    while (i!= INVALIDO){
        printf("%i\t", l->A[i].reg.chave);
        i = l->A[i].prox;
    }
    printf("\"\n");
}

int buscaSequencia(LISTA * l , TIPOCHAVE ch){
    int i = l->inicio;
    while(i =! INVALIDO && i < l->A[i].reg.chave < ch) {
        i =  l->A->prox;
    if(i != INVALIDO && l->A[i].reg.chave == ch) return i;
    else return INVALIDO;
    }
}
//essa função verifica a disponibilidade da lista
int obterNO (LISTA* l){
    //a variável resultado recebe o primeiro  elemento da lista de disponíveis
    //caso o primeiro elemento disponivel tiver indice inválido significa que a lista está cheia
    int resultado = l->disponivel;
    //caso a lista de disponivel seja diferente de inválido a lista de disponivel anda uma posição para o proximo elemento disponível
    if(l->disponivel != INVALIDO){
        l->disponivel = l->A[l->disponivel].prox;
    }
    //retorna a posição(indice)do elemento disponivel que será utilizado
    return resultado;
}

int inserirElemento(LISTA * l, REGISTRO reg){
    if (l->disponivel == INVALIDO) return False;
    int ant = INVALIDO;
    int i = l->inicio;
    TIPOCHAVE ch = reg.chave;
    while(i != INVALIDO && l->A[i].reg.chave < ch){
        ant = i;
         i = l->A[i].prox;
    } 
    if(i!=INVALIDO && l->A[i].reg.chave == ch ) return False;
    i = obterNO(l);
    l->A[i].reg = reg;
    if(ant == INVALIDO){
        l->A[i].prox = l->inicio;
        l->inicio = i;
    }
    else{
        l->A[i].prox = l->A[ant].prox;
        l->A[ant].prox = i;
    }
}

bool excluirElemLista(LISTA * l, TIPOCHAVE ch){
    int ant = INVALIDO;
    int i = l->inicio;
    while ((i != INVALIDO) && (l->A[i].reg.chave < ch))
    {
        ant = i;
        i = l->A[i].prox;
    }
    if (i ==INVALIDO || l->A[i].reg.chave!=ch) return False;
    if (ant == INVALIDO) l->inicio = l->A[i].prox;
    else l->A[ant].prox = l->A[i].prox;
}

void reinicializarLista(LISTA* l ){
    inicializa(l);
}

void devolverNo(LISTA * l, int j){
    l->A[j].prox = l->disponivel;
    l->disponivel = j;
}

int main(){
    //Criando uma EStrutura do tipo lista
    LISTA lista1;
    // ELEMENTO elem1;
    // elem1.reg.chave = 5;
    // ELEMENTO elem1;
    // elem1.reg.chave = 5;


    inicializa(&lista1);
    // ELEMENTO* elem1 = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    // ELEMENTO* elem2 = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    // ELEMENTO* elem3 = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    // ELEMENTO* elem4 = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    // ELEMENTO* elem5 = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    REGISTRO reg1;
    reg1.chave = 2;
    REGISTRO reg2;
    reg2.chave = 1;
    REGISTRO reg3;
    reg3.chave = 5;
    REGISTRO reg4;
    reg4.chave = 26;
    // elem1->reg = reg1;
    // elem2->reg = reg2;
    // elem3->reg = reg3;
    // elem4->reg = reg4;

    printf("%i", tamanho(&lista1));
    inserirElemento(&lista1,reg1);
    inserirElemento(&lista1,reg2);
    inserirElemento(&lista1,reg3);
    inserirElemento(&lista1,reg4);
    exibirLista(&lista1);
    excluirElemLista(&lista1,5);
    exibirLista(&lista1);
    


    return 0;


}
