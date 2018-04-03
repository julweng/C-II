/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * May 14, 2017
 * C2A7E4_OpenTemporaryFile.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description:
 * This file contains the definition of the OpenTemporaryFile function.
 * The function tires to open a temporary file and outputs an error message
 * if errors occurs when opening the file.
 */

#include <stdio.h>
#include <stdlib.h>

FILE *OpenTemporaryFile(void)
{
    FILE *tmpFp;
    /* open a temporary file and test for open success */
    if ((tmpFp = tmpfile()) == NULL)
    {
        fprintf(stderr, "Can't open file.\n");
        exit(EXIT_FAILURE);
    }
    
    /* return a pointer to the open file if file opened successfully */
    return(tmpFp);
}
