/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * May 7, 2017
 * C2A6E4_List.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description:
 * This file contains the defition of the CreateList, PrintList, FreeList functions.
 * CreateList creates a list for the strings read from the open text file. PrintList
 * prints a list of the read strings. FreeList frees up the memory dynamically allocated 
 * to read in the strings from the open text file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C2A6E4_List-Driver.h"

/*size of input buffer */
#define BUFSIZE 256
/* field width for input buffer scan */
#define BUFFWD "%255"

/* safemalloc functions that tests for dynamic allocation (copied from note 8.6) */
static void *SafeMalloc(size_t size)
{
    void *vp;
    /* if memory allocation fails */
    if ((vp = malloc(size)) == NULL)
    {
        /* output error message and exit program */
        fputs("Out of memory\n", stderr);
        exit(EXIT_FAILURE);
    }
    return(vp);
}

/* create a list for the strings from the open text file pointed to by fp */
List *CreateList(FILE *fp)
{
    /* head points to a list type */
    List *head;
    
    /* textString will be used for getting the input string from the text file pointed to by fp */
    char textString[BUFSIZE];

    /* list pointed to by head begins with NULL */
    /* read and break the text file into whitespace separated strings and temporarily store in textString */
    for (head = NULL; fscanf(fp, BUFFWD "s", textString) != EOF;)
    {
        List *pTemp;
        
        /* compare string in list pointed to by head and string in textString */
        for (pTemp = head; pTemp != NULL && strcmp(pTemp->str, textString); pTemp = pTemp->next)
            ;
        
        /* if strings in current list and textString are the same */
        if (pTemp != NULL)
        {
            /* add a count to that string item */
            ++pTemp->count;
        }
            
        /* if end of list is reached and still can't find the same string */
        else
        {
            /* allocate memory for a new list node using SafeMalloc */
            pTemp = (List *)SafeMalloc(sizeof(List));
                
            /* make next point to the previous node pointed to by head */
            pTemp->next = head;
                
            /* make head point to the newly inserted node */
            head = pTemp;
                
            /* give the string item one count */
            pTemp->count = 1;
                
            /* allocate memory for string using SafeMalloc */
            size_t length = strlen(textString) + 1;
            pTemp->str = (char *)SafeMalloc(length);
                
            /* copy str to textString */
            memcpy(pTemp->str, textString, length);
        }
    }
    return(head);
}

/* print a table from the list pointed to by head */
List *PrintList(const List *head)
{
    const List *pTemp;
    /* use p to iterate through the list */
    for (pTemp = head; pTemp != NULL; pTemp = pTemp->next)
    {
        //print aligend strings and counts
        printf("%-18s%4d ea\n", pTemp->str, pTemp->count);
    }
    return (List *)head;
}

/* frees the memory dynamically allocated to the list pointed to by head; modified from note 15.14B */
void FreeList(List *head)
{
    /* loop thru the list to free storage */
    for (List * ptr = head; ptr != NULL;)
    {
        /* save head to p */
        List *pTemp = ptr;
        
        /* so head can point to next node */
        ptr = ptr->next;
        
        /* free storage */
        free(pTemp->str);
        
        /* free pTemp */
        free(pTemp);
    }
}
