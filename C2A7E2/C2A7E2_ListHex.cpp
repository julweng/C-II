//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// May 1, 2017
// C2A7E2_ListHex.cpp
// Mac OS X
// Xcode Version 8.3.1
//
// description:
// This file contains the definition of the ListHex function.
// The function reads in the content of a file one byte at a time and
// print out the hexadecimal representations of the read content in a line.
// The amount to be printed on a line depends on the specified bytesPerLine.
//

#include <iostream>
#include <iomanip>
#include <fstream>

const int BYTE = 1;

using namespace std;

//test for failed new allocation
static void *SafeNew(size_t size)
{
    void *vp;
    
    //if failure to allocate memory
    if ((vp = new (nothrow) size_t[size]) == NULL)
    {
        //error message and exit program
        cerr << "Out of memory\n";
        exit(EXIT_FAILURE);
    }
    return(vp);
}

void ListHex(ifstream &inFile, int bytesPerLine)
{
    //allocate memory for buffer
    char *buffer = (char *)SafeNew((size_t)BYTE);
    
    //set up format for fill and hex
    cout << setfill('0') << hex;
    
    //read inFile until EOF is reached
    while (!inFile.eof())
    {
        //read in content one byte at a time
        for (int byteCount = 0; byteCount < bytesPerLine; ++byteCount, ++*buffer)
        {
            //read content to buffer one byte at a time
            inFile.read(buffer, BYTE);
            
            if (!inFile.eof())
            {
                //print 2 digit hex representation of content in a line specified by bytesPerLine
                cout << setw(2) << (int)(unsigned char)*buffer << " ";
            }
        }
        cout << "\n";
    }
    delete[] buffer;
}
