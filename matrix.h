//
// Created by Riccardo on 18/02/2022.
//

#ifndef RICCARDOPIERINI105131_MATRIX_H
#define RICCARDOPIERINI105131_MATRIX_H
#include <stdlib.h>
#include <stdint.h>

int **allocate_matrix(int **matrix, int rows, int columns);
void free_matrix(int **matrix, int columns);


#endif //RICCARDOPIERINI105131_MATRIX_H
