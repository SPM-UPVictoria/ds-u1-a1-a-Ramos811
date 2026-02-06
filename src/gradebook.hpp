#ifndef GRADEBOOK_HPP
#define GRADEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Dimensiones del arreglo de calificaciones
const int NUM_STUDENTS = 5;
const int NUM_SUBJECTS = 4;

// Plantilla genérica para gestionar matriz de calificaciones
// Soporta tipos: int, float, double
template <typename T>
class GradeBook {
private:
    T grades[NUM_STUDENTS][NUM_SUBJECTS];      // Matriz de calificaciones
    std::string studentNames[NUM_STUDENTS];    // Nombres de estudiantes
    std::string subjectNames[NUM_SUBJECTS];    // Nombres de materias
    
public:
    GradeBook() {
        initializeNames();
    }
    
    // Asigna nombres a estudiantes y materias
    void initializeNames() {
        studentNames[0] = "Alumno 1";
        studentNames[1] = "Alumno 2";
        studentNames[2] = "Alumno 3";
        studentNames[3] = "Alumno 4";
        studentNames[4] = "Alumno 5";
        
        subjectNames[0] = "Matemáticas";
        subjectNames[1] = "Español";
        subjectNames[2] = "Inglés";
        subjectNames[3] = "Ciencias";
    }
    
    // Lee calificaciones desde entrada estándar (teclado)
    // Solicita una calificación por cada estudiante y materia
    void inputGradesManual() {
        std::cout << "\n=== INGRESO MANUAL DE CALIFICACIONES ===" << std::endl;
        for (int i = 0; i < NUM_STUDENTS; i++) {
            std::cout << "\nIngrese calificaciones para " << studentNames[i] << ":" << std::endl;
            for (int j = 0; j < NUM_SUBJECTS; j++) {
                std::cout << "  " << subjectNames[j] << ": ";
                std::cin >> grades[i][j];
            }
        }
    }
    
    // Genera calificaciones aleatorias entre 50 y 100
    // Inicializa la semilla con la hora actual para variabilidad
    void inputGradesRandom() {
        srand(static_cast<unsigned>(time(0)));
        std::cout << "\n=== CALIFICACIONES GENERADAS ALEATORIAMENTE ===" << std::endl;
        for (int i = 0; i < NUM_STUDENTS; i++) {
            for (int j = 0; j < NUM_SUBJECTS; j++) {
                grades[i][j] = static_cast<T>(50 + (rand() % 51));
            }
        }
    }
    
    // Calcula el promedio de calificaciones de un estudiante específico
    T getStudentAverage(int studentIndex) const {
        if (studentIndex < 0 || studentIndex >= NUM_STUDENTS) return 0;
        
        T sum = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            sum += grades[studentIndex][j];
        }
        return sum / NUM_SUBJECTS;
    }
    
    // Calcula el promedio de calificaciones de una materia en todos los estudiantes
    T getSubjectAverage(int subjectIndex) const {
        if (subjectIndex < 0 || subjectIndex >= NUM_SUBJECTS) return 0;
        
        T sum = 0;
        for (int i = 0; i < NUM_STUDENTS; i++) {
            sum += grades[i][subjectIndex];
        }
        return sum / NUM_STUDENTS;
    }
    
    // Busca la calificación más baja en toda la matriz
    T getMinGrade() const {
        T minGrade = grades[0][0];
        for (int i = 0; i < NUM_STUDENTS; i++) {
            for (int j = 0; j < NUM_SUBJECTS; j++) {
                if (grades[i][j] < minGrade) {
                    minGrade = grades[i][j];
                }
            }
        }
        return minGrade;
    }
    
    // Busca la calificación más alta en toda la matriz
    T getMaxGrade() const {
        T maxGrade = grades[0][0];
        for (int i = 0; i < NUM_STUDENTS; i++) {
            for (int j = 0; j < NUM_SUBJECTS; j++) {
                if (grades[i][j] > maxGrade) {
                    maxGrade = grades[i][j];
                }
            }
        }
        return maxGrade;
    }
    
    // Imprime la matriz de calificaciones en formato tabla
    void displayGradeTable() const {
        std::cout << "\n=== TABLA DE CALIFICACIONES ===" << std::endl;
        std::cout << std::left << std::setw(15) << "Estudiante";
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            std::cout << std::setw(15) << subjectNames[j];
        }
        std::cout << std::endl;
        std::cout << std::string(15 + (NUM_SUBJECTS * 15), '-') << std::endl;
        
        for (int i = 0; i < NUM_STUDENTS; i++) {
            std::cout << std::left << std::setw(15) << studentNames[i];
            for (int j = 0; j < NUM_SUBJECTS; j++) {
                std::cout << std::setw(15) << std::fixed << std::setprecision(2) << grades[i][j];
            }
            std::cout << std::endl;
        }
    }
    
    // Genera un reporte completo con toda la información estadística
    // Incluye: tabla de calificaciones, promedios por estudiante,
    // promedios por materia, y calificaciones mínima y máxima
    void displayReport() const {
        std::cout << "\n" << std::string(50, '=') << std::endl;
        std::cout << "         REPORTE DE CALIFICACIONES DEL GRUPO" << std::endl;
        std::cout << std::string(50, '=') << std::endl;
        
        displayGradeTable();
        
        std::cout << "\n=== PROMEDIO POR ESTUDIANTE ===" << std::endl;
        for (int i = 0; i < NUM_STUDENTS; i++) {
            std::cout << std::left << std::setw(15) << studentNames[i] << ": " 
                      << std::fixed << std::setprecision(2) << getStudentAverage(i) << std::endl;
        }
        
        std::cout << "\n=== PROMEDIO POR MATERIA ===" << std::endl;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            std::cout << std::left << std::setw(15) << subjectNames[j] << ": " 
                      << std::fixed << std::setprecision(2) << getSubjectAverage(j) << std::endl;
        }
        
        std::cout << "\n=== ESTADÍSTICAS GENERALES ===" << std::endl;
        std::cout << "Calificación mínima general: " << std::fixed << std::setprecision(2) << getMinGrade() << std::endl;
        std::cout << "Calificación máxima general: " << std::fixed << std::setprecision(2) << getMaxGrade() << std::endl;
        std::cout << std::string(50, '=') << std::endl;
    }
};

#endif // GRADEBOOK_HPP
