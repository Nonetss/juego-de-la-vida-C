#include "reglas/reglas.h"
#include "tablero/nuevag.h" // Incluye la función nuevaGeneración
#include "tablero/tablero.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Para sleep()

int main() {
  // Dimensiones del tablero
  int filas = 10;
  int columnas = 10;

  // Inicializar la semilla para números aleatorios
  srand(time(NULL));

  // Crear el tablero inicial
  int **tablero = crearTablero(filas, columnas);

  // Inicializar el tablero con valores aleatorios
  inicializarTablero(tablero, filas, columnas);

  // Imprimir el tablero inicial
  printf("Tablero inicial:\n");
  imprimirTablero(tablero, filas, columnas);

  // Bucle para continuar el juego mientras haya células vivas
  while (hayCelulasVivas(tablero, filas, columnas)) {
    // Calcular los vecinos vivos
    int **vecinos = calcularVecinos(tablero, filas, columnas);

    // Crear la nueva generación basada en el tablero y los vecinos vivos
    int **nuevaGeneracionTablero =
        nuevaGeneracion(tablero, vecinos, filas, columnas);

    // Liberar el tablero actual y los vecinos
    liberarTablero(tablero, filas);
    liberarTablero(vecinos, filas);

    // Actualizar el tablero con la nueva generación
    tablero = nuevaGeneracionTablero;

    // Imprimir la nueva generación
    printf("\nNueva generación:\n");
    imprimirTablero(tablero, filas, columnas);
    sleep(1);
  }

  // Liberar la última generación
  liberarTablero(tablero, filas);

  return 0;
}
