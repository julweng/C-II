//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// Apr 10, 2017
// C2A1E7_AppendFile.cpp
// Mac OS X
// Xcode Version 8.3
//
// description:
// This file contains definition of the AppendFile function, that takes 2 parameters,
// inFile and outFile, which are of pointer to const char type. AppendFile will read
// the content of the file whose name is pointed to by inFile and append to the content
// of the file whose name is pointed to by outFile.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int FAILURE = -1;                                               /* value of failure code */

int AppendFile(const char *inFile, const char *outFile)
{
    ifstream source;
    fstream dest;
    
    source.open(inFile, ios_base::in | ios_base::binary);             /* open source for read */
    dest.open(outFile,  ios_base::app | ios_base::binary);            /* open dest for append */
    
    if (!source.is_open() || !dest.is_open())                         /* if open error */
    {
        cerr << "Error opening file.\n";                              /* error message */
        exit(FAILURE);                                                /* terminate program */
    }
    else
    {
        int ch;                                                       
        while ((ch = source.get()) != EOF)                            /* read source till EOF */
            dest.put(char(ch));                                       /* append to dest */
    }
    
    source.close();                                                   /* close source */
    dest.close();                                                     /* close dest */
    return(EXIT_SUCCESS);
}
