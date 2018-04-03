/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * Apr 10, 2017
 * C2A1E1_Macros_h
 * Mac OS X
 * Xcode Version 8.3
 *
 * description:
 * This is a header file that contains three function-like macros: Product, Negate, and Elements.
 * 1. The value of Product is the product of two arithmetic type arguments that are passed to it.
 * 2. The value of Negate is the negated value of the one arithemtic type argument that is passed 
 *    to it.
 * 3. The value of Elements is the number of elements of the 1-dimensional array passed to it.
 */


#ifndef C2A1E1_MACROS_H
#define C2A1E1_MACROS_H

#define Product(num1, num2)((num1) * (num2))             /* Product is the product of num1 and num2 */
#define Negate(num)((-1) * (num))                        /* Negate is the negated value of num */
#define Elements(arr)((sizeof(arr)) / (sizeof(arr[0])))  /* Elements is the number of elements in arr*/

#endif
