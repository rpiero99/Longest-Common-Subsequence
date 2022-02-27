//
// Created by Riccardo on 27/02/2022.
//

#include <stdlib.h>
#include <memory.h>
#include "operationfiles.h"

char *openFileInBinary(char *path){
    FILE *fileOpen;
    char *buffer;

    fileOpen = fopen(path, "rb");
    int length = getFileLength(fileOpen);

    buffer = (char *) malloc(sizeof(char) * (length + 1));
    if (!buffer) {
        fclose(fileOpen);
        fputs("Memory allocation failed", stderr);
        exit(1);
    }
    readFileInBinary(buffer, sizeof (char), length, fileOpen);

    fclose(fileOpen);
    return buffer;
}
char *readFileInBinary(char *buffer, size_t dim, size_t length,  FILE *fileOpen){
    size_t read_size = fread(buffer, dim, length, fileOpen);
    if (length != read_size) {
        free(buffer);
        fclose(fileOpen);
        buffer = NULL;
        return NULL;
    }
}
int getFileLength(FILE *fileOpen){
    fseek(fileOpen, 0L, SEEK_END);
    int length = ftell(fileOpen);
    rewind(fileOpen);

    return length;
}

void writeFileInBinary(char *path, char* output){
    FILE *fileOpen = fopen(path, "wb");
    if(fileOpen == NULL){
        fputs("File not found", stdin);
        exit(1);
    }
    fwrite(output, sizeof (char), strlen(output), fileOpen );
}