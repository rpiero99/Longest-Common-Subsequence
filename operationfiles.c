//
// Created by Riccardo on 27/02/2022.
//

#include <stdlib.h>
#include <memory.h>
#include "operationfiles.h"

char *openFile(char *path){
    FILE *fileOpen;
    char *buffer;

    fileOpen = fopen(path, "rb");
    int length = fileLength(fileOpen);

    buffer = (char *) malloc(sizeof(char) * (length + 1));
    if (!buffer) {
        fclose(fileOpen);
        fputs("memory allocation fails", stderr);
        exit(1);
    }
    size_t read_size = fread(buffer, sizeof(char), length, fileOpen);
    if (length != read_size) {
        free(buffer);
        fclose(fileOpen);
        buffer = NULL;
        return NULL;
    }

    fclose(fileOpen);
    return buffer;
}

int fileLength(FILE *fileOpen){
    fseek(fileOpen, 0L, SEEK_END);
    int length = ftell(fileOpen);
    rewind(fileOpen);

    return length;
}