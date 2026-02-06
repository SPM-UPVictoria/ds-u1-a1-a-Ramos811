#include <iostream>
#include "gradebook.hpp"

int main() {
    // Mostrar encabezado del programa
    std::cout << "╔════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   SISTEMA DE GESTIÓN DE CALIFICACIONES                ║" << std::endl;
    std::cout << "║   Estructura de Datos - Actividad Práctica 1          ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════╝" << std::endl;
    
    // Crear objeto de tipo GradeBook con calificaciones en punto flotante
    GradeBook<float> gradeBook;
    
    int choice;
    bool exit_program = false;
    
    // Bucle principal del menú
    while (!exit_program) {
        std::cout << "\n╔════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║              MENÚ DE OPCIONES                          ║" << std::endl;
        std::cout << "║  1. Ingresar calificaciones manualmente                ║" << std::endl;
        std::cout << "║  2. Generar calificaciones aleatoriamente             ║" << std::endl;
        std::cout << "║  3. Mostrar reporte completo                          ║" << std::endl;
        std::cout << "║  4. Salir                                             ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════╝" << std::endl;
        std::cout << "Seleccione una opción: ";
        
        std::cin >> choice;
        
        // Procesar la opción seleccionada
        switch (choice) {
            case 1:
                // Opción para ingreso manual de calificaciones
                gradeBook.inputGradesManual();
                std::cout << "\n✓ Calificaciones ingresadas correctamente." << std::endl;
                break;
                
            case 2:
                // Opción para generar calificaciones aleatorias
                gradeBook.inputGradesRandom();
                std::cout << "\n✓ Calificaciones generadas aleatoriamente." << std::endl;
                break;
                
            case 3:
                // Opción para mostrar el reporte completo
                gradeBook.displayReport();
                break;
                
            case 4:
                // Opción para salir del programa
                std::cout << "\n¡Gracias por usar el Sistema de Gestión de Calificaciones!" << std::endl;
                exit_program = true;
                break;
                
            default:
                // Manejo de opción inválida
                std::cout << "\n✗ Opción inválida. Intente nuevamente." << std::endl;
        }
    }
    
    return 0;
}
