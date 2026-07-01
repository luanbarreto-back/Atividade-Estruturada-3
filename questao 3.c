#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct{
    char dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p){
    p->topo = -1;
}

void push(Pilha *p, char c){
    p->dados[++p->topo] = c;
}

char pop(Pilha *p){
    return p->dados[p->topo--];
}

int main(){

    char palavra[MAX];

    Pilha p;

    inicializar(&p);

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tam = strlen(palavra);

    for(int i=0;i<tam/2;i++)
        push(&p,palavra[i]);

    int inicio;

    if(tam%2==0)
        inicio=tam/2;
    else
        inicio=tam/2+1;

    int palindromo=1;

    for(int i=inicio;i<tam;i++){

        if(pop(&p)!=palavra[i]){
            palindromo=0;
            break;
        }
    }

    if(palindromo)
        printf("A palavra e um palindromo.\n");
    else
        printf("A palavra nao e um palindromo.\n");

    return 0;
}
