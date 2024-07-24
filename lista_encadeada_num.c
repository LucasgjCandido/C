#include <stdio.h>
#include <stdlib.h>

struct lista {
    int dado;
    struct lista *prox;
};

struct lista *inicio = NULL;
struct lista *aux = NULL;

void inserir() {
    struct lista *novo = malloc(sizeof(struct lista));
    printf("Digite o valor a ser inserido na lista: ");
    scanf("%d", &novo->dado);
    novo->prox = inicio;
    inicio = novo;
}

void retirar()
    {
        aux = inicio;
        inicio = aux->prox;
        free(aux);
        aux=inicio;
    }

void mostrar() {
    if (inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }
    struct lista *aux = inicio;
    while (aux != NULL) {
        printf("%d  ", aux->dado);
        aux = aux->prox;
    }
    printf("\n\n");
}

int main() {
    int op;
    do {
        printf("Digite:\n");
        printf("1 - Inserir\n");
        printf("2 - Apresentar\n");
        printf("3 - Remover\n");
        printf("4 - Sair\n");
        scanf("%d", &op);
        switch(op) {
            case 1:
                inserir();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                retirar();
                break;
        }
    } while (op != 4);
    return 0;
}

