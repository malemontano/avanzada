#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {
    list_t* l = listNew(TypeFAT32);
    fat32_t* f1 = new_fat32();
    fat32_t* f2 = new_fat32();
    listAddFirst(l, f1);
    listAddFirst(l, f2);
    listDelete(l);
    rm_fat32(f1);
    rm_fat32(f2);
    
    list_t* lista = listNew(TypeFAT32);

    // Crear elementos FAT32
    fat32_t* f6 = new_fat32();
    fat32_t* f7 = new_fat32();
    fat32_t* f3 = new_fat32();
    fat32_t* f4 = new_fat32();
    fat32_t* f5 = new_fat32();

    // Agregar elementos a la lista
    listAddFirst(lista, f6);
    listAddFirst(lista, f7);
    listAddFirst(lista, f3);
    listAddFirst(lista, f4);
    listAddFirst(lista, f5);

    // Intercambiar el primer y el último nodo
    listSwapNodes(lista, 0, 4);

    // Imprimir la lista después del swap
    node_t* current = lista->first;
    while (current) {
        printf("Nodo: %p, Valor: %u -> ", (void*)current, *(fat32_t*)current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Liberar memoria
    listDelete(lista);
    rm_fat32(f6);
    rm_fat32(f7);
    rm_fat32(f3);
    rm_fat32(f4);
    rm_fat32(f5);
    return 0;
}