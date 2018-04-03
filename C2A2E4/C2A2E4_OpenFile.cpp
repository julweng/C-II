//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// Apr 17, 2017
// C2A2E4_OpenFile.cpp
// Mac OS X
// Xcode Version 8.3
//
// description:
// This file contains the definition of the OpenFile function.
// The function takes two parameters: fileName that points to the name of the file
// to be opened, and inFile that references the ifstream object used to open the file.
// OpenFile opens a file in the text mode using inFile.
//

#include <iostream>
#include <fstream>

using namespace std;

void OpenFile(const char *fileName, ifstream &inFile)
{
    //open file
    inFile.open(fileName);
    if (!inFile.is_open())
    {
        //if error opening file
        cerr << "Problem opening file.Exiting...\n";
        //exit the program
        exit(EXIT_FAILURE);
    }
}
