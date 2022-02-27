//
// Created by Riccardo on 27/02/2022.
//

#ifndef RICCARDOPIERINI105131_OPERATIONFILES_H
#define RICCARDOPIERINI105131_OPERATIONFILES_H

#include <stdio.h>

char *openFileInBinary(char *path);
char *readFileInBinary(char *buffer, size_t dim, size_t length,  FILE *fileOpen);
int getFileLength(FILE *fileOpen);
void writeFileInBinary(char *path, char* output);

#endif //RICCARDOPIERINI105131_OPERATIONFILES_H
