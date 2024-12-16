# Juego de la Vida en C

Este es un proyecto hecho para practicar y aprender los fundamentos de **C**, trabajando con:

- Memoria dinámica.
- Modularización del código.
- Bibliotecas gráficas como **SDL2**.

El proyecto implementa el famoso **Juego de la Vida de Conway**, donde las células vivas y muertas se representan con colores en una ventana gráfica.

## Cómo usarlo

1. **Compila el proyecto:**

   ```bash
   make
   ```

2. **Ejecuta el programa:**

   ```bash
   ./juego
   ```

3. **Configura las dimensiones del tablero:**

   - Al iniciar, el programa te pedirá que introduzcas el número de filas y columnas.

4. **Disfruta de la simulación gráfica:**
   - Células vivas se muestran de color verde.
   - Células muertas se muestran en negro.

## Notas

- Este proyecto es para **practicar y aprender C**, por lo que no busca ser perfecto ni el más eficiente.
- Se utilizó **SDL2** para la visualización gráfica. Si tienes problemas al compilar, asegúrate de tener instaladas las bibliotecas necesarias.

## Cómo limpiar el proyecto

Para eliminar los archivos generados durante la compilación:

```bash
make clean
```
