

#ifndef RICCARDOPIERINI105131_EXTRACTLCS_H
#define RICCARDOPIERINI105131_EXTRACTLCS_H

typedef struct Mat_struct {
    int** matrix;
    int* columns;
    int* rows;
} extractlcs_matrix;


void fill_matrix (const char* file1, const char* file2, extractlcs_matrix* matrix);
char *result_exctractlcs (const char* file1, const char* file2, extractlcs_matrix* matrix, char* output);

#endif //RICCARDOPIERINI105131_EXTRACTLCS_H
