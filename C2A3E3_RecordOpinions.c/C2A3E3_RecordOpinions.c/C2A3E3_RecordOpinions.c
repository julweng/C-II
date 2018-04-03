/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * Apr 24, 2017
 * C2A3E3_RecordOpinions.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description:
 * This file contains definition of the function RecordOpinions that prompts user to rate a product,
 * record the ratings and prints them out.
 */

#include <stdio.h>

#define ENDPOINT 5
#define TERMINATE 99
#define ARRAYSIZE (2 * ENDPOINT + 1)

void RecordOpinions(void)
{
    int resp[ARRAYSIZE] = {0};
    
    for (;;)
    {
        /* prompt user for rating */
        /* note to self: rating temporarily stores user entry and will be used to derive the index for resp */
        int rating;
        printf("Enter your rating\n");
        scanf("%d", &rating);
        
        /* if rating is out of range and equals TERMINATE, exit loop */
        if (rating == TERMINATE)
        {
            printf("exiting loop...\n");
            break;
        }
        
        /* if rating is out of range but not equal to TERMINATE, prompt user again */
        else if ((rating > ENDPOINT || rating < -ENDPOINT) && (rating != TERMINATE))
        {
            printf("Enter a valid number.\n");
            continue;
        }
        
        /* if rating is within range, add rating to reponse and count response */
        else if (rating <= ENDPOINT || rating >= -ENDPOINT)
        {
            ++resp[rating + ENDPOINT];
        }
    }
    
    /* print a table for rating and response count */
    printf("\n""Rating      Responses\n""------      ---------\n");
    
    for (int respCounter = 0; respCounter < ARRAYSIZE; respCounter++)
    {
        printf("%4d%14d\n", respCounter - ENDPOINT, resp[respCounter]);
    }
}
