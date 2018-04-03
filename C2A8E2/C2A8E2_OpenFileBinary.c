/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * May 21, 2017
 * C2A8E2_OpenFileBinary.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description:
 * This file contains the definition of the OpenFileBinary function.
 * The function opens a file in the read-only binary mode, and outputs an error
 * message if the file fails to open.
 */


#include <stdio.h>
#include <stdlib.h>

FILE *OpenFileBinary(const char *fileName)
{
    FILE *inFp;
    
    /* test if file can be opened thru file pointer inFp */
    if ((inFp = fopen(fileName, "rb")) == NULL)
    {
        /* if fails to open file */
        fprintf(stderr, "Can't open\"%s\"n", fileName);
        
        /* outputs error message */
        exit(EXIT_FAILURE);
    }
    /* otherwise, return pointer to the open file */
    return(inFp);
}
