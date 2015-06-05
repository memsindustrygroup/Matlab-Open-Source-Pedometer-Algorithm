/*
 * aTimeUnroll2.c
 *
 * Code generation for function 'aTimeUnroll2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "aTimeUnroll2.h"
#include "stepCounter_struct_init.h"
#include "walkAlg3.h"

/* Function Declarations */
static float rt_roundf_snf(float u);

/* Function Definitions */
static float rt_roundf_snf(float u)
{
  float y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

void aTimeUnroll2(unsigned short atime, float resolution, struct0_T *walkStruct)
{
  unsigned int u0;
  float f0;
  if (walkStruct->prevTime > atime) {
    /* if previosu time is greater than current time, then increase count to note wrap */
    /*  assumes no packets lost, and updates within 2 seconds of each other.. */
    u0 = walkStruct->nWrap + 1U;
    if (u0 > 65535U) {
      u0 = 65535U;
    }

    walkStruct->nWrap = (unsigned short)u0;
  }

  /*  set in milliseconds for best storage method */
  f0 = rt_roundf_snf((float)(walkStruct->nWrap * 65535U + atime) * resolution *
                     1000.0F);
  if (f0 < 4.2949673E+9F) {
    if (f0 >= 0.0F) {
      u0 = (unsigned int)f0;
    } else {
      u0 = 0U;
    }
  } else if (f0 >= 4.2949673E+9F) {
    u0 = MAX_uint32_T;
  } else {
    u0 = 0U;
  }

  walkStruct->aTimeUnroll = u0;

  /*  wrap corrected time scaled in milli seconds */
  if (walkStruct->aTimeUnroll > 4294967294U) {
    /*  max uint32 # */
    walkStruct->nWrap = 0;
    walkStruct->timerOverflow = 1;

    /*  sets overflow flag to 1 */
  } else {
    walkStruct->timerOverflow = 0;

    /*  resets wrapper back to 0 */
  }

  walkStruct->prevTime = atime;
}

/* End of code generation (aTimeUnroll2.c) */
