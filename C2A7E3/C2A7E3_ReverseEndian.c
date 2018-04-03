/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * May 14, 2017
 * C2A7E3_ReverseEndian.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description:
 * This file contains the definition of the ReverseEndian function. 
 * The function reverses the endianness of a scalar object.
 */

#include <stdio.h>
#include <stdlib.h>

void *ReverseEndian(void *ptr, size_t size)
{
    /* pointer to first byte */
    char *first = (char *)ptr;
    
    /* pointer to last byte */
    char *last = first + size - 1;
    
    /* swapping bytes */
    for (; last > first; --last, ++first)
    {
        char temp = *first;
        *first = *last;
        *last = temp;
    }
    return ptr;
}
