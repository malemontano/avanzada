#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define NAME_LEN 50
typedef struct persona_s {
        char nombre[NAME_LEN+1];
        int edad;
    } persona_t;
void crearPersona(char* nombrePersona, int edadPersona){
    persona_t *nuevaPersona = malloc(sizeof(persona_t));
    if(nuevaPersona != NULL){
        (*nuevaPersona).nombre = nombrePersona;
        (*nuevaPersona).edad = edadPersona;
    }
}
int main(){
    
}