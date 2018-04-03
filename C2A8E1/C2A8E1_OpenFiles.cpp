//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// May 15, 2017
// C2A8E1_OpenFiles.cpp
// Mac OS X
// Xcode Version 8.3.1
//
// description:
// This file contains the definition for the function OpenFile, which creates an array of
// open ifstream objects to open the files named in fileNames. If no file names are in the input,
// or if memory allocation fails, or if there is open file failure, the program will output an
// error message and terminate.
//

#include <iostream>
#include <fstream>

using namespace std;

ifstream *OpenFiles(char * const fileNames[], size_t count)
{
    // check if count is zero
    if (count == 0)
    {
        // if array is empty, output error message
        cerr << "No filename input.\n";
        
        // exit program
        exit(EXIT_FAILURE);
    }
    
    //allocate space for fileName array
    ifstream *p;
    if ((p = new (nothrow) ifstream[count]) == NULL)
    {
        // if memory allocation fails, output error message
        cerr << "Out of memory!\n";
        
        //exit program
        exit(EXIT_FAILURE);
    }
    
    //otherwise, open each file in fileName in read only mode
    for (size_t open = 0; open < count; ++open)
    {
        //Open each file individually/safely in read only text mode
        p[open].open(fileNames[open]);
        
        //test for file open success
        if (!p[open].is_open())
        {
            //If file open failure, output error message
            cerr << "Failed to open file " << fileNames[open] << "\n";
            
            //delete the allocated array
            delete[] p;
            
            //exit program
            exit(EXIT_FAILURE);
        }
    }
    return(p);
}
