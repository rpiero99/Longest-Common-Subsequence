//
// Created by Riccardo on 05/03/2022.
//

#include <malloc.h>
#include <memory.h>
#include <ctype.h>
#include "extractlcs.h"

void fill_matrix (const char* file1, const char* file2, extractlcs_matrix *matrix){
    int c = *matrix->columns;
    int r = *matrix->rows;

    //filling the first column and the first row with 0s.
    for(int i=0; i < r; i++){
        matrix->matrix[i][0] = 0;
    }
    for(int i=0; i < c; i++){
        matrix->matrix[0][i] = 0;
    }

    //filling the resting matrix
    for(int i=1; i < r; i++){
        for(int j=1; j < c; j++){
            if(file1[i-1] == file2[j-1]) {
                matrix->matrix[i][j] = matrix->matrix[i - 1][j - 1] + 1;
            } else if(matrix->matrix[i - 1][j] >= matrix->matrix[i][j - 1]){
                matrix->matrix[i][j] = matrix->matrix[i - 1][j];
            } else {
                matrix->matrix[i][j] = matrix->matrix[i][j - 1];
            }
        }
    }

}

void set_upper_case (char *string){
    for(int i = 0; i<strlen(string); i++)
        string[i] = toupper(string[i]);
}

char *result_exctractlcs (const char* file1, const char* file2, extractlcs_matrix* matrix, char* output){
    int rows = *matrix->rows -1;
    int columns = *matrix->columns -1;
    int index = matrix->matrix[rows][columns];
    output = (char* ) calloc(index+1,sizeof (char));

    output[index] = '\0';

    int i = rows, j = columns;
    while (i > 0 && j > 0) {
        if (file1[i - 1] == file2[j - 1]) {
            output[index - 1] = file1[i - 1];
            i--;
            j--;
            index--;
        }

        else if (matrix->matrix[i - 1][j] > matrix->matrix[i][j - 1])
            i--;
        else
            j--;
    }
    return output;
}
