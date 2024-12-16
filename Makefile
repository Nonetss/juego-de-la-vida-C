# Archivos fuente
SRCS = src/main.c src/tablero/tablero.c src/reglas/reglas.c src/tablero/nuevag.c src/windous/sdl_handler.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Compilación
CC = gcc
CFLAGS = -Wall -Wextra -g -I./src -I/usr/include/SDL2
LDFLAGS = -lSDL2

# Regla principal
juego: $(OBJS)
	$(CC) $(OBJS) -o juego $(LDFLAGS)

# Regla para compilar los archivos fuente a objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS) juego
