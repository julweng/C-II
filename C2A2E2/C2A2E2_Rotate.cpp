//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// Apr 17, 2017
// C2A2E2_Rotate.cpp
// Mac OS X
// Xcode Version 8.3
//
// description:
// This file contains the definition of Rotate function.
// Rotate uses BountIntBitsF() to calculate the number of bits used to store object.
// To prevent the most and least significant bits from being lost, the function will
// rotate the bit pattern so that these end bits are treated as if they are adjacent
// to each other.
//

int CountIntBitsF();

unsigned Rotate(unsigned object, int count)
{
    int numBits = CountIntBitsF();
    
    //left shit if count is negative or rotate the bit pattern at location count
    if (count < 0)
    {
        count = -count;
        return (object << count) | (object >> (numBits - count));
    }
    //right shift if count is positive or rotate the bit pattern at location count
    else
        return (object >> count) | (object << (numBits - count));
}
