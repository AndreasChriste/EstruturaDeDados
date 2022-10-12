// Alista linear sequencial  com sentinela 
#include <stdio.h>

#define MAX 5
#define False 0;
#define True 1;
typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
    //outros campos
}REGISTRO;

typedef struct{
    //elemento a mais de registro justamente para a inserção do sentinela
    REGISTRO A[MAX+1];
    int nroElem;
}LISTA;

void inicializaLista (LISTA * l){
    l->nroElem = 0;
}
void reinicializarLista (LISTA * l){
    l->nroElem = 0;
}

int tamanho(LISTA* l){
    return l->nroElem;
}

void exibirLista(LISTA * l){
    int i;
    printf("Lista: \"");
    for( i=0;i<l->nroElem;i++){
        printf("%i\t ",l->A[i].chave);
    }
    printf("\"\n");
}

int BuscaSequencial(LISTA * l,TIPOCHAVE ch){
    int i = 0;
    while(i<l->nroElem){
        if (ch == l->A[i].chave) return i;
        else i++;
    }
    return -1;
}

bool inserirElemLista(LISTA * l,REGISTRO reg,int i){
    int j;
    if ((l->nroElem == MAX) || (i < 0) || (i> l->nroElem)) return False;
    for (j = l->nroElem; j > i;j--) l->A[j] = l->A[j-1];
    l->A[i] = reg;    
    l->nroElem++;
    return True;
}

bool excluirElemLista(LISTA*l,TIPOCHAVE ch){
    int pos,j;
    pos = BuscaSequencial(l,ch);
    if(pos ==-1) return False;
    for (j = pos;j<l->nroElem-1; j++) l->A[j] = l->A[j+1];
}

int buscasentinela(LISTA * l, TIPOCHAVE ch){
    int i = 0;
    l->A[l->nroElem].chave = ch;
    while(l->A[i].chave != ch) {
        i++;
    }
    if(i == l->nroElem) return -1;
    else return i;
}

bool inserirElemOrd(LISTA *l , REGISTRO reg){
    if (l->nroElem >= MAX) return False;
    int pos = l->nroElem;
    while(pos > 0 && l->A[pos-1].chave >reg.chave){
        l->A[pos] = l->A[pos-1];
        pos--;
    }
    l->A[pos] = reg;
    l->nroElem++;
    return True;
}

int main(){
    LISTA ListaDeClientes;
    inicializaLista(&ListaDeClientes);
    REGISTRO cliente1;
    cliente1.chave = 5;
    REGISTRO cliente2;
    cliente2.chave = 9;
    REGISTRO cliente3;
    cliente3.chave = 18;
    inserirElemLista(&ListaDeClientes,cliente1,0);
    exibirLista(&ListaDeClientes);
    inserirElemLista(&ListaDeClientes,cliente2,1);
    exibirLista(&ListaDeClientes);
    inserirElemLista(&ListaDeClientes,cliente3,2);
    exibirLista(&ListaDeClientes);
    // printf("%i",BuscaSequencial(&ListaDeClientes,9));
   printf("%i",buscasentinela(&ListaDeClientes,18));
    return 0;
}