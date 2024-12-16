#include "nuevag.h"
#include "tablero.h"

int **nuevaGeneracion(int **tablero, int **vecinos, int filas, int columnas) {
  int **nGeneracion = crearTablero(filas, columnas);

  // Recorrer cada posición del tablero
  for (int x = 0; x < filas; x++) {
    for (int y = 0; y < columnas; y++) {
      if (tablero[x][y] == 1) {
        // Célula viva: sobrevive si tiene 2 o 3 vecinos
        if (vecinos[x][y] == 2 || vecinos[x][y] == 3) {
          nGeneracion[x][y] = 1; // Sobrevive
        } else {
          nGeneracion[x][y] = 0; // Muere
        }
      } else {
        // Célula muerta: revive si tiene exactamente 3 vecinos
        if (vecinos[x][y] == 3) {
          nGeneracion[x][y] = 1; // Nace
        } else {
          nGeneracion[x][y] = 0; // Permanece muerta
        }
      }
    }
  }

  return nGeneracion;
}
