#include <stdio.h>
#include <stdlib.h>
#include "tablero.h"

// Crear una matriz dinámica
int **crearTablero(int filas, int columnas) {
    int **tablero = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        tablero[i] = (int *)malloc(columnas * sizeof(int));
    }
    return tablero;
}

// Inicializar la matriz con valores aleatorios
void inicializarTablero(int **tablero, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            tablero[i][j] = rand() % 2;
        }
    }
}

// Imprimir el tablero
void imprimirTablero(int **tablero, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
}

// Liberar la memoria asignada al tablero
void liberarTablero(int **tablero, int filas) {
    for (int i = 0; i < filas; i++) {
        free(tablero[i]);
    }
    free(tablero);
}
