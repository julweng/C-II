/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * May 7, 2017
 * C2A6E4_OpenFile.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description:
 * This file contains the defition of the OpenFile function which opens a file in the read-only
 * text mode, and outputs an error message if the file fails to open.
 */

#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(const char *fileName)
{
    FILE *fp;
    
    /* attempts to open file through fp */
    if ((fp = fopen(fileName, "r")) == NULL)
    {
        /* if file fails to open, outputs error message */
        fprintf(stderr, "Can't open \"%s\".\n", fileName);
        exit(EXIT_FAILURE);
    }
    
    /* otherwise, return the pointer to the open file */
    return(fp);
}
