/*
 * _coder_walkAlg3_api.h
 *
 * Code generation for function 'walkAlg3'
 *
 */

#ifndef ___CODER_WALKALG3_API_H__
#define ___CODER_WALKALG3_API_H__
/* Include files */
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

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

/* Function Declarations */
extern void walkAlg3_initialize(emlrtContext *aContext);
extern void walkAlg3_terminate(void);
extern void walkAlg3_atexit(void);
extern void walkAlg3_api(const mxArray *prhs[5], const mxArray *plhs[1]);
extern void stepCounter_struct_init_api(const mxArray *plhs[1]);
extern struct0_T stepCounter_struct_init(void);
extern void aTimeUnroll2_api(const mxArray * const prhs[3], const mxArray *plhs[1]);
extern void walkAlg3_xil_terminate(void);
extern void walkAlg3(struct0_T *walkStruct, float accDataIn[3], float aRMSin[3], unsigned int tDataIn, float whichThr);
extern void aTimeUnroll2(unsigned short atime, float resolution, struct0_T *walkStruct);

#endif
/* End of code generation (_coder_walkAlg3_api.h) */
