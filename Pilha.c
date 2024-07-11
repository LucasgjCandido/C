#include<stdio.h> 
#include<stdlib.h> 
#include<locale.h> 
  
  
typedef struct p1
{ 
    int topo; 
    int vetor[600]; 
} pilha; 
pilha p; 
void main() 
{ 
  
    p.topo=-1; 
    int num, i, remover; 
    printf("%d\n", p.topo); 
    //printf("%d", sizeof(pilha)); 
    //PUSH = INSERIR VALORES NA PILHA 
    setlocale(LC_ALL, "Portuguese"); 
    printf("Qual sera o espaço da pilha\n"); 
    scanf("%d", &num); 
  
    for(i=1; i<=num; i++) 
    { 
        p.topo=p.topo+1; 
        printf("digite um valor para a pilha %d= ", i); 
        scanf("%d",&p.vetor[p.topo]); 
    } 
  
  
    //MOSTRAR A PILHA 
    printf("\n--------PILHA---------\n"); 
    for(int i=0; i<=p.topo; i++) 
    { 
        printf("Ponteiro %d = %d\n",i+1,p.vetor[i]); 
    } 
  
    do 
    { 
        printf("\n\nRemover o ultimo valor inserido na Pilha\n"); 
        printf(" 1 para SIM\n"); 
        printf(" 2 Para NAO\n"); 
        scanf("%d", &remover); 
  
        if(remover==1) 
        { 
            if (p.topo >= 0) 
            { 
                p.topo = p.topo - 1; 
                printf("\n--------PILHA---------\n"); 
                for(int i=0; i<=p.topo; i++) 
                { 
                    printf("Ponteiro %d = %d\n ",i+1,p.vetor[i]); 
                } 
            } 
  
        } 
        else if(remover==2) 
        { 
        } 
        else 
        { 
            printf("Valor Errado"); 
        } 
        //Continuação 
    } 
    while (p.topo != -1 && remover != 2); 
  
    { 
  
        printf("Fim"); 
    } 
} 
