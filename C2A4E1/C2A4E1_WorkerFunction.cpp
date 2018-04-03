//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// Apr 24, 2017
// C2A4E1_WorkerFunction.cpp
// Mac OS X
// Xcode Version 8.3.1
//
// description: This file contains the definition of the WorkerFunction which uses the
// RandomizeArray and ComputeAverages functions.
//

#include "C2A4E1_ArraySize.h"

void RandomizeArray(float array[DIM1][DIM2][DIM3][DIM4]);

void ComputeAverages(float array[DIM1][DIM2][DIM3][DIM4], float *nestedAvg, float *linearAvg);

void WorkerFunction(float *nestedAvg, float *linearAvg)
{
    float testArray[DIM1][DIM2][DIM3][DIM4];
    RandomizeArray(testArray);
    ComputeAverages(testArray, nestedAvg, linearAvg);
}
