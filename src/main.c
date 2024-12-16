#include "tablero/tablero.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Dimensiones del tablero
    int filas = 10;
    int columnas = 10;

    // Inicializar la semilla para números aleatorios
    srand(time(NULL));

    // Crear el tablero
    int **tablero = crearTablero(filas, columnas);

    // Inicializar el tablero con valores aleatorios
    inicializarTablero(tablero, filas, columnas);

    // Imprimir el tablero inicial
    printf("Tablero inicial:\n");
    imprimirTablero(tablero, filas, columnas);

    // Liberar memoria del tablero
    liberarTablero(tablero, filas);

    return 0;
}
