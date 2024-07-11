#include<stdio.h> 
#include<stdlib.h> 
#include<locale.h> 
  
struct fila { 
    int comeco; 
    int final; 
    int conteudo[10]; 
}; 
  
struct fila f; 
  
void iniciar() { 
    f.comeco = -1; 
    f.final = -1; 
} 
  
void enqueue(int item) { 
    setlocale(LC_ALL,"Portuguese"); 
    if (f.final == 9) { 
        printf("Não é possível adicionar mais elementos.\n"); 
    } else { 
        if (f.comeco == -1) 
            f.comeco = 0; 
        f.final++; 
        f.conteudo[f.final] = item; 
        printf("%d adicionado à fila.\n", item); 
    } 
} 
  
void mostra() { 
    if (f.comeco == -1) 
        printf("Fila vazia.\n"); 
    else { 
        printf("Fila:\n"); 
        for (int i = f.comeco; i <= f.final; i++) { 
            printf("%d ", f.conteudo[i]); 
        } 
        printf("\n"); 
    } 
} 
  
void dequeue() { 
    setlocale(LC_ALL,"Portuguese"); 
    if (f.comeco == -1) { 
        printf("Foram remover todos os elementos.\n"); 
    } else { 
        printf("%d removido da fila.\n", f.conteudo[f.comeco]); 
        if (f.comeco == f.final) { 
            f.comeco = -1; 
            f.final = -1; 
        } else { 
            f.comeco++; 
        } 
    } 
} 
  
int main() { 
    int x, a; 
    iniciar(); 
    do { 
        printf("Digite:\n"); 
        printf("1 - INSERIR\n"); 
        printf("2 - MOSTRAR\n"); 
        printf("3 - REMOVER\n"); 
        printf("4 - SAIR\n"); 
        scanf("%d", &x); 
        switch(x) { 
            case 1: 
                printf("Digite um valor: "); 
                scanf("%d", &a); 
                enqueue(a); 
                break; 
            case 2: 
                mostra(); 
                break; 
            case 3: 
                dequeue(); 
                break; 
        } 
    } while (x != 4); 
  
    return 0; 
} 
