#include <stdio.h>
#include <memory.h>
#include "operationfiles.h"
#include "extractlcs.h"
#include "matrix.h"
int main() {

    char *result2 = openFileInBinary("C:\\Users\\Riccardo\\Desktop\\proba.txt");
    char *result = openFileInBinary("C:\\Users\\Riccardo\\Desktop\\proba2.txt");

    int **a = NULL;
    int lengthFirst = strlen(result);
    int lengthSecond = strlen(result2);
    a = allocate_matrix(a, lengthFirst,lengthSecond);
    extractlcs_matrix matrix = create_extractlcs_matrix(a, &lengthFirst,&lengthSecond);
    fill_matrix(result, result2, &matrix);
    char *output = NULL;
    output = result_exctractlcs(result, result2, &matrix, output);

    writeFileInBinary("C:\\Users\\Riccardo\\Desktop\\result.txt", output);
    free_matrix(a, strlen(result2));
    free(result);
    free(result2);
    return 0;
}
