#include <stdio.h>
#include "operationfiles.h"
int main() {
    char *result = openFileInBinary("C:\\Users\\Riccardo\\Desktop\\proba.txt");
    char *result2 = openFileInBinary("C:\\Users\\Riccardo\\Desktop\\proba2.txt");
    printf(result);
    printf(result2);
    writeFileInBinary("C:\\Users\\Riccardo\\Desktop\\result.txt", "provvvvv ennnammooooo");
    return 0;
}
