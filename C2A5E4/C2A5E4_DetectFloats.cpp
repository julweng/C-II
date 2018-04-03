//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// May 1, 2017
// C2A5E4_DetectFloats.cpp
// Mac OS X
// Xcode Version 8.3.1
//
// description:
// This file contains the defition of the DetectFloats function, which reads the characters
// in a character string and determine if it is a floating literal. If a complete floating
// literal is detected, the program will return the detected data type. Otherwise, the
// program will exit with a message that the string is not a floating literal. This is an
// implementation of the state machine diagram in C2A5E3.
//

#include "C2A5E4_StatusCode-Driver.h"

StatusCode DetectFloats(const char *chPtr)
{
    //data type enum States which consists of the states in the C2A5E3 diagram as its enumerators
    enum States
    {
        START,
        WHOLE,
        NOTWHOLE,
        EXPONENT,
        FRACTION,
        FLOAT,
        LONGDOUBLE,
        SIGN,
        AFTEREXPONENT
    } state = START;
    
    //use chPtr to loop through character in the string and test at each state
    for (;; chPtr++)
    {
        //go to start
        switch (state)
        {
            case START:
                switch (*chPtr)
                {
                    case '.':
                        state = NOTWHOLE;
                        break;
                    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
                    case '8': case '9':
                        state = WHOLE;
                        break;
                    default:
                        return(NOTFLOATING);
                }
                break;
        
            //go to NOTWHOLE if point is found at START
            case NOTWHOLE:
                switch (*chPtr)
                {
                    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
                    case '8': case '9':
                        state = FRACTION;
                        break;
                    default:
                        return(NOTFLOATING);
                }
                break;
        
            //go to FRACTION if digit is found at NOTWHOLE
            case FRACTION:
                switch (*chPtr)
                {
                    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
                    case '8': case '9':
                        state = FRACTION;
                        break;
                    case 'L': case 'l':
                        state = LONGDOUBLE;
                        break;
                    case 'F': case 'f':
                        state = FLOAT;
                        break;
                    case 'E': case 'e':
                        state = EXPONENT;
                        break;
                    case '\0':
                        return(TYPE_DOUBLE);
                    default:
                        return(NOTFLOATING);
                }
                break;
                
            //go to LONGDOUBLE if L or l is found at FRACTION
            case LONGDOUBLE:
                switch (*chPtr)
                {
                    case '\0':
                        return(TYPE_LDOUBLE);
                    default:
                        return(NOTFLOATING);
                }
                
            //go to FLOAT if F or f is found at FRACTION
            case FLOAT:
                switch (*chPtr)
                {
                    case '\0':
                        return(TYPE_FLOAT);
                    default:
                        return(NOTFLOATING);
                }
                
            //go to WHOLE if digit is found at START
            case WHOLE:
                switch (*chPtr)
                {
                    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
                    case '8': case '9':
                        state = WHOLE;
                        break;
                    case '.':
                        state = FRACTION;
                        break;
                    case 'E': case 'e':
                        state = EXPONENT;
                        break;
                    default:
                        return(NOTFLOATING);
                }
                break;
                
            //go to EXPONENT if E or e is found at FRACTION or WHOLE
            case EXPONENT:
                switch (*chPtr)
                {
                    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
                    case '8': case '9':
                        state = AFTEREXPONENT;
                        break;
                    case '+': case '-':
                        state = SIGN;
                        break;
                    default:
                        return(NOTFLOATING);
                }
                break;
            
            //go to SIGN if plus or minus sign is found at EXPONENT
            case SIGN:
                switch (*chPtr)
                {
                    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
                    case '8': case '9':
                        state = AFTEREXPONENT;
                        break;
                    default:
                        return(NOTFLOATING);
                }
                break;
                
            //go to AFTEREXPONENT if digit is found at EXPONENT or SIGN
            case AFTEREXPONENT:
                switch (*chPtr)
                {
                    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
                    case '8': case '9':
                        state = AFTEREXPONENT;
                        break;
                    case 'F': case 'f':
                        state = FLOAT;
                        break;
                    case 'L': case 'l':
                        state = LONGDOUBLE;
                        break;
                    case '\0':
                        return(TYPE_DOUBLE);
                    default:
                        return(NOTFLOATING);
                }
                break;
        }
    }
}
