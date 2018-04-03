//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// Apr 24, 2017
// C2A4E1_RandomizeArray.cpp
// Mac OS X
// Xcode Version 8.3.1
//
// description: This file contains the definition of the RandomizeArray function.
// The function loops through a 4-dimensional array and assigns random values to
// each element of the array.
//

#include <cstdlib>
#include <ctime>
#include "C2A4E1_ArraySize.h"

void RandomizeArray(float array[DIM1][DIM2][DIM3][DIM4])
{
    //seed random number generator with time of day
    srand((unsigned int)time(NULL));
    
    //use a pointer to iterate through array
    for (float *Ptr = (float *)array; Ptr < (float *)array + DIM1 * DIM2 * DIM3 * DIM4; ++Ptr)
        //assign random float to each element
        *Ptr = (float)rand();
}

//for(int * iter = &arr[0][0]; iter != &arr[0][0] + col * row; iter++)
