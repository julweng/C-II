//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// Apr 24, 2017
// C2A3E2_TestDeclarations.cpp
// Mac OS X
// Xcode Version 8.3.1
//
// description:
// This file contains a function TestDeclarations that takes no parameters and returns void.
// The code in the function explores typecasting and declarations of pointers and references.
//

const int ARRAYSIZE = 9;

void TestDeclarations()
{
    //sentence1: vp is a pointer to a void
    void *vp = 0;
    
    //sentence2: fcnA takes int val as a parameter and returns an int
    int fcnA(int val);
    
    //sentence3: ppa is a pointer to a pointer to an array of floats
    float (**ppa)[ARRAYSIZE];
    
    //sentence4: rppa references a pointer to a pointer to an array of floats and is intialized to ppa
    float (**&rppa)[ARRAYSIZE] = ppa;
    
    //sentence5: typecast vp to a pointer to a pointer to an array of floats and assign it to ppa
    ppa = (float (**)[ARRAYSIZE])(vp);
}
