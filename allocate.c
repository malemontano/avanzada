#include <stdlib.h>
#include <stdio.h>

void allocateArray(int **arr, int size, int value) {
    *arr = (int*)malloc(size * sizeof(int));//malloc devuelve puntero de tipo void, castearlo al tipo correcto. 
    //SE MODIFICA LOCALMENTE, CUANDO VUELVA A MAIN VECTOR SIGUE SIENDO NULL
    if(*arr != NULL) {
        for(int i=0; i<size; i++) {
            (*arr)[i] = value;
        }
    }
}
// Uso
int main(){
    int *vector = NULL;
    allocateArray(&vector,5,45);
    for(int i = 0; i < 5; i++){
        printf("%d\n", vector[i]);
    }
    free(vector);
}
