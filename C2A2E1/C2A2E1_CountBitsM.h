/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * Apr 17, 2017
 * C2A2E1_CountBitsM.h
 * Mac OS X
 * Xcode Version 8.3
 *
 * description:
 * This header file contains the definition of the CountBitsM macro.
 * This function-like macro takes a parameter of any object data type and determines
 * the bits used to store that data type.
 *
 * answer to assignment question:
 * CountBitsM and CountIntBitsF could produce different results because CountBitsM includes
 * bits that are unused padding in its calculation, while CountIntBitsF doesn't take into
 * account of padding.
 */

#ifndef C2A2E1_COUNTBITSM_H
#define C2A2E1_COUNTBITSM_H

#include <limits.h>

#define CountBitsM(objectOrType) ((int)(sizeof(objectOrType)*CHAR_BIT))

#endif
