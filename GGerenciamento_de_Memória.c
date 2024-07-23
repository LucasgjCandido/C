#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1024

// Estrutura de um bloco de memória
typedef struct Block {
    size_t size; // Tamanho do bloco de memória
    struct Block* next; // Próximo bloco na lista de memória livre
} Block;

static char memory[MEMORY_SIZE]; // Memória simulada
static Block* free_list = (Block*)memory; // Lista de blocos livres

// Inicializa o gerenciador de memória
void memory_init() {
    free_list->size = MEMORY_SIZE - sizeof(Block); // Tamanho inicial da memória livre
    free_list->next = NULL; // Não há mais blocos livres no início
}

// Aloca memória
void* memory_alloc(size_t size) {
    Block* prev = NULL;
    Block* curr = free_list;

    // Procura um bloco de memória livre suficiente
    while (curr) {
        if (curr->size >= size) {
            if (curr->size > size + sizeof(Block)) {
                // Divide o bloco de memória e cria um novo bloco livre
                Block* new_block = (Block*)((char*)curr + sizeof(Block) + size);
                new_block->size = curr->size - size - sizeof(Block);
                new_block->next = curr->next;
                curr->size = size;
                curr->next = new_block;
            }
            // Remove o bloco alocado da lista de blocos livres
            if (prev) {
                prev->next = curr->next;
            } else {
                free_list = curr->next;
            }
            return (void*)((char*)curr + sizeof(Block));
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL; // Memória insuficiente
}

// Libera memória
void memory_free(void* ptr) {
    if (!ptr) return;
    Block* block = (Block*)((char*)ptr - sizeof(Block));
    block->next = free_list;
    free_list = block;
}

// Função principal para testar o gerenciador de memória
int main() {
    memory_init();

    void* ptr1 = memory_alloc(128); // Aloca 128 bytes
    void* ptr2 = memory_alloc(256); // Aloca 256 bytes
    memory_free(ptr1); // Libera o primeiro bloco alocado
    void* ptr3 = memory_alloc(64); // Aloca 64 bytes

    return 0;
}
