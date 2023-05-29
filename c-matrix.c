#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<time.h>

int* initializeMatrix(int x, int y) {
    int* matrix = malloc(sizeof(int) * x * y);
    if (matrix == NULL) {
        return NULL;
    }

    return matrix;
}

void printMatrix (int rows, int cols, int* matrix) {
    for (int i = 0; i < rows; i++) {
        printf("[ ");
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[(i * cols) + j]);
        }

        printf("]\n");
    }
}

void populateMatrix(int rows, int cols, int* matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[(i * cols) + j] = i + (2 * i * j);
        }
    }
}

int main() {
    int rows = 5000;
    int cols = 5000;

    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    int* matrix = initializeMatrix(rows, cols);
    if (matrix == NULL) {
        return 1;
    }
    
    populateMatrix(rows, cols, matrix);
    printMatrix(rows, cols, matrix);

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Printing time: %f seconds\n", time_taken);
    return 0;
}
