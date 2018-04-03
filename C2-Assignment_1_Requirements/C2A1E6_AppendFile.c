/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * Apr 10, 2017
 * C2A1E6_AppendFile.c
 * Mac OS X
 * Xcode Version 8.3
 *
 * description:
 * This file contains definition of the AppendFile function, that takes 2 parameters,
 * inFile and outFile, which are of pointer to const char type. AppendFile will read 
 * the content of the file whose name is pointed to by inFile and append to the content
 * of the file whose name is pointed to by outFile.
 */

#include <stdio.h>
#include <stdlib.h>

#define FAILURE (-1)                                               /* value of failure code */


int AppendFile(const char *inFile, const char *outFile)
{
    FILE *source;
    FILE *dest;
    
    source = fopen(inFile, "rb");                                  /* open source for read */
    dest = fopen(outFile, "ab");                                   /* open dest for append */
    
    if ((source == NULL) || (dest == NULL))                        /* if open error */
    {
        fprintf(stderr, "Error opening file.\n");                  /* error message */
        exit(FAILURE);                                             /* terminate program */
    }
    else
    {
        int check;
        while((check = fgetc(source)) != EOF)                      /* otherwise, read source till EOF */
            putc(check, dest);                                     /* append to dest */
    }
        
    fclose(source);                                                /* close source */
    fclose(dest);                                                  /* close dest */
    return(EXIT_SUCCESS);
}
