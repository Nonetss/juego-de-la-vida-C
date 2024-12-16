
#include "sdl_handler.h"
#include <stdio.h>

// Inicializar SDL y crear ventana y renderer
SDL_Window *initSDL(SDL_Renderer **renderer, int width, int height) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Error al inicializar SDL: %s\n", SDL_GetError());
    return NULL;
  }

  SDL_Window *window =
      SDL_CreateWindow("Juego de la Vida", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

  if (!window) {
    printf("Error al crear la ventana: %s\n", SDL_GetError());
    return NULL;
  }

  *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!*renderer) {
    printf("Error al crear el renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    return NULL;
  }

  return window;
}

// Renderizar el tablero en la ventana
void renderTablero(SDL_Renderer *renderer, int **tablero, int filas,
                   int columnas, int cellSize) {
  for (int x = 0; x < filas; x++) {
    for (int y = 0; y < columnas; y++) {
      SDL_Rect rect = {y * cellSize, x * cellSize, cellSize, cellSize};

      if (tablero[x][y] == 1) {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0,
                               255); // Verde para células vivas
      } else {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0,
                               255); // Negro para células muertas
      }

      SDL_RenderFillRect(renderer, &rect);
    }
  }
}
