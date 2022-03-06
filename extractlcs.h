

#ifndef RICCARDOPIERINI105131_EXTRACTLCS_H
#define RICCARDOPIERINI105131_EXTRACTLCS_H

typedef struct Mat_struct {
    int** matrix;
    int* colums;
    int* rows;
} extractlcs_matrix;


void fill_matrix (char* file1, char* file2, extractlcs_matrix* matrix);
char* result_exctractlcs (extractlcs_matrix* matrix, char* output);

#endif //RICCARDOPIERINI105131_EXTRACTLCS_H
