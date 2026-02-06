# Especificaciones Técnicas del Proyecto

## 1. Requisitos Funcionales

### RF1: Sistema de Almacenamiento de Calificaciones
- **Descripción**: El sistema debe almacenar calificaciones de N estudiantes en M materias
- **Implementación**: Arreglo bidimensional estático de tipo `T grades[NUM_STUDENTS][NUM_SUBJECTS]`
- **Capacidad**: 5 estudiantes x 4 materias (configurable en código)
- **Rango de Valores**: 0-100 (sin validación, confianza en usuario)

### RF2: Ingreso de Datos
- **Ingreso Manual**: Usuario ingresa cada calificación manualmente
- **Ingreso Aleatorio**: Sistema genera valores aleatorios entre 50 y 100
- **Validación**: No se valida entrada (fuera de alcance actual)

### RF3: Cálculos Estadísticos
- **Promedio por Estudiante**: Suma de calificaciones / Número de materias
- **Promedio por Materia**: Suma de calificaciones / Número de estudiantes
- **Calificación Mínima**: Búsqueda exhaustiva en todo el arreglo
- **Calificación Máxima**: Búsqueda exhaustiva en todo el arreglo

### RF4: Generación de Reportes
- **Tabla de Calificaciones**: Formato con bordes y alineación
- **Promedios por Estudiante**: Lista con identificación
- **Promedios por Materia**: Lista con identificación
- **Estadísticas Generales**: Mínimo y máximo con precisión de 2 decimales

### RF5: Interfaz de Usuario
- **Menú Principal**: Menú interactivo con 4 opciones
- **Navegación**: Permite ciclar entre opciones
- **Salida**: Opción para terminar el programa

---

## 2. Requisitos No Funcionales

### RNF1: Lenguaje y Compilación
- **Lenguaje**: C++17
- **Compilador**: Compatible con estándar C++17
- **Sistema de Compilación**: CMake 3.10+
- **Plataformas**: Windows, Linux, macOS

### RNF2: Rendimiento
- **Operaciones**: O(n*m) para cálculos
- **Memoria**: Fija, aproximadamente 80-160 bytes para arreglo de calificaciones
- **Resolución**: < 1 segundo para todas las operaciones

### RNF3: Código
- **Plantillas**: Usa template<typename T> para flexibilidad de tipos
- **Encapsulación**: Atributos privados, métodos públicos
- **Estilo**: Nombres descriptivos en inglés/español

### RNF4: Documentación
- README.md con instrucciones de compilación
- PRUEBAS.md con casos de prueba
- Comentarios en código
- Código limpio y legible

---

## 3. Especificación de la Clase Template GradeBook<T>

### Atributos Privados

```cpp
private:
    T grades[NUM_STUDENTS][NUM_SUBJECTS];  // Matriz 5x4 de calificaciones
    std::string studentNames[NUM_STUDENTS];  // Nombres de 5 estudiantes
    std::string subjectNames[NUM_SUBJECTS];  // Nombres de 4 materias
```

### Métodos Públicos

#### Constructor
```cpp
GradeBook()
// Inicializa nombres de estudiantes y materias
```

#### Métodos de Entrada
```cpp
void inputGradesManual()
// Lee calificaciones línea por línea desde entrada estándar

void inputGradesRandom()
// Genera valores aleatorios 50-100 para todas las celdas
```

#### Métodos de Cálculo
```cpp
T getStudentAverage(int studentIndex)
// Retorna promedio de un estudiante específico

T getSubjectAverage(int subjectIndex)
// Retorna promedio de una materia específica

T getMinGrade()
// Retorna la calificación mínima del arreglo

T getMaxGrade()
// Retorna la calificación máxima del arreglo
```

#### Métodos de Presentación
```cpp
void displayGradeTable()
// Imprime tabla formateada de calificaciones

void displayReport()
// Imprime reporte completo con todas las estadísticas
```

### Tipos Soportados

| Tipo | Descripción | Uso |
|------|-------------|-----|
| int | Enteros sin decimales | Cuando se requiere precisión entera |
| float | Decimales de 32 bits | Estándar, precisión suficiente |
| double | Decimales de 64 bits | Máxima precisión |

---

## 4. Estructura de Directorios

```
Practica A1/
├── CMakeLists.txt              # Configuración de build
├── README.md                   # Manual del usuario
├── PRUEBAS.md                  # Reporte de pruebas
├── ESPECIFICACIONES.md         # Este documento
├── src/
│   ├── main.cpp                # Función principal
│   └── gradebook.hpp           # Clase template GradeBook
└── build/
    ├── CMakeCache.txt
    ├── CMakeFiles/
    ├── Makefile
    └── gradebook (o .exe)      # Ejecutable
```

---

## 5. Constantes de Configuración

En `src/gradebook.hpp` líneas 9-10:

```cpp
const int NUM_STUDENTS = 5;    // Estudiantes (editable)
const int NUM_SUBJECTS = 4;    // Materias (editable)
```

Para cambiar a 10 estudiantes y 6 materias:
```cpp
const int NUM_STUDENTS = 10;
const int NUM_SUBJECTS = 6;
```

**Nota**: Requiere recompilar después de cambios

---

## 6. Flujo de Ejecución

```
┌─────────────────────────────────────┐
│  Inicio del Programa                │
├─────────────────────────────────────┤
│  Crear objeto GradeBook<float>      │
├─────────────────────────────────────┤
│  ┌───────────────────────────────┐  │
│  │ Mostrar Menú Principal        │  │
│  ├───────────────────────────────┤  │
│  │ Opción 1: Ingreso Manual      │  │ ─► getGradesManual()
│  │ Opción 2: Ingreso Aleatorio   │  │ ─► inputGradesRandom()
│  │ Opción 3: Ver Reporte         │  │ ─► displayReport()
│  │ Opción 4: Salir               │  │ ─► exit(0)
│  └───────────────────────────────┘  │
│         ▲                            │
│         │ (Loop hasta opción 4)      │
│         └────────────────────────────┘
└─────────────────────────────────────┘
```

---

## 7. Matriz de Cálculo de Promedios

### Ejemplo: Arreglo 5x4

```
            Mat    Esp    Ing    Cien
Alumno 1    85     78     92     88      Promedio: 85.75
Alumno 2    76     85     80     79      Promedio: 80.00
Alumno 3    82     80     87     91      Promedio: 85.00
Alumno 4    88     92     85     79      Promedio: 86.00
Alumno 5    71     68     75     73      Promedio: 71.75
         ────────────────────────
Promedio   80.4   80.6   83.8   82.0
```

### Fórmula de Promedio por Estudiante (i)
```
Promedio_Estudiante[i] = Σ(grades[i][j]) / NUM_SUBJECTS
                         j=0 a 3
```

### Fórmula de Promedio por Materia (j)
```
Promedio_Materia[j] = Σ(grades[i][j]) / NUM_STUDENTS
                      i=0 a 4
```

---

## 8. Formato de Salida

### Precisión Decimal
- **Todos los promedios**: 2 decimales usando `std::fixed << std::setprecision(2)`
- **Tabla de calificaciones**: 2 decimales
- **Estadísticas**: 2 decimales

### Ancho de Columnas
- Columna de etiqueta: 15 caracteres
- Otras columnas: 15 caracteres
- Alineación: izquierda (std::left)

### Separadores
- Líneas horizontales: carácter '-' repetido
- Bordes de menú: caracteres Unicode ║, ═, ╔, ╗, ╚, ╝
- Símbolos: ✓ (éxito), ✗ (error)

---

## 9. Consideraciones de Implementación

### Ventajas del Template
✓ Reutilización de código
✓ Flexibilidad de tipos
✓ Sin overhead de herencia
✓ Type-safe en tiempo de compilación

### Limitaciones Actuales
⚠ Tamaño de arreglo fijo (no dinámico)
⚠ Sin validación de entrada
⚠ Sin persistencia de datos (archivo)
⚠ Sin tratamiento de excepciones

### Posibles Mejoras Futuras
- [ ] Usar std::vector<std::vector<T>> para tamaño dinámico
- [ ] Agregar validación de calificaciones (0-100)
- [ ] Guardar/cargar calificaciones de archivo
- [ ] Calcular desviación estándar y varianza
- [ ] Interfaz gráfica (GUI)
- [ ] Base de datos

---

## 10. Notas de Desarrollo

### Compilación en GCC/Clang
```bash
g++ -std=c++17 -o gradebook src/main.cpp -I src
```

### Compilación en MSVC
```bash
cl /std:c++17 /Iincluir src\main.cpp
```

### Debugging
```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
gdb ./gradebook          # En systems Unix
windbg gradebook.exe     # En Windows
```

---

## 11. Control de Versiones

**Versión**: 1.0  
**Estado**: Requisitos implementados y funcionales

---

**Especificaciones del Proyecto**  
Sistema de Gestión de Calificaciones con Estadísticas Básicas
