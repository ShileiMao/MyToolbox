//
//  main.c
//  ShileiToolbox
//
//  Created by Shilei Mao on 15/10/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileOperator.h"
#include "StandardOut.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    FILE * file = openFile("/Users/shilei.mao/Downloads/2AFA6CE8E789053F1EFE75BF42B914CD831417E21767779D6130A99C76921343.txt", "r+");
    
    char *buffer[10];
    
    if (file != NULL) {
        long fileSize = getFileSize(file);
        long readLen = 0;
        if (fileSize == 0) {
            printf("Empty file!\n");
            return 0;
        }
        
        char * fileData = (char* ) malloc(fileSize);
        while (readLen < fileSize) {
            size_t tempLen = readBytes(buffer, 1, 10, file);
            if (tempLen > 0) {
                memcpy(fileData + readLen, buffer, tempLen);
                readLen += tempLen;
            } else {
                break;
            }
        }
        
        puts(fileData);
        free(fileData);
    }
    closeFile(file);
    return 0;
}
