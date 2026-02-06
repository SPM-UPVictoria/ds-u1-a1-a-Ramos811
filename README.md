# Sistema de Gestión de Calificaciones con Estadísticas Básicas

## Descripción

Sistema en C++ que implementa una clase template `GradeBook<T>` para la gestión de calificaciones de estudiantes. El programa permite:

- ✓ Almacenar calificaciones de N estudiantes en M materias usando un arreglo bidimensional estático
- ✓ Calcular promedios por estudiante
- ✓ Calcular promedios por materia
- ✓ Obtener calificaciones mínima y máxima del sistema
- ✓ Ingreso manual o aleatorio de calificaciones
- ✓ Generación de reportes detallados

## Requisitos Previos

- **CMake** (versión 3.10 o superior)
- **Compilador C++** que soporte C++17 (g++, clang, MSVC)
- **Windows**: MinGW-w64 o MSVC
- **Linux/Mac**: g++ o clang

### Instalación de Herramientas

#### Windows
```bash
# Descargar CMake desde: https://cmake.org/download/
# Descargar MinGW-w64 desde: https://sourceforge.net/projects/mingw-w64/
```

#### Linux (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install cmake g++ build-essential
```

#### macOS
```bash
brew install cmake gcc
```

## Estructura del Proyecto

```
Practica A1/
├── CMakeLists.txt          # Configuración de compilación
├── README.md               # Este archivo
├── src/
│   ├── main.cpp            # Programa principal
│   └── gradebook.hpp       # Clase template GradeBook
└── build/                  # Carpeta de compilación (se crea automáticamente)
    └── gradebook           # Ejecutable generado
```

## Instrucciones de Compilación

### Opción 1: Compilación en Windows (PowerShell)

```powershell
# Navegar a la carpeta del proyecto
cd C:\Users\Tu Usuario\Desktop\Practica A1

# Crear carpeta de compilación y compilar
mkdir build -ErrorAction SilentlyContinue
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make

# Ejecutar el programa
.\gradebook.exe
```

### Opción 2: Compilación en Linux/macOS

```bash
# Navegar a la carpeta del proyecto
cd ~/Desktop/Practica\ A1

# Crear carpeta de compilación y compilar
mkdir -p build && cd build
cmake ..
make

# Ejecutar el programa
./gradebook
```

### Opción 3: Compilación con Visual Studio (Windows)

```bash
cd Practica A1
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
cmake --build . --config Release
# Luego abrir el .sln generado en Visual Studio
```

## Uso del Programa

Después de compilar, ejecuta:

```bash
./gradebook          # Linux/macOS
.\gradebook.exe      # Windows
```

El programa muestra un menú interactivo:

```
╔════════════════════════════════════════════════════════╗
║   SISTEMA DE GESTIÓN DE CALIFICACIONES                ║
║   Estructura de Datos - Actividad Práctica 1          ║
╚════════════════════════════════════════════════════════╝

╔════════════════════════════════════════════════════════╗
║              MENÚ DE OPCIONES                          ║
║  1. Ingresar calificaciones manualmente                ║
║  2. Generar calificaciones aleatoriamente             ║
║  3. Mostrar reporte completo                          ║
║  4. Salir                                             ║
╚════════════════════════════════════════════════════════╝
```

### Ejemplo de Uso

1. **Opción 2**: Genera 5 estudiantes x 4 materias con calificaciones aleatorias (50-100)
2. **Opción 3**: Muestra:
   - Tabla de calificaciones
   - Promedio por estudiante
   - Promedio por materia
   - Calificación mínima y máxima general

## Características Principales

### Clase Template GradeBook<T>

```cpp
template <typename T>
class GradeBook {
    // Soporta: int, float, double
    
    // Métodos principales:
    void inputGradesManual();           // Ingreso manual de calificaciones
    void inputGradesRandom();           // Genera calificaciones aleatorias
    T getStudentAverage(int index);     // Promedio por estudiante
    T getSubjectAverage(int index);     // Promedio por materia
    T getMinGrade();                    // Calificación mínima
    T getMaxGrade();                    // Calificación máxima
    void displayReport();               // Reporte completo
};
```

### Configuración

Editar `src/gradebook.hpp` para cambiar:

```cpp
const int NUM_STUDENTS = 5;    // Número de estudiantes
const int NUM_SUBJECTS = 4;    // Número de materias
```

## Reporte de Salida

El programa genera un reporte como el siguiente:

```
==================================================
         REPORTE DE CALIFICACIONES DEL GRUPO
==================================================

=== TABLA DE CALIFICACIONES ===
Estudiante      Matemáticas     Español         Inglés          Ciencias
----------------------------------------------------------------------
Alumno 1        85.50           78.00           92.00           88.50
Alumno 2        76.00           85.50           80.00           79.00
...

=== PROMEDIO POR ESTUDIANTE ===
Alumno 1        : 86.00
Alumno 2        : 80.13
...

=== PROMEDIO POR MATERIA ===
Matemáticas     : 82.10
Español         : 81.50
...

=== ESTADÍSTICAS GENERALES ===
Calificación mínima general: 50.00
Calificación máxima general: 100.00
==================================================
```

## Detalles Técnicos

- **Tipo de Datos**: Usa plantillas para soportar int, float y double
- **Almacenamiento**: Arreglo bidimensional estático (5x4)
- **Encapsulación**: Atributos privados, métodos públicos
- **Compilación**: CMake multiplataforma
- **Estándar**: C++17

## Solución de Problemas

### Error: "cmake: command not found"
```bash
# Windows: Agregar CMake al PATH o usar la ruta completa
"C:\Program Files\CMake\bin\cmake.exe" ..

# Linux: Instalar cmake
sudo apt-get install cmake
```

### Error: "mingw32-make: command not found"
```bash
# Usar make en su lugar (si está disponible)
make
# O compilar directamente
g++ -std=c++17 -o gradebook src/main.cpp
```

### Error de compilación en macOS
```bash
# Asegurar que Xcode Command Line Tools está instalado
xcode-select --install
```

## Autor
Estudiante de Estructura de Datos

## Licencia
Proyecto educativo
