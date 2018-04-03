#define INSTRUCTOR_FILE /* DO NOT DEFINE THIS MACRO IN ANY FILES YOU CREATE */

/***  YOU DO NOT NEED TO UNDERSTAND THE CODE IN THIS FILE TO WRITE YOURS  ***/

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

#include <stdio.h>

#define TEST_APPEND_EXPECTED_RESULTS_FILE_NAME "Append_ExpectedResults.bin"
#define TEST_APPEND_TARGET_FILE_NAME "Append_ActualResults.bin"
#define TEST_INFILE1_NAME "Append_GettysburgAddress.txt"
#define TEST_INFILE2_NAME "Append_3000Nulls.bin"

int AppendFile(const char *inFile, const char *outFile);

/*
 * Test: AppendFile
 */
int main(void)
{
   int tests = 0, errors = 0;

   FILE *fpActual, *fpExpected;

   remove(TEST_APPEND_TARGET_FILE_NAME);
   AppendFile(TEST_INFILE1_NAME, TEST_APPEND_TARGET_FILE_NAME);
   AppendFile(TEST_INFILE2_NAME, TEST_APPEND_TARGET_FILE_NAME);
   AppendFile(TEST_INFILE1_NAME, TEST_APPEND_TARGET_FILE_NAME);
   AppendFile(TEST_INFILE2_NAME, TEST_APPEND_TARGET_FILE_NAME);

   ++tests;
   if ((fpActual = fopen(TEST_APPEND_TARGET_FILE_NAME, "rb")) == 0)
   {
      ++errors;
      perror(TEST_APPEND_TARGET_FILE_NAME);
      putc('\n', stderr);
   }
   else if ((fpExpected = fopen(TEST_APPEND_EXPECTED_RESULTS_FILE_NAME, "rb"))
      == 0)
   {
      ++errors;
      perror(TEST_APPEND_EXPECTED_RESULTS_FILE_NAME);
      putc('\n', stderr);
      fclose(fpActual);
   }
   else
   {
      ++tests;
      for (;;)
      {
         int actualCh = getc(fpActual);
         int expectedCh = getc(fpExpected);
         if (actualCh == expectedCh)
         {
            if (actualCh == EOF)
               break;
         }
         else
         {
            fprintf(stderr,
               "***ERROR*** AppendFile: Concatenation failed.\n\n");
            ++errors;
            break;
         }
      }
   }
   const char *plural = errors != 1 ? "s" : "";
   if (errors)
      fputc('\n', stderr);
   fprintf(stderr, "C2A1E6: %d tests %d error%s.\n",
      tests, errors, plural);

   return 0;
}
#endif
