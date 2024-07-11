#include <stdio.h> 
#include <locale.h> 
#define MAX 26 
  
typedef struct { 
    char letras[MAX]; 
    int topo; 
} Pilha; 
  
void inicializar(Pilha *p) { 
    p->topo = -1; 
} 
  
int vazia(Pilha *p) { 
    return p->topo == -1; 
} 
  
int cheia(Pilha *p) { 
    return p->topo == MAX - 1; 
} 
  
void empilhar(Pilha *p, char valor) { 
    if (cheia(p)) { 
        printf("A pilha está cheia!\n"); 
    } else { 
        p->topo++; 
        p->letras[p->topo] = valor; 
    } 
} 
  
char desempilhar(Pilha *p) { 
    if (vazia(p)) { 
        printf("A pilha está vazia!\n"); 
        return -1; 
    } else { 
        char d = p->letras[p->topo]; 
        p->topo--; 
        return d; 
    } 
} 
  
void mostrar(Pilha *p) { 
    for (int i = p->topo; i >= 0; i--) { 
        printf("%c ", p->letras[i]); 
    } 
    printf("\n"); 
} 
  
int main() { 
    setlocale(LC_ALL, "Portuguese"); 
  
    Pilha pilha; 
    inicializar(&pilha); 
  
    // Empilhando de A a Z 
  
    printf("  A a Z:\n"); 
    printf("\n--------PILHA---------\n"); 
    for (char c = 'A'; c <= 'Z'; c++) { 
        empilhar(&pilha, c); 
    } 
    mostrar(&pilha); 
  
    // Desempilhando de Z a A 
    printf("\n  Z a A:\n"); 
    printf("\n--------PILHA---------\n"); 
    while (!vazia(&pilha)) { 
        printf("%c ", desempilhar(&pilha)); 
    } 
    printf("\n"); 
  
    return 0; 
} 
