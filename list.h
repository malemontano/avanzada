#include <stdint.h>
#include <stdio.h>
#include "type.h"


typedef struct node {
    void* data;
    struct node* next;
} node_t;

typedef struct list {
    type_t type;
    uint8_t size;
    node_t* first;
} list_t;

list_t* listNew(type_t t);
void listAddFirst(list_t* l, void* data);
void* listGet(list_t* l, uint8_t i); // se asume: i < l->size
void* listRemove(list_t* l, uint8_t i); // se asume: i < l->size
void listDelete(list_t* l);
void listSwapNodes(list_t* l, uint8_t i, uint8_t j);




