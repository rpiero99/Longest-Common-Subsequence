//
// Created by Riccardo on 18/02/2022.
//

#include "matrix.h"

int **allocate_matrix(int **matrix, int rows, int cols) {
    rows = rows+1;
    cols = cols+1;

    matrix = (int **) calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) calloc(cols, sizeof(int));
    }
    return matrix;
}

void free_matrix(int **matrix, int cols) {
    cols = cols+1;

    if (matrix != NULL) {
        for (int i = 0; i < cols; ++i) {
            free(matrix[i]);
            matrix[i] = NULL;
        }
        free(matrix);
        matrix = NULL;
    }
}