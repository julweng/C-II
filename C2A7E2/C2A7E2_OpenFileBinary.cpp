//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// May 1, 2017
// C2A7E2_OpenFileBinary.cpp
// Mac OS X
// Xcode Version 8.3.1
//
// description:
// This file contains the definition for the function OpenFile, which opens a file
// named in fileName in read only binary mode using inFile, outputs an error message
// and exit the program if there is error opening the file.
//

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void OpenFileBinary(const char *fileName, ifstream &inFile)
{
    //open fileName through inFile
    inFile.open(fileName, ios_base::in | ios_base::binary);
    
    //if error opening file
    if (!inFile.is_open())
    {
        //output error message
        cerr << "Error opening " << fileName << "\n";
    
        //exit program
        exit(EXIT_FAILURE);
    }
}
