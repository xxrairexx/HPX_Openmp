// Hello World en OpenMP (equivalente al ejemplo de GeeksforGeeks)
// Compilar: g++ -std=c++17 -fopenmp hello_openmp.cpp -o hello_openmp
// Ejecutar: ./hello_openmp
#include <iostream>
#include <omp.h>
#include <cstdio>

int main() {
    #pragma omp parallel
    {
        // printf evita que las lineas se mezclen tanto como std::cout
        std::printf("Hello World... from thread = %d\n", omp_get_thread_num());
    }
    return 0;
}