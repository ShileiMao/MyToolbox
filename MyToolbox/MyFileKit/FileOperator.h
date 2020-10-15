//
//  FileOperator.h
//  ShileiToolbox
//
//  Created by Shilei Mao on 15/10/2020.
//

#ifndef FileOperator_h
#define FileOperator_h

#include <stdio.h>


/**
 
 open filename with the given mode
 
 values available for mode:
 "r"

 Opens a file for reading. The file must exist.

 2
 "w"

 Creates an empty file for writing. If a file with the same name already exists, its content is erased and the file is considered as a new empty file.

 3
 "a"

 Appends to a file. Writing operations, append data at the end of the file. The file is created if it does not exist.

 4
 "r+"

 Opens a file to update both reading and writing. The file must exist.

 5
 "w+"

 Creates an empty file for both reading and writing.

 6
 "a+"

 Opens a file for reading and appending.
 */
FILE * openFile(char * path, char * mode);


/**
 close file
 */
int closeFile(FILE * file);


long getFileSize(FILE * file);

size_t readBytes(void *buffer, int itemLen, int len, FILE * file);


size_t writeBytes(void * buffer, size_t itemLen, size_t nItems, FILE * file);


#endif /* FileOperator_h */
