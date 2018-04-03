//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// May 15, 2017
// C2A8E1_MergeAndDisplay.cpp
// Mac OS X
// Xcode Version 8.3.1
//
// description:
// This file contains the definition of the function MergeAndDisplay, which reads and print
// the first line of the content of each input file, then reads and print the second line of
// each input file, and continues until it reaches the end of a file.
//

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void MergeAndDisplay(ifstream files[], size_t count)
{
    // use currentfile as a flag to keep track of file whose line is being read into buffer
    int currentfile = (int)count;
    
    while (currentfile != 0)
    {
        currentfile = 0;
        
        for (ifstream *p = files; p < files + count; ++p)
        {
            //if file is open
            if (p->is_open())
            {
                string buffer;
                // use getline to read line to buffer
                if (getline(*p, buffer))
                {
                    currentfile++;
                    // print content
                    cout << buffer << "\n";
                }
                // if getline gets to the end
                else
                {
                    p->close();
                }
            }
        }
    }
}
