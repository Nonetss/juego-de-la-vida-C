#include "reglas.h"
#include "../tablero/tablero.h"

int **calcularVecinos(int **tablero, int filas, int columnas) {
  // Crear una matriz para almacenar el número de vecinos vivos
  int **vecinosTablero = crearTablero(filas, columnas);

  // Recorrer cada posición del tablero
  for (int x = 0; x < filas; x++) {
    for (int y = 0; y < columnas; y++) {
      int pos[2] = {x, y};
      vecinosTablero[x][y] = contarVecinosVivos(tablero, filas, columnas, pos);
    }
  }

  return vecinosTablero;
}

int contarVecinosVivos(int **tablero, int filas, int columnas, int pos[2]) {
  int vecinos = 0;

  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0)
        continue;

      int filVecino = pos[0] + i;
      int colVecino = pos[1] + j;

      if (filVecino >= 0 && filVecino < filas && colVecino >= 0 &&
          colVecino < columnas) {
        vecinos += tablero[filVecino][colVecino];
      }
    }
  }

  return vecinos;
}
