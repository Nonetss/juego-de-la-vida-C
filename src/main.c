#include <SDL2/SDL.h>
#include "tablero/tablero.h"
#include "reglas/reglas.h"
#include "tablero/nuevag.h"
#include "windous/sdl_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int filas = 30, columnas = 30, cellSize = 20;
    int width = columnas * cellSize;
    int height = filas * cellSize;

    // Inicializar SDL
    SDL_Renderer *renderer;
    SDL_Window *window = initSDL(&renderer, width, height);
    if (!window) return 1;

    // Inicializar tablero
    srand(time(NULL));
    int **tablero = crearTablero(filas, columnas);
    inicializarTablero(tablero, filas, columnas);

    int running = 1;
    SDL_Event event;

    // Bucle principal
    while (running) {
        // Manejo de eventos
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Renderizar tablero
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Fondo blanco
        SDL_RenderClear(renderer);
        renderTablero(renderer, tablero, filas, columnas, cellSize);
        SDL_RenderPresent(renderer);

        // Calcular nueva generación
        int **vecinos = calcularVecinos(tablero, filas, columnas);
        int **nuevaGen = nuevaGeneracion(tablero, vecinos, filas, columnas);
        liberarTablero(tablero, filas);
        liberarTablero(vecinos, filas);
        tablero = nuevaGen;

        // Esperar 100ms (10 fps)
        SDL_Delay(100);
    }

    // Liberar recursos
    liberarTablero(tablero, filas);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
