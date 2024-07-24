

#include <stdio.h>
#include <stdlib.h>

struct Convite {
    int id;
    int vendido; // 0 para n�o vendido, 1 para vendido
    struct Convite *prox;
};

struct Convite *inicio;
struct Convite *fim;
struct Convite *aux;
int op, valor;

void inserir(int id) {
    struct Convite *novo = (struct Convite*)malloc(sizeof(struct Convite));
    novo->id = id;
    novo->vendido = 0;
    novo->prox = NULL;

    if (inicio == NULL) {
        inicio = novo;
        fim = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }
}

void venderProximoConvite() {
    if (inicio == NULL) {
        printf("Todos os convites foram vendidos.\n");
        return;
    }

    struct Convite *vendido = inicio;
    inicio = inicio->prox;

    printf("Convite %d vendido com sucesso!\n", vendido->id);
    free(vendido);

    if (inicio == NULL) {
        fim = NULL;
    }
}

void mostrar() {
    if (inicio == NULL) {
        printf("Lista vazia\n");
    } else {
        aux = inicio;
        while (aux != NULL) {
            printf("Convite ID: %d - Status: %s\n", aux->id, aux->vendido ? "Vendido" : "Dispon�vel");
            aux = aux->prox;
        }
        printf("\n");
    }
}

int main() {
    inicio = fim = aux = NULL;
    for (int i = 1; i <= 300; i++) {
        inserir(i);
    }

    do {
        printf("Digite:\n");
        printf("1 - Apresentar convites\n");
        printf("2 - Vender pr�ximo convite\n");
        printf("3 - Sair\n");
        scanf("%d", &op);

        switch (op) {
            case 1: {
                mostrar();
                break;
            }
            case 2: {
                venderProximoConvite();
                break;
            }
        }
    } while (op != 3);

    return 0;
}
