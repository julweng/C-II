/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * Apr 17, 2017
 * C2A4E2_StorageMap5D.h
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description:
 * This file contains a macro StorageMap5D which is a storage map equation for a block of memory
 * represented by a 5-dimensional array. The function uses a pointer to the start of the index and, by
 * adding elements of the array, allows the user to access elements in the array.
 */

#ifndef C2A4E2_STORAGEMAP5D_H
#define C2A4E2_STORAGEMAP5D_H

#define StorageMap5D(ptr, idx0, idx1, idx2, idx3, idx4, dim1, dim2, dim3, dim4) (*((ptr) \
+ (idx0) * (dim1) * (dim2) * (dim3) * (dim4) + (idx1) * (dim2) * (dim3) * (dim4) \
+ (idx2) * (dim3) * (dim4) + (idx3) * (dim4) + (idx4)))

#endif 
