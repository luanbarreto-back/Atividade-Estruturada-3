#include <stdio.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p){
    p->topo = -1;
}

int vazia(Pilha *p){
    return p->topo == -1;
}

void push(Pilha *p, int valor){
    p->dados[++p->topo] = valor;
}

int pop(Pilha *p){
    return p->dados[p->topo--];
}

int main(){

    Pilha p;
    inicializar(&p);

    int numero;

    printf("Digite um numero inteiro maior que zero: ");
    scanf("%d",&numero);

    while(numero > 0){
        push(&p, numero % 2);
        numero /= 2;
    }

    printf("Numero em binario: ");

    while(!vazia(&p)){
        printf("%d", pop(&p));
    }

    printf("\n");

    return 0;
}
