/*
 * Julia Tzu-Ya Weng, U07487022
 * julweng@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section: 121616
 * Instructor: Raymond Mitchell
 * May 21, 2017
 * C2A8E2_DisplayModifiedSingleReals.c
 * Mac OS X
 * Xcode Version 8.3.1
 *
 * description:
 * This file contains the definition of the DisplayModifiedSingleReals function.
 * The function displays the IEEE 754 data representation of the floating point format 
 * in the modified version: 9 bits for the exponent field and 22 bits for the fraction field.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F_NORM 1                                                 /* positive normalized number */
#define F_NNORM (-F_NORM)                                        /* negative normalized number */
#define F_DENORM 2                                               /* postive denormalized number */
#define F_NDENORM (-F_DENORM)                                    /* negative denormalized number */
#define F_PZERO 3                                                /* positive zero */
#define F_NZERO (-F_PZERO)                                       /* negative zero */
#define F_PINF 4                                                 /* positive infinity */
#define F_NINF (-F_PINF)                                         /* negative infinity */
#define F_PNAN 5                                                 /* positive NaN */
#define F_NNAN (-F_PNAN)                                         /* negative NaN */
#define SIGN_MASK 0x80000000uL                                   /* sign field bit mask */
#define EXP_MASK 0x7FC00000uL                                    /* exponent field bit mask */
#define FRAC_MASK 0x003FFFFFuL                                   /* fraction field bit mask */
#define FRAC_BITS 22                                             /* bits in fraction field */
#define EXP_NBIAS 255                                            /* normalized number exponent bias */
#define EXP_DBIAS 254                                            /* denormalized number exponent bias */
#define EXP_MAX 511                                              /* exponent maximum value */
#define BASE 2                                                   /* base */
#define HEXSIZE 8                                                /* amount of character to in hex value */
#define BUFSIZE 4                                                /* byte of buffer size */
#define START (BUFSIZE - 1)                                      /* starting point of pattern to read */

static int NewSingleReal(unsigned long pattern, double *result)  /* display modified single real values */
{                                                                /* modified from note 16.10E */
    int signIsNegative = !!(SIGN_MASK & pattern);                /* true if negative value */
    int exponent = (EXP_MASK & pattern) >> FRAC_BITS;            /* value of exponent field */
    int fraction = FRAC_MASK & pattern;                          /* value of fraction field */
    int status;
    
    if (exponent == 0 && fraction == 0)                          /* test for negative/positive zero */
    {
        status = signIsNegative ? F_NZERO : F_PZERO;
        *result = 0;
    }
    
    else if (exponent == EXP_MAX && fraction == 0)               /* test for negative/positive infinity */
        status = signIsNegative ? F_NINF : F_PINF;
    
    else if (exponent == EXP_MAX && fraction != 0)               /* test for negative/positive NANs */
        status = signIsNegative ? F_NNAN : F_PNAN;
    
    else                                                         /* test for normalized/denormalized */
    {
        *result = fraction * pow(BASE, -FRAC_BITS);              /* value of the fractional part */
        int bias;
        if (exponent !=  0)                                      /* if number is normalized */
        {
            bias = EXP_NBIAS;
            status = signIsNegative ? F_NNORM : F_NORM;          /* negative or positive normalized */
            ++*result;
        }
        else                                                     /* if number is denormalized */
        {
            bias = EXP_DBIAS;                                    
            status = signIsNegative ? F_NDENORM : F_DENORM;      /* negative or positive denormalized */
        }
        *result *= pow(BASE, exponent - bias);                   /* mantissa *=base to exponent */
        
        if (signIsNegative)                                      /* if number is negative */
            *result = -*result;                                  /* negate the value */
    }
    return(status);                                              /* return status of the analysis */
}

void DisplayModifiedSingleReals(FILE *inFile)                    /* display modified singel reals */
{
    unsigned char buffer[BUFSIZE];
    
    for (;;)
    {
        size_t readElem = fread(buffer, 1, BUFSIZE, inFile);     /* read and return number of elements read */
        
        if (readElem != BUFSIZE)                                 /* if not BUFSIZE, error or EOF */
        {
            if (readElem != 0)                                   /* if not 0, incomplete pattern read */
            {
                printf("Unexpected EOF\n");                      /* display error message */
            }
            break;
        }
        
        int status;
        
        unsigned long pattern = (unsigned long)buffer[START];

        for (int read = START - 1; read >= 0; read--)            /* bitwise read buffer to pattern */
        {
            pattern |= (unsigned long)buffer[read] << (START - read) * HEXSIZE;
        }
        printf("0x%08lx   ", pattern);                           /* print pattern in hex with 8 trailing 0 */
        
        double result;
        
        status = NewSingleReal(pattern, &result);                /* determine status using NewSingleReal */
        
        switch (status)                                          /* go thru status options for match */
        {
            case F_NORM:                                         /* positive normalized pattern */
                printf("+%-17eNormal\n", result);
                break;
                
            case F_NNORM:                                        /* negative normalized pattern */
                printf("%-18eNormal\n", result);
                break;
            case F_DENORM:                                       /* positive denormalized pattern */
                printf("+%-17eDenormal\n", result);
                break;
            case F_NDENORM:                                      /* negative denormalized pattern */
                printf("%-18eDenormal\n", result);
                break;
            case F_PZERO:
                printf("+%-17eZero\n", result);                  /* positive zero */
                break;
            case F_NZERO:
                printf("-%-17eZero\n", result);                  /* negative zero */
                break;
            case F_PNAN:
                printf("+NAN\n");                                /* positive NAN */
                break;
            case F_NNAN:
                printf("-NAN\n");                                /* negative NAN */
                break;
            case F_PINF:
                printf("+INF\n");                                /* positive infinity */
                break;
            case F_NINF:                                         /* negative infinity */
                printf("-INF\n");
                break;
            default:
                printf("An error has occurred");
        }
        
        if (feof(inFile))                                        /* read and display until EOF */
            break;
    }
}
