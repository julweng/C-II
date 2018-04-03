/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * Apr 24, 2017
 * C2A3E4_OpenFile.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description:
 * This file contains definition of the function OpenFile, that opens a text file in the
 * read-only mode, and outputs an error message and exit the program if there is an error
 * opening the file.
 */

#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(const char *fileName)
{
    FILE *inFp;
    /* open file for read only */
    if ((inFp = fopen(fileName, "r")) == NULL)
    {
        /* if file fails to open, print error message and exit program */
        fprintf(stderr, "error opening file\n");
        exit(EXIT_FAILURE);
    }
    /* otherwise return pointer to the open file */
    return(inFp);
}
