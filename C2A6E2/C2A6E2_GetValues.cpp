//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// May 8, 2017
// C2A6E2_GetValues.cpp
// Mac OS X
// Xcode Version 8.3.1
//
// description:
// This file contains the definition of the GetValues function, which asks user to enter floating
// point values, reads in user input one at a time, stores it in an array, and return pointer
// to the first element of the array.
//

#include <iostream>

using namespace std;

float *GetValues(float *first, size_t elements)
{
    //prompt for floating point values
    cout << "Enter " << elements << " floating point values:\n";
    
    //Use a loop to read in input one at a time through the use of pointer first
    //set a limit to the loop by declaring last to point to end of the array
    for (float *last = first + elements; first < last; ++first)
        cin >> *first;
    
    //return pointer to the first element
    return(first - elements);
}
