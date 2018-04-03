//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// May 8, 2017
// C2A6E2_SortValues.cpp
// Mac OS X
// Xcode Version 8.3.1
//
// description:
// This file contains the defition of SortValues function, which takes a floating point array and
// implements the bubble sort algorithm to sort the elements in the array in descending order.
//

#include <cstddef>

float *SortValues(float *first, size_t elements)
{
    float *last = &first[elements - 1];
    
    //didSwap represents swapped or not
    bool didSwap;
    
    //loop through the array until no more swapping is required
    do
    {
        didSwap = false;
        for (float *current = first, *next = first + 1; current < last; ++current, ++next)
        {
            //if value of object pointed to by current is smaller than that pointed to by next
            if (*current < *next)
            {
                //temporarily assign the the value of object pointed to by current to temp
                float temp = *current;
                
                //swap the value of objected pointed to by next to the object pointed to by current
                *current = *next;
                
                //the object pointed to by next will get the value temporarily stored in temp
                *next = temp;
               
                //the values have been swapped
                didSwap = true;
            }
        }
        --last;
    } while (didSwap);
    
    return(first);
}
