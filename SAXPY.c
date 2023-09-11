
//Examen 1. SAXPY

//Leyva Mercado Christian Alejandro
//Rivas Solis Carlos Eduardo
//Sánchez Pérez Marco Antonio

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // Tamaño de las matrices cuadradas. Variar entre 500, 1000, 5000, 10000

// Función para multiplicar dos matrices cuadradas A y B y almacenar el resultado en C
void multiplicarMatrices(int **A, int **B, int **C) {
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    //Declaración de las matrices y de las variables de tiempo
    int **A, **B, **C;
    clock_t inicio, fin;
    double tiempo;

    // Asigna memoria para las matrices
    A = (int **)malloc(N * sizeof(int *));
    B = (int **)malloc(N * sizeof(int *));
    C = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        A[i] = (int *)malloc(N * sizeof(int));
        B[i] = (int *)malloc(N * sizeof(int));
        C[i] = (int *)malloc(N * sizeof(int));
    }

    // Inicia el cronómetro
    inicio = clock();

    // Multiplica las matrices
    multiplicarMatrices(A, B, C);

    // Detiene el cronómetro
    fin = clock();

    // Calcula el tiempo transcurrido en segundos
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    // Imprime el resultado y el tiempo transcurrido
    printf("Multiplicación de %d terminada:\n", N);
    printf("Tiempo transcurrido: %f segundos\n", tiempo);

    // Libera la memoria asignada
    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    return 0;
}