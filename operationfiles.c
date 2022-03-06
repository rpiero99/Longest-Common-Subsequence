//
// Created by Riccardo on 27/02/2022.
//

#include <stdlib.h>
#include <memory.h>
#include "operationfiles.h"

char *openFileInBinary(char *path){
    FILE *fileOpen;
    char *buffer = NULL;

    fileOpen = fopen(path, "rb");
    if (fileOpen==NULL)
        perror("File not found"), exit(1);
    long length = getFileLength(fileOpen);

    buffer = calloc(length+1, sizeof (char));
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
long getFileLength(FILE *fileOpen){
    fseek(fileOpen, 0L, SEEK_END);
    long length = ftell(fileOpen);
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