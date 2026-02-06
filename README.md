 # Sistema de Gestión de Calificaciones con Estadísticas Básicas

 ## Descripción

 Programa en C++ que implementa una clase genérica `GradeBook<T>` para gestionar calificaciones de un grupo. Permite:

 - Almacenar calificaciones de N estudiantes en M materias (arreglo estático N x M).
 - Captura manual o generación aleatoria de calificaciones.
 - Calcular promedios por estudiante y por materia.
 - Encontrar la calificación mínima y máxima del conjunto.
 - Mostrar un reporte con la tabla de calificaciones y estadísticas.

 ## Requisitos

 - CMake 3.10+
 - Compilador con soporte C++17 (g++, clang, MSVC)

 ## Estructura del proyecto

 ```
 Practica A1/
 ├── CMakeLists.txt
 ├── README.md
 ├── src/
 │   ├── main.cpp
 │   └── gradebook.hpp
 └── build/    # carpeta de compilación (no subir al repo)
 ```

 ## Compilación

 ### Windows (PowerShell, MinGW)
 ```powershell
 cd "C:\Users\Walmart\Desktop\Practica A1"
 mkdir build -ErrorAction SilentlyContinue
 cd build
 cmake .. -G "MinGW Makefiles"
 mingw32-make
 .\gradebook.exe
 ```

 ### Linux / macOS
 ```bash
 cd /ruta/a/Practica\ A1
 mkdir -p build && cd build
 cmake ..
 make
 ./gradebook
 ```

 ## Uso

 Ejecuta el binario y usa el menú para ingresar calificaciones manualmente, generar aleatorias o mostrar el reporte.

 ## Archivos incluidos

 - `src/main.cpp`: programa principal con menú interactivo.
 - `src/gradebook.hpp`: clase genérica `GradeBook<T>` con métodos para entrada y cálculos.
 - `CMakeLists.txt`: archivo de configuración para CMake.
 - `PRUEBAS.md`: casos de prueba y evidencia.

 ## Entregables

 1. Repositorio GitHub con todo el código fuente y documentación (`README.md`, `PRUEBAS.md`).
 2. Estructura de carpetas según lo indicado.
 3. Instrucciones de compilación en `README.md`.

 ## Autor
 Estudiante de Estructura de Datos

 ## Licencia
 Proyecto educativo

