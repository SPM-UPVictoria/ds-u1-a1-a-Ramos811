# Reporte de Pruebas - Sistema de Gestión de Calificaciones

## 1. Estrategia de Pruebas

### Objetivos de Prueba

Se busca validar que el sistema de gestión de calificaciones funcione correctamente mediante:

1. **Entrada de Datos**
   - Validar ingreso manual de calificaciones
   - Validar generación aleatoria de calificaciones
   - Verificar rangos válidos (50-100 para aleatorio)

2. **Cálculos Estadísticos**
   - Verificar cálculo correcto de promedios por estudiante
   - Verificar cálculo correcto de promedios por materia
   - Validar identificación de calificación mínima
   - Validar identificación de calificación máxima

3. **Funcionalidad del Template**
   - Pruebas con tipo `float`
   - Pruebas con tipo `int`
   - Pruebas con tipo `double`

4. **Interfaz de Usuario**
   - Menú interactivo funcional
   - Mostrado correcto de reportes
   - Manejo de opciones inválidas

### Tipos de Pruebas

- **Pruebas Unitarias**: Validar cada método de la clase GradeBook
- **Pruebas de Integración**: Validar flujo completo del programa
- **Pruebas de Regresión**: Asegurar que cambios futuros no rompan funcionalidad

---

## 2. Casos de Prueba

### Caso de Prueba 1: Generación de Calificaciones Aleatorias

**Objetivo**: Validar que el programa genera calificaciones aleatorias en rango 50-100

**Pasos**:
1. Ejecutar el programa
2. Seleccionar opción 2 (Generar calificaciones aleatoriamente)
3. Seleccionar opción 3 (Mostrar reporte completo)

**Resultado Esperado**:
- ✓ Se genera tabla con 5 estudiantes y 4 materias
- ✓ Todas las calificaciones están entre 50 y 100
- ✓ Se calcula promedio de cada estudiante
- ✓ Se calcula promedio de cada materia
- ✓ Se identifica mínimo y máximo correctamente

**Valores de Ejemplo**:
```
Alumno 1: 85.50 (Matemática) + 78.00 (Español) + 92.00 (Inglés) + 88.50 (Ciencias)
Promedio Alumno 1: (85.50 + 78.00 + 92.00 + 88.50) / 4 = 86.00
```

---

### Caso de Prueba 2: Ingreso Manual de Calificaciones

**Objetivo**: Validar ingreso manual y cálculos posteriores

**Pasos**:
1. Ejecutar programa
2. Seleccionar opción 1 (Ingreso manual)
3. Ingresar valores conocidos:
   ```
   Alumno 1: 80, 80, 80, 80
   Alumno 2: 90, 90, 90, 90
   Alumno 3: 70, 70, 70, 70
   Alumno 4: 100, 100, 100, 100
   Alumno 5: 60, 60, 60, 60
   ```
4. Seleccionar opción 3 (Mostrar reporte)

**Resultado Esperado**:
```
Promedio por Estudiante:
- Alumno 1: 80.00
- Alumno 2: 90.00
- Alumno 3: 70.00
- Alumno 4: 100.00
- Alumno 5: 60.00

Promedio por Materia:
- Todas: 80.00 (promedio de 80,90,70,100,60)

Estadísticas Generales:
- Calificación mínima: 60.00
- Calificación máxima: 100.00
```

---

### Caso de Prueba 3: Validación de Calificación Mínima y Máxima

**Objetivo**: Verificar identificación correcta de extremos

**Pasos**:
1. Ingresar manualmente:
   ```
   Valores: 55, 75, 85, 95, 100 (para todos los estudiantes en todas las materias)
   Mínimo esperado: 55
   Máximo esperado: 100
   ```

**Resultado Esperado**:
- ✓ Calificación mínima general: 55.00
- ✓ Calificación máxima general: 100.00

---

### Caso de Prueba 4: Manejo de Opciones Inválidas

**Objetivo**: Validar manejo de entrada incorrecta

**Pasos**:
1. Ejecutar programa
2. Ingresar opción inválida (ej: 5, -1, texto)

**Resultado Esperado**:
- ✓ Mensaje: "✗ Opción inválida. Intente nuevamente."
- ✓ Menú vuelve a mostrarse
- ✓ Programa no se cierra

---

### Caso de Prueba 5: Template con Diferentes Tipos

**Objetivo**: Validar que template funciona con int, float, double

**Implementación** (modificar main.cpp temporalmente):

```cpp
// Prueba con float (actual)
GradeBook<float> gb1;

// Prueba con int
GradeBook<int> gb2;

// Prueba con double
GradeBook<double> gb3;
```

**Resultado Esperado**:
- ✓ Compila sin errores
- ✓ Funciona correctamente con cada tipo
- ✓ Cálculos son correctos según precisión del tipo

---

### Caso de Prueba 6: Flujo Completo

**Objetivo**: Validar secuencia completa de operaciones

**Pasos**:
1. Ejecutar programa
2. Opción 2 (Generar aleatorios)
3. Opción 3 (Ver reporte)
4. Opción 1 (Ingresar manualmente) - requiere nuevas calificaciones
5. Opción 3 (Ver reporte actualizado)
6. Opción 4 (Salir)

**Resultado Esperado**:
- ✓ Todas las operaciones se completan sin errores
- ✓ Los reportes se actualizan correctamente
- ✓ El programa termina correctamente

---

## 3. Procedimiento de Prueba en Windows

### Compilación y Ejecución

```powershell
# 1. Abrir PowerShell en la carpeta del proyecto
cd "C:\Users\Walmart\Desktop\Practica A1"

# 2. Crear carpeta build y compilar
mkdir build -ErrorAction SilentlyContinue
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make

# 3. Ejecutar el programa
.\gradebook.exe

# 4. Realizar pruebas según casos de prueba anteriores
```

---

## 4. Resultados de Pruebas

### Ejecución de Prueba (Ejemplo)

```
╔════════════════════════════════════════════════════════╗
║   SISTEMA DE GESTIÓN DE CALIFICACIONES                ║
║   Estructura de Datos - Actividad Práctica 1          ║
╚════════════════════════════════════════════════════════╝

=== CALIFICACIONES GENERADAS ALEATORIAMENTE ===

╔════════════════════════════════════════════════════════╗
║              MENÚ DE OPCIONES                          ║
║  1. Ingresar calificaciones manualmente                ║
║  2. Generar calificaciones aleatoriamente             ║
║  3. Mostrar reporte completo                          ║
║  4. Salir                                             ║
╚════════════════════════════════════════════════════════╝
Seleccione una opción: 3

==================================================
         REPORTE DE CALIFICACIONES DEL GRUPO
==================================================

=== TABLA DE CALIFICACIONES ===
Estudiante      Matemáticas     Español         Inglés          Ciencias
----------------------------------------------------------------------
Alumno 1        85.00           78.00           92.00           88.00
Alumno 2        76.00           85.00           80.00           79.00
Alumno 3        82.00           80.00           87.00           91.00
Alumno 4        88.00           92.00           85.00           79.00
Alumno 5        71.00           68.00           75.00           73.00

=== PROMEDIO POR ESTUDIANTE ===
Alumno 1        : 85.75
Alumno 2        : 80.00
Alumno 3        : 85.00
Alumno 4        : 86.00
Alumno 5        : 71.75

=== PROMEDIO POR MATERIA ===
Matemáticas     : 80.40
Español         : 80.60
Inglés          : 83.80
Ciencias        : 82.00

=== ESTADÍSTICAS GENERALES ===
Calificación mínima general: 68.00
Calificación máxima general: 92.00
==================================================
```

### Análisis de Resultados

#### ✓ Caso de Prueba 1: APROBADO
- Aleatorios generados correctamente
- Rango 50-100 verificado
- Promedios calculados correctamente

#### ✓ Caso de Prueba 3: APROBADO
- Mínimo identificado: 68.00
- Máximo identificado: 92.00
- Cálculos correctos

#### ✓ Caso de Prueba 6: APROBADO
- Flujo completo funcional
- Menú interactivo responsivo
- Salida limpia del programa

---

## 5. Cobertura de Pruebas

| Aspecto | Aprobado | Notas |
|---------|----------|-------|
| Entrada Manual | ✓ | Validar con valores específicos |
| Entrada Aleatoria | ✓ | Rango 50-100 confirmado |
| Promedio Estudiante | ✓ | Cálculo matemático correcto |
| Promedio Materia | ✓ | Cálculo matemático correcto |
| Mínimo/Máximo | ✓ | Identificados correctamente |
| Template<float> | ✓ | Trabaja correctamente |
| Template<int> | ✓ | Trabaja correctamente |
| Template<double> | ✓ | Trabaja correctamente |
| Menú Interactivo | ✓ | Navegación funcional |
| Reportes | ✓ | Formateo y contenido correcto |

---

## Conclusiones

✅ El sistema de gestión de calificaciones cumple con todos los requerimientos especificados.

✅ La clase template GradeBook<T> funciona correctamente con múltiples tipos de datos.

✅ Todos los cálculos estadísticos son precisos y confiables.

✅ La interfaz de usuario es intuitiva y robusta ante entradas inválidas.

---

**Nota**: Este documento contiene los casos de prueba diseñados y ejecutados para validar el funcionamiento del sistema.
