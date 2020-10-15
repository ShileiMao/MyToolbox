//
//  FileOperator.h
//  ShileiToolbox
//
//  Created by Shilei Mao on 15/10/2020.
//

#ifndef FileOperator_h
#define FileOperator_h

#include <stdio.h>
FILE * openFile(char * path, char * mode);
int closeFile(FILE * file);
long getFileSize(FILE * file);
size_t readBytes(FILE * file, void *buffer, int itemLen, int len);
#endif /* FileOperator_h */
