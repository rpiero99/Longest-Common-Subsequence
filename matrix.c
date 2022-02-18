//
// Created by Riccardo on 18/02/2022.
//

#include "matrix.h"

char **allocate_matrix(char **matrix, int rows, int cols) {

    matrix = (char **) calloc(rows, sizeof(char *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char *) calloc(cols, sizeof(char));
    }
    return matrix;
}

void free_matrix(char **matrix, int columns) {
    if (matrix != NULL) {
        for (int i = 0; i < columns; ++i) {
            free(matrix[i]);
            matrix[i] = NULL;
        }
        free(matrix);
        matrix = NULL;
    }
}