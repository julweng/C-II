/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * May 1, 2017
 * C2A6E1_GetPointers.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description: This file contains definitions of the GetPrintfPointer and GetPutsPointer functions.
 * GetPrintfPointer returns a pointer to the standard library printf function. GetPutsPointer returns
 * a pointer to the standard library puts function.
 */

#include <stdio.h>
/* this function returns a pointer to the printf function */
int (*GetPrintfPointer(void))(const char *format, ...)
{
    int (*pPrintf)(const char *format, ...) = printf;
    return(pPrintf);
}

/* this function returns a pointer to the puts function */
int (*GetPutsPointer(void))(const char *str)
{
    int (*pPuts)(const char *str) = puts;
    return(pPuts);
}
