/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * Apr 10, 2017
 * C2A1E3_FindFirstInt.c
 * Mac OS X
 * Xcode Version 8.3
 *
 * description:
 * This file contains definition of the FindFirstInt function.
 * The function takes 3 parameters:
 * 1. "ptr" is a pointer to a constant int and represents an array
 * 2. "count" is of the type size_t and indicates the number of elements in an array
 * 3. "value" is an int that the function attempts to find in a given array.
 * When FindFirstInt finds the first occurrence of "value" in an array, it will return a pointer
 * to that element. If nothing in the array matches "value", a null pointer will be returned.
*/

#include <stdio.h>
#include <stdlib.h>

int *FindFirstInt(const int *ptr, size_t count, int value)
{
    for (size_t i=0; i<count; ++i)      /* loop through elements in array */
    {
        if (ptr[i] == value)            /* search for the first occurrence of value */
            return (int *)(&ptr[i]);    /* return pointer to that element if found */
    }
    return (NULL);                      /* otherwise, return NULL */
}
