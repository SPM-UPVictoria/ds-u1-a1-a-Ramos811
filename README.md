[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jgdpDkeE)
# Estructura de Datos - Unidad 1 - Actividad práctica 1 - A

## Sistema de Gestión de Calificaciones con Estadísticas Básicas

---

## Descripción del problema

Desarrollar un programa en C++ que modele un pequeño Sistema de Gestión de Calificaciones de un grupo. El sistema deberá:

1. Administrar calificaciones de N estudiantes en M materias mediante:
    * Un arreglo bidimensional estático N x M para almacenar calificaciones numéricas.
    * La captura manual o aleatoria de las calificaciones.

2. Implementar una clase genérica `GradeBook<T>` que:
    * Sea una plantilla (`template <typename T>`).
    * Almacene las calificaciones.
    * Permita operaciones como:
        * Obtener el promedio por estudiante.
        * Obtener el promedio por materia.
        * Obtener la calificación mínima y máxima del arreglo.

3. El programa principal (main.cpp) deberá:
    * Declarar un objeto `GradeBook<float>`, `GradeBook<int>` o  `GradeBook<double>`.
    * Llenar las calificaciones.
    * Mostrar un reporte como el siguiente:
    >> ```bash
    >> Promedio por estudiante:
    >> Alumno 1: 78.3
    >> Alumno 2: 85.2
    >> ...
    >> Promedio por materia:
    >> Materia 1: 80.1
    >> Materia 2: 76.8
    >> ...
    >> Calificación mínima general: 55.0
    >> Calificación máxima general: 100.0
    >> ```

---

## Estructura mínima del proyecto (usando CMake)

```CSS
/practica1
│── CMakeLists.txt
│── src/
│   ├── main.cpp
│   └── gradebook.hpp
```

### Requerimientos técnicos

El estudiante debe crear un `CMakeLists.txt` mínimo que:
* Genere un ejecutable.
* Organice correctamente los archivos bajo `/src`.
* Permita compilar con:

```bash
mkdir build && cd build
cmake ..
make
```

#### Clases

* Mínimo 1 clase (`GradeBook`).
* Encapsulación correcta.
* Métodos públicos para cálculos estadísticos.

#### Arreglos

* Arreglo estático bidimensional para las calificaciones.
* Uso de arreglo unidimensional para estadísticas temporales cuando sea necesario.

#### Plantillas

* La clase debe aceptar distintos tipos numéricos (`int`, `float`, `double`).

---

## Entregables

1. Repositorio en GitHub, el cual debe contener:
    * Todo el código fuente.
    * El archivo `CMakeLists.txt`
    * Instrucciones de compilación en `README.md`.
    * Estructura de carpetas indicada.

2. Reporte de pruebas el cual debe incluir
    * Estrategia de pruebas: Qué se buscó probar: promedios, mínimos, máximos, entrada, etc.
    * Casos de prueba ejecutados (pantallasos)


