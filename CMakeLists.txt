cmake_minimum_required(VERSION 3.10)
project(GradeBook VERSION 1.0 LANGUAGES CXX)

# Configurar estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Ruta de includes
include_directories(src)

# Crear ejecutable
add_executable(gradebook
    src/main.cpp
)

# Mensaje de compilación exitosa
message(STATUS "Proyecto GradeBook configurado exitosamente")
message(STATUS "Ejecutable: gradebook")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
