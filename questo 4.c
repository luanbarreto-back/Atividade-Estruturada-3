#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct{
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p){
    p->topo = -1;
}

void push(Pilha *p, int valor){
    p->dados[++p->topo]=valor;
}

int pop(Pilha *p){
    return p->dados[p->topo--];
}

int main(){

    char exp[MAX];

    Pilha p;

    inicializar(&p);

    printf("Digite a expressao em pos-fixa: ");
    scanf("%s", exp);

    for(int i=0; exp[i]!='\0'; i++){

        if(isdigit(exp[i])){

            push(&p, exp[i]-'0');

        }else{

            int b = pop(&p);
            int a = pop(&p);

            switch(exp[i]){

                case '+':
                    push(&p,a+b);
                    break;

                case '-':
                    push(&p,a-b);
                    break;

                case '*':
                    push(&p,a*b);
                    break;

                case '/':
                    push(&p,a/b);
                    break;
            }
        }
    }

    printf("Resultado = %d\n", pop(&p));

    return 0;
}
