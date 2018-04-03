/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * May 1, 2017
 * C2A5E1_SwapObjects.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description: This file contains the definition of the function SwapObjects which swaps
 * two objects, each pointed to by a pointer.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SwapObjects(void *pa, void *pb, size_t size)
{
    /* temporary pointer variable for swapping */
    void *temp;
    
    /* test for dynamic memory allocation result  */
    if ((temp = malloc(size)) == NULL)
    {
        /* output error message and exit program if memory allocation fails */
        fputs("Error allocating memory.\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    /* copy object pointed to by pa to temp */
    memcpy(temp, pa, size);
    
    /* copy object pointed to by pb to pa */
    memcpy(pa, pb, size);
    
    /* copy object pointed to by temp (previously pointed to by pa) to pb--swapped */
    memcpy(pb, temp, size);
    
    /* free memory allocated for temp */
    free(temp);
}
