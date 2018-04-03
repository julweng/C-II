/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * Apr 17, 2017
 * C2A2E1_CountIntBitsF.c
 * Mac OS X
 * Xcode Version 8.3
 *
 * description:
 * This file contains the defition of the function CountIntBitsF.
 * It calculates the bits used to store an int data type and returns the number of bit as
 * an int.
 */


int CountIntBitsF(void)
{
    int countBits = 0;
    /* shift anInt left by 1 position until it reaches 0 and count countBits */
    for (unsigned int anInt = 1; anInt != 0; countBits++)
    {
        anInt <<= 1;
    }
    return countBits;
}
