//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// May 1, 2017
// C2A5E4_OpenFile.cpp
// Mac OS X
// Xcode Version 8.3.1
//
// description:
// This file contains the definition for the function OpenFile, which opens a text file
// named in fileName for read only using inFile, outputs an error message and exit the
// program if there is error opening the file.
//

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void OpenFile(const char *fileName, ifstream &inFile)
{
    inFile.open(fileName);
    
    //try to open file
    if (!inFile.is_open())
    {
        cerr << "Error opening file " << fileName << '\n';
        exit(EXIT_FAILURE);
    }
}
