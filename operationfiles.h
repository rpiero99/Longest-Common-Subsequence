//
// Created by Riccardo on 27/02/2022.
//

#ifndef RICCARDOPIERINI105131_OPERATIONFILES_H
#define RICCARDOPIERINI105131_OPERATIONFILES_H

#include <stdio.h>

char *openFile(char *path);
int fileLength(FILE *fileOpen);
void writeFile(char *path, char* output);

#endif //RICCARDOPIERINI105131_OPERATIONFILES_H