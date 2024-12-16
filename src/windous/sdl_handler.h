
#ifndef SDL_HANDLER_H
#define SDL_HANDLER_H

#include <SDL2/SDL.h>

// Declarar la función para inicializar SDL y crear la ventana
SDL_Window *initSDL(SDL_Renderer **renderer, int width, int height);

// Declarar la función para renderizar el tablero
void renderTablero(SDL_Renderer *renderer, int **tablero, int filas,
                   int columnas, int cellSize);

#endif // SDL_HANDLER_H
