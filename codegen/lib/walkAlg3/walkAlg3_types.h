/*
 * walkAlg3_types.h
 *
 * Code generation for function 'walkAlg3'
 *
 */

#ifndef __WALKALG3_TYPES_H__
#define __WALKALG3_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct
{
    float HIthrA;
    float LIthrA;
    float HIthrW;
    float LIthrW;
    float timeThr;
    unsigned int HLI;
    unsigned int HIt;
    unsigned int LIt;
    unsigned int HIcnt;
    unsigned int LIcnt;
    float Acur[3];
    float AcurRMS[3];
    float Aprev[3];
    float AprevRMS[3];
    unsigned int Acurt;
    unsigned int Aprevt;
    unsigned char crossed;
    signed char addPoint;
    unsigned char reset;
    unsigned int aTimeUnroll;
    unsigned short prevTime;
    unsigned short nWrap;
    unsigned char timerOverflow;
    unsigned char counterOverflow;
} struct0_T;
#endif /*typedef_struct0_T*/

#endif
/* End of code generation (walkAlg3_types.h) */
