//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// Apr 10, 2017
// C2A1E8_Employee.cpp
// Mac OS X
// Xcode Version 8.3
//
// description:
// This file contains the definition of the Employee::Set function. The function
// takes a pointer to constant char parameter that points to a string that represents
// an employee's name. Then, the function will dynamically allocate memory to store
// that string, sets member name to point to where the string is located in memory,
// and make a copy of that string into memory.
//

#include "C2A1E8_Employee.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void Employee::Set(const char *setName)
{
    name = new char [strlen(setName) + 1];
 
    if(name == NULL)
    {
        cerr << "Error allocating memory\n";
        exit(EXIT_FAILURE);
    }
       strcpy(name, setName);
    return;
}
