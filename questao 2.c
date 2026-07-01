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

void pop(Pilha *p){
    if(p->topo != -1)
        p->topo--;
}

int vazia(Pilha *p){
    return p->topo == -1;
}

int main(){

    char exp[MAX];

    Pilha p;
    inicializar(&p);

    printf("Digite a expressao: ");
    fgets(exp, MAX, stdin);

    for(int i=0; exp[i]!='\0'; i++){

        if(exp[i]=='(')
            push(&p,'(');

        else if(exp[i]==')'){

            if(vazia(&p)){
                printf("Quantidade incorreta de parenteses.\n");
                return 0;
            }

            pop(&p);
        }
    }

    if(vazia(&p))
        printf("Quantidade correta de parenteses.\n");
    else
        printf("Quantidade incorreta de parenteses.\n");

    return 0;
}
