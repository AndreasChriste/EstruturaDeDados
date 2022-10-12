#include <stdio.h>
#include <stdlib.h>


typedef struct aux{
    int cpf;
    int idade;
    struct aux* conjuge;
}PESSOA;

void imprimirCPFs (PESSOA * p){
    if (p->conjuge != NULL){
        printf("CPFs: %i x %i\n", p->cpf,p->conjuge->cpf);
    }
}

void envelhecer1(PESSOA* p){
    p->idade++;
}
void envelhecer3(PESSOA* p){
    p->conjuge->idade++;
}


int main(){
    PESSOA pessoa1;
    PESSOA pessoa2;
    PESSOA solteira;
    pessoa1.cpf=646546464;
    pessoa1.idade = 32;
    pessoa2.cpf=156485959;
    pessoa2.idade = 32;
    pessoa1.conjuge = &pessoa2;
    pessoa2.conjuge = &pessoa1;
    solteira.cpf = 987654321;
    solteira.conjuge = NULL;
    solteira.idade = 40;
    imprimirCPFs(&pessoa1);
    return 0;
}