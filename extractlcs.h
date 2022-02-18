

#ifndef RICCARDOPIERINI105131_EXTRACTLCS_H
#define RICCARDOPIERINI105131_EXTRACTLCS_H

typedef struct Mat_struct {
    char** matrix;
    int* colums;
    int* rows;
} extractlcs_matrix;


void exctractlcs (char* file1, char* file2, char* file_output);

#endif //RICCARDOPIERINI105131_EXTRACTLCS_H
