//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// Apr 17, 2017
// C2A2E4_Reverse.cpp
// Mac OS X
// Xcode Version 8.3
//
// description:
// This file contains definition of the Reverse function.
// Reverse is a recursive function that reads the text file in inFile one character
// at a time until it reaches a separataor. Then, the function will display the read text
// in reverse order and capitalize the last character displayed. However, the separator
// is not reversed.
//

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

const int LEVELCHANGE = 1;

// checks for separator
inline bool isSeparator(int ch)
{
    // look for any whitespace that is defined by isspace
    if (isspace(ch))
        return true;
    // or look for any other separators: ".?!,:;"
    else if (ch ==  '.' || ch == '?' || ch == '!' || ch == ',' || ch == ':' || ch == ';' || ch == EOF)
        return true;
    else
        return false;
}

int Reverse(ifstream &inFile, const int level)
{
    //get character from inFile
    int thisChar = inFile.get();
    int thisSeparator;
    
    //if thisChar is a separator
    if (isSeparator(thisChar))
    
        //return this separator to the caller (exit recursion)
        return thisChar;
    
    //else call Reverse again
    else
        thisSeparator = Reverse(inFile, level + LEVELCHANGE);
    
    
    //if level is 1, capitalize this first character
    if (level == 1)
        cout << char(toupper(thisChar));
    else
        cout << char(thisChar);
        
    return thisSeparator;
}
