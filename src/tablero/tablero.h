#ifndef TABLERO_H
#define TABLERO_H

// Declaraciones de las funciones
int **crearTablero(int filas, int columnas);
void inicializarTablero(int **tablero, int filas, int columnas);
void imprimirTablero(int **tablero, int filas, int columnas);
void liberarTablero(int **tablero, int filas);
int hayCelulasVivas(int **tablero, int filas, int columnas);

#endif // TABLERO_H
