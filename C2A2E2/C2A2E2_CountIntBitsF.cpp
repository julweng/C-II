//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// Apr 17, 2017
// C2A2E2_CountIntBitsF.cpp
// Mac OS X
// Xcode Version 8.3
//
// description:
// This file contains the defition of the function CountIntBitsF.
// It calculates the bits used to store an int data type and returns the number of bit as
// an int.
//


int CountIntBitsF()
{
    int countBits = 0;
    unsigned int anInt = 1;
    while (anInt)
    {
        anInt <<= 1;       /* shift anInt left by 1 position until it reaches becomes 0 */
        countBits++;       /* count bit */
    }
    return countBits;
}
