#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t* listNew(type_t t) {
    list_t* l = malloc(sizeof(list_t));
    l->type = t; // l->type es equivalente a (*l).type
    l->size = 0;
    l->first = NULL;
    return l;
}

void listAddFirst(list_t* l, void* data) {
    node_t* n = malloc(sizeof(node_t));
    switch(l->type) {
        case TypeFAT32:
        n->data = (void*) copy_fat32((fat32_t*) data);
        break;
        case TypeEXT4:
            n->data = (void*) copy_ext4((ext4_t*) data);
            break;
        case TypeNTFS:
            n->data = (void*) copy_ntfs((ntfs_t*) data);
            break;
    }
    n->next = l->first;
    l->first = n;
    l->size++;
}
    //se asume: i < l->size
void* listGet(list_t* l, uint8_t i){
    node_t* n = l->first;
    for(uint8_t j = 0; j < i; j++)
        n = n->next;
    return n->data;
    }
    //se asume: i < l->size
void* listRemove(list_t* l, uint8_t i){
    node_t* tmp = NULL;
    void* data = NULL;
    if(i == 0){
        data = l->first->data;
        tmp = l->first;
        l->first = l->first->next;
    }else{
        node_t* n = l->first;
        for(uint8_t j = 0; j < i - 1; j++)
            n = n->next;
        data = n->next->data;
        tmp = n->next;
        n->next = n->next->next;
    }
    free(tmp);
    l->size--;
    return data;
}

void listDelete(list_t* l){
    node_t* n = l->first;
    while(n){
        node_t* tmp = n;
        n = n->next;
        switch(l->type) {
            case TypeFAT32:
                rm_fat32((fat32_t*) tmp->data);
                break;
            case TypeEXT4:
                rm_ext4((ext4_t*) tmp->data);
                break;
            case TypeNTFS:
                rm_ntfs((ntfs_t*) tmp->data);
                break;
        }
        free(tmp);
    }
    free(l);
}

void listSwapNodes(list_t* l, uint8_t i, uint8_t j){
    if(l==NULL || l->size < 2 || i==j){return;}
    node_t* node_i = NULL;
    node_t* prev_i = NULL;
    node_t* node_j = NULL;
    node_t* prev_j = NULL;
    node_t* current = l->first;
    node_t* prev = NULL;

    if(i>j){
        uint8_t n = i;
        i = j;
        j = n;
    }
    
    
    for(int k = 0; k <= j; k++){
        if (current == NULL) { return; }
        if(k==i){
            node_i = current;
            prev_i = prev;
        }
        if(k==j){
            node_j = current;
            prev_j = prev;
        }
        prev = current;
        current = current->next;
        
    }

    node_t* temp = node_j->next;
    if(i==0){
        l->first=node_j;//caso i==0
    }
    
    if(j==i+1){//si son consecutivos
        if(prev_i != NULL){
            prev_i->next = node_j;
        }
        node_j->next = node_i;
        node_i->next = temp;
    }else{
        node_j->next = node_i->next;
        node_i->next = temp;
        if (prev_i) {
            prev_i->next = node_j;
        }
        if (prev_j) {
            prev_j->next = node_i;
        }

    }
    
}