#include <stdio.h>

typedef struct{
        char* nombre;
        int vida;
        double ataque;
        double defensa;
    }monstruo_t;

monstruo_t evolution(monstruo_t monster);
int main(){
    monstruo_t monstruos[2]={{"Oli",10,5.2,3.0}, {"Male", 100, 30.5, 20}};
    int length = sizeof(monstruos)/sizeof(monstruos[0]);

    for(int i=0; i<length; i++){
        printf("nombre: %s, vida: %d \n", monstruos[i].nombre, monstruos[i].vida);
    }
    monstruo_t monster1 = {"Kir", 100000, 300, 450.5};
    monstruo_t nuevo = evolution(monster1);
    printf("nombre: %s, vida: %d, ataqueAnterior: %f, ataquePosterior: %f, defensaAnterior: %f, defensaPosterior: %f\n", nuevo.nombre, nuevo.vida, monster1.ataque, nuevo.ataque, monster1.defensa, nuevo.defensa);
}

monstruo_t evolution(monstruo_t monster){
    char* nombre = monster.nombre; //como creo un nuevo monstruo?
    int vida = monster.vida;
    double ataque = monster.ataque + 10;
    double defensa = monster.defensa + 10;
    monstruo_t newMonster = {nombre, vida, ataque, defensa};
    return newMonster;
}