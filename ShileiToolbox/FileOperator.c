//
//  FileOperator.c
//  ShileiToolbox
//
//  Created by Shilei Mao on 15/10/2020.
//

#include "FileOperator.h"
#include <errno.h>

extern int errno;

FILE * openFile(char * path, char * mode)
{
    FILE *file = fopen(path, mode);
    int errorNum;
    
    if (file == NULL) {
        errorNum = errno;
        
        return NULL;
    } else {
        return file;
    }
}

int closeFile(FILE * file) {
    if (file == NULL) {
        return 0;
    }
    return fclose(file);
}

//FIXME: test this function
long getFileSize(FILE * file) {
    long curPos = ftell(file);
    fseek(file, curPos, SEEK_END); // seek to end of file
    long size = ftell(file); // get current file pointer
    fseek(file, curPos, SEEK_SET); // seek back to begining of file
    return size;
}

size_t readBytes(FILE * file, void *buffer, int itemLen, int len) {
    size_t resp;
    resp = fread(buffer, itemLen, len, file);
    return resp;
}



