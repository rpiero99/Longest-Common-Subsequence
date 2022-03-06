//
// Created by Riccardo on 05/03/2022.
//

#include "extractlcs.h"

void fill_matrix (char* file1, char* file2, extractlcs_matrix *matrix){
    int rows = *matrix->rows;
    int columns = *matrix->colums;

    //filling the first column and the first row with 0s.
    for(int i=0; i<= rows; i++){
        matrix->matrix[i][0] = 0;
    }
    for(int i=0; i<=columns; i++){
        matrix->matrix[0][i] = 0;
    }

    //filling the resting matrix
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            if(file1[i-1] == file2[j-1]) {
                matrix->matrix[i][j] = matrix->matrix[i - 1][j - 1] + 1;
            } else if(matrix->matrix[i - 1][j] >= matrix->matrix[i][j - 1]){
                matrix->matrix[i][j] = matrix->matrix[i - 1][j];
            } else {
                matrix->matrix[i][j] = matrix->matrix[i][j - 1];
            }
        }
    }

    char* result_exctractlcs (extractlcs_matrix* matrix, char* output){

    }

}
