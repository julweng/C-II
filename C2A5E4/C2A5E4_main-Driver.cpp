#define INSTRUCTOR_FILE /* DO NOT DEFINE THIS MACRO IN ANY FILES YOU CREATE */

/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/
/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/
/******************** DO NOT MODIFY THIS FILE IN ANY WAY ********************/

/****************************************************************************
 * Everything in this file was written to help test/verify your code and must
 * not be altered in any way.  Do not rename this file or copy anything from
 * it into your file(s).  This file does not necessarily represent good coding
 * technique, proper formatting/style, or meet the requirements your code must
 * meet.  You do not need to understand the code in this file to write yours.
 ***************************************************************************/
#ifdef INSTRUCTOR_FILE

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "C2A5E4_StatusCode-Driver.h"

const char * const FILENAME = "TestFile5.txt";

void OpenFile(const char *fileName, ifstream &inFile);
StatusCode DetectFloats(const char *chPtr);

int main()
{
   const int BUFSIZE = 128;                 // input string buffer size
   const int SAFEBUF = BUFSIZE - 1;         // limit input string
   char buf[BUFSIZE];                       // input buffer
   ifstream inFile;

   OpenFile(FILENAME, inFile);

   // Get one string at a time and pass it to the parser function.
   while (inFile >> setw(SAFEBUF) >> buf)
   {
      cout << '"' << buf << "\" is ";
      switch (DetectFloats(buf))
      {
         case NOTFLOATING:  cout << "not a floating literal.\n";        break;
         case TYPE_FLOAT:   cout << "type float.\n";                    break;
         case TYPE_DOUBLE:  cout << "type double.\n";                   break;
         case TYPE_LDOUBLE: cout << "type long double.\n";              break;
         default:           cout << "*****internal error*****\n";       break;
      }
   }

   inFile.close();
   return EXIT_SUCCESS;
}
#endif
