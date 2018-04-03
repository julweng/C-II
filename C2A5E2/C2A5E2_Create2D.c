/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * May 1, 2017
 * C2A5E2_Create2D.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description: 
 * This file contains the definitions of the functions Create2D and Free2D.
 * Function Create2D creates a 2D array by dynamically allocating a continous memory block.
 * Function Free2D frees the space allocated for the 2D array.
 */

#include <stdio.h>
#include <stdlib.h>
#include "C2A5E2_Type-Driver.h"

Type **Create2D(size_t rows, size_t cols)
{
    /* allocate a block of memory for the whole 2D array through p */
    Type **p;
    
    if ((p = (Type **)malloc((rows * sizeof(Type *)) + (rows * cols * sizeof(Type)))) == NULL)
    {
        fputs("Memory allocation failure\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    /* store p in pTemp1 */
    Type **pTemp1 = p;
    
    /* go to first element of the first column and store the address in pTemp */
    Type *pTemp2 = (Type *)(pTemp1 + rows);
    
    /* iterate through rows using p */
    for (Type **end = pTemp1 + rows; pTemp1 < end; ++pTemp1)
    {
        /* store address of the first column element in the corresponding row element */
        *pTemp1 = pTemp2;
        
        /* make pTemp point to the first element of the next column */
        pTemp2 = (Type *)(pTemp2 + cols);
    }
    /* return pointer to the first pointer of the 2D array */
    return(p);
}
     
void Free2D(void *p)
{
    free(p);
}
