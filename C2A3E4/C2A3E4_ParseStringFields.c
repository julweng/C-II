/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * Apr 24, 2017
 * C2A3E4_ParseStringFields.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description:
 * This file contains definition of the function RecordOpinions that prompts user to rate a product,
 * record the ratings and prints them out.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DELIM "AEIOUaeiou\n"
#define BUFSIZE 256

void ParseStringFields(FILE *fp)
{
    /* use line as placeholder for string from fp */
    char line[BUFSIZE];
    
    /* read string line by line */
    while (fgets(line, BUFSIZE, fp))
    {
        /* break line into tokens, walk through all tokens until the last token is reached */
        char *token;
        for (token = strtok(line, DELIM); token != NULL;)
        {
            /* if there is a whitespace, move over it */
            while (isspace((int)(*token)))
            {
                token++;
            }
            
            /*print tokens */
            printf("%s\n", token);
            /* next token */
            token = strtok(NULL, DELIM);
        }
    }
}
