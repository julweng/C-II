/*
* Julia Tzu-Ya Weng, U07487022
* julweng@gmail.com
* C/C++ Programming II : Dynamic Memory and File I/O Concepts
* Section: 121616
* Instructor: Raymond Mitchell
* Apr 10, 2017
* C2A1E5_ResizeAlloc.c
* Mac OS X
* Xcode Version 8.3
*
* description:
* This file contains definition of the ResizeAlloc 
* function, that takes 3 parameters:
* 1. pOld, a pointer to void, that represents a block of memory
* 2. newSize, type size_t, that represents memory in bytes in a new block
* 3. oldSize, type isze_t, that represents memory in bytes in the pOld.
* The function ResizeAlloc dynamically allocates a new block of memory of the size of newSize. 
* Alternatively, the function can resize the memory in pOld from oldSize to newSize while 
* preserving data in pOld that will fit into newSize.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *ResizeAlloc(void *pOld, size_t newSize, size_t oldSize)
{
    /* if newSize is zero, return NULL */
    if (newSize == 0)
        return NULL;
    
    /* else allocate a new block; return NULL if allocation fails */
    void *pNew;
    if ((pNew = malloc(newSize)) == NULL)
        return NULL;
    
    /* else if pOld is NULL, return pNew */
    else if (pOld == NULL)
        return pNew;
    
    /* otherwise, do the following */
    else
        /* if newSize is greater than oldSize; copy oldSize from pOld to pNew */
        /* otherwise, copy newSize from pOld to pNew */
        (newSize > oldSize) ? (memcpy(pNew, pOld, oldSize)) : (memcpy(pNew, pOld, newSize));
    
    /* free pOld */
    free(pOld);
    return pNew;
}
