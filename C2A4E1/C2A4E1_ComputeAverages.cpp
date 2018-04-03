//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// Apr 24, 2017
// C2A4E1_ComputeAverages.cpp
// Mac OS X
// Xcode Version 8.3.1
//
// description: This file contains the definition of the ComputeAverages function.
// The function calculates the average of all elements in a 4-dimensional array
// using a nested for loop and a linear loop with pointer.
//

#include "C2A4E1_ArraySize.h"

void ComputeAverages(float array[DIM1][DIM2][DIM3][DIM4], float *nestedAvg, float *linearAvg)
{
    //nested for loop
    float nestedSum = 0;
    for (int firstDIM = 0; firstDIM < DIM1; ++firstDIM)
        for (int secondDIM = 0; secondDIM < DIM2; ++secondDIM)
            for (int thirdDIM = 0; thirdDIM < DIM3; ++thirdDIM)
                for (int fourthDIM = 0; fourthDIM < DIM4; ++fourthDIM)
                    //add elements to nestedSum
                    nestedSum += array[firstDIM][secondDIM][thirdDIM][fourthDIM];
    
    //calulate nestedAvg
    *nestedAvg = nestedSum / (DIM1 * DIM2 * DIM3 * DIM4);

    //linear loop using a pointer
    float linearSum = 0;
    for (float *Ptr = (float *)array; Ptr < (float *)array + DIM1 * DIM2 * DIM3 * DIM4; ++Ptr)
        //add elements to linearSum
        linearSum += *Ptr;
    
    //caclulate linearAvg
    *linearAvg = linearSum / (DIM1 * DIM2 * DIM3 * DIM4);
}
