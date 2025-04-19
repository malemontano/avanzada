# include <stdio.h>
int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    // p apunta al int en la fila 0, columna 0
    int *p = &matrix[0][0]; //p tiene como valor la dir de matrix[0][0]
    // ¿que es reshape?
    int (*reshape)[2] = (int (*)[2]) p;
    printf("%d\n", p[3]); // Que imprime esta lınea?
    printf("%d\n", reshape[1][1]); // Que imprime esta lınea?
    return 0;
}