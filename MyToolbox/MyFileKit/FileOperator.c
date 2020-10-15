//
//  FileOperator.c
//  ShileiToolbox
//
//  Created by Shilei Mao on 15/10/2020.
//

#include "FileOperator.h"
#include <errno.h>
#include "StandardOut.h"
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

long getFileSize(FILE * file) {
    // the second param (0) is the offset compare with current position
    fseek(file, 0, SEEK_END); // seek to end of file
    long size = ftell(file); // get current file pointer
    fseek(file, 0, SEEK_SET); // seek back to begining of file
    return size;
}


size_t readBytes(void * buffer, int itemLen, int len, FILE * file) {
    size_t resp;
    resp = fread(buffer, itemLen, len, file);
    return resp;
}

size_t writeBytes(void * buffer, size_t itemLen, size_t nItems, FILE * file) {
    size_t resp;
    resp = fwrite(buffer, itemLen, nItems, file);
    return resp;
}
