/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * May 14, 2017
 * C2A7E4_ProcessStructures.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description:
 * File C2A7E4_ProcessStructures.c must contain functions named ReverseMembersEndian, ReadStructures 
 * and WriteStructures. The ReverseMembersEndian function reverse the endianness of all memebers of 
 * the structure Test. The ReadStrutures function read the number of structures from a file. The 
 * number is specified by count. The WriteStructures writes the read structures. 
 * Answer 1: the result for my implementation is correct
 * Answer 2: on my system, float is 4 byte, double is 8 byte, and pointer is 8 byte, so there are
 * 4 padding bytes between the float and the double. 
 */

#include <stdio.h>
#include <stdlib.h>
#include "C2A7E4_Test-Driver.h"

void *ReverseEndian(void *ptr, size_t size);

/* use the ReverseEndian function on members of Test */
struct Test *ReverseMembersEndian(struct Test *ptr)
{
    ReverseEndian((void *)&ptr->flt, sizeof(ptr->flt));
    ReverseEndian((void *)&ptr->dbl, sizeof(ptr->dbl));
    ReverseEndian((void *)&ptr->vp, sizeof(ptr->vp));
    return(ptr);
}

/* read structures */
struct Test *ReadStructures(struct Test *ptr, size_t count, FILE *fp)
{
    /* read file content pointed to by fp into object pointed to by ptr */
    size_t read = fread(ptr, sizeof(struct Test), count, fp);
    
    /* if not successfully read */
    if (read != count)
    {
        /* error message and exit program */
        fprintf(stderr, "failure to read the proper number of Test");
        exit(EXIT_FAILURE);
    }
    
    /* return ptr if count structures are read */
    return(ptr);
}

/* write structures */
struct Test *WriteStructures(const struct Test *ptr, size_t count, FILE *fp)
{
    /* write content of file pointed to by fp to object pointed to by ptr */
    if (fwrite(ptr, sizeof(struct Test), count, fp) != count)
    {
        /* if not successfully written, outputs error message and exit program */
        fprintf(stderr, "failure to write the proper number of Test");
        exit(EXIT_FAILURE);
    }
    /* return ptr if count structures are written */
    return((struct Test *)ptr);
}
