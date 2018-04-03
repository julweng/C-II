/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * Apr 10, 2017
 * C2A1E2_main.c
 * Mac OS X
 * Xcode Version 8.3
 *
 * description:
 * This program prints the the number of command line arguments, followed by each argument
 * on separate lines.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf ("%d\n", argc);            /* prints the number of arguments */
    for (int i=0; i<argc; ++i)        /* prints each argument */
    {
        printf ("%s\n", argv[i]);
    }
    return 0;
}
