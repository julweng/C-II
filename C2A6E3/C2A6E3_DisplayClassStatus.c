/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * May 7, 2017
 * C2A6E3_DisplayClassStatus.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description:
 * This file contains the defitions of the Compare, SortStudents, and DisplayClassStatus functions.
 * Compare uses the strcmp function to compare the elements in the names array character by character.
 * SortStudents uses the qsort function to sort the elements in the array in alphabetical order.
 * DisplayClassStatus displays the names of those who did not attend the first class and those 
 * who are present but not registered.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//const char *names[] = { "Al", "Ned Nasty", "Sweet L. Sally", etc. };

/* Compares the value of the object pointed to by elemA and elemB */
int Compare(const void *elemA, const void *elemB)
{
    /* return the int value from strcmp */
    /* must typecast void pointers in order to dereference */
    return(strcmp(*(char **)elemA, *(char **)elemB));
}

/* sort elements in studentList in alphabetical order using qsort */
void SortStudents(const char *studentList[], size_t studentCount)
{
    /* must typecast studentList to void * to pass it into Compare */
    qsort((void *)studentList, studentCount, sizeof(*studentList), Compare);
}

void DisplayClassStatus(const char *registrants[], size_t registrantCount,
                        const char *attendees[], size_t attendeeCount)
{
    const char **first, **last;
    
    /* not present list */
    printf("Not present:\n");
    
    /* find if a registrant(key) is among the attendees(base) using bsearch */
    for (first = registrants, last = registrants + registrantCount; first < last; ++first)
    {
        /* typecast arguments because bsearch takes void * arguments */
        if ((bsearch((void *)first, (void *)attendees, attendeeCount, sizeof(*attendees), Compare)) == NULL)
        {
            /* if not found, print in the not present list */
            printf("    %s\n", *first);
        }
    }

    /* not registered list */
    printf("Not registered:\n");
    
    /* find if an attendees(key) is among the registrants(base) using bsearch */
    for (first = attendees, last = attendees + attendeeCount; first < last; ++first)
    {
        /* typecast arguments because bsearch takes void * arguments */
        if ((bsearch((void *)first, (void *)registrants, registrantCount, sizeof(*registrants), Compare
            )) == NULL)
        {
            /* if not found, print in the not registered list */
            printf("    %s\n", *first);
        }
    }
}
