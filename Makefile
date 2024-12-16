# Nombre del ejecutable
TARGET = juego

# Archivos fuente
SRCS = src/main.c src/tablero/tablero.c src/reglas/reglas.c src/tablero/nuevag.c

# Archivos objeto (se generan automáticamente)
OBJS = $(SRCS:.c=.o)

# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Wextra -g -I./src/tablero  -I./src/reglas

# Regla principal: cómo construir el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar los archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar los archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

# Regla para recompilar todo
rebuild: clean $(TARGET)
