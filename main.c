#include <stdio.h>
#include <memory.h>
#include "operationfiles.h"
#include "extractlcs.h"
#include "matrix.h"

static void number_of_arguments_incorrect() {
    printf("Incorrect number of arguments! You have to insert only 3 files (2 for input and one of output)");
    exit(EXIT_FAILURE);
}

void exctractlcs(char **argv) {
    char *result2 = openFileInBinary(argv[0]);
    char *result = openFileInBinary(argv[1]);

    int **a = NULL;
    int lengthFirst = strlen(result);
    int lengthSecond = strlen(result2);
    a = allocate_matrix(a, lengthFirst,lengthSecond);
    extractlcs_matrix matrix = create_extractlcs_matrix(a, &lengthFirst,&lengthSecond);
    fill_matrix(result, result2, &matrix);
    char *output = NULL;
    output = result_exctractlcs(result, result2, &matrix, output);

    writeFileInBinary(argv[2], output);
    free_matrix(a, strlen(result2));
    free(result);
    free(result2);
}
int main(int argc, char **argv) {

    if(argc==3){
        exctractlcs(argv);
    }
    else
        number_of_arguments_incorrect();
    return 0;
}




