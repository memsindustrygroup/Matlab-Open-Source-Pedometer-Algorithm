/*
 * stepCounter_struct_init.c
 *
 * Code generation for function 'stepCounter_struct_init'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "aTimeUnroll2.h"
#include "stepCounter_struct_init.h"
#include "walkAlg3.h"

/* Function Definitions */
struct0_T stepCounter_struct_init(void)
{
  struct0_T walkStruct;
  int i0;

  /* %% init of stepCounter structure */
  /*  */
  /*  */
  /*  walkStruct */
  walkStruct.HIthrA = 2.0F;
  walkStruct.LIthrA = 0.7F;
  walkStruct.HIthrW = 1.7F;
  walkStruct.LIthrW = 1.05F;
  walkStruct.timeThr = 250.0F;

  /*  made a single for real time updates */
  walkStruct.HLI = 0U;
  walkStruct.HIt = 0U;
  walkStruct.LIt = 0U;
  walkStruct.HIcnt = 0U;
  walkStruct.LIcnt = 0U;
  for (i0 = 0; i0 < 3; i0++) {
    walkStruct.Acur[i0] = 0.0F;

    /* accel x y z time */
    walkStruct.AcurRMS[i0] = 0.0F;
    walkStruct.Aprev[i0] = 0.0F;
    walkStruct.AprevRMS[i0] = 0.0F;
  }

  walkStruct.Acurt = 0U;
  walkStruct.Aprevt = 0U;
  walkStruct.crossed = 0;
  walkStruct.addPoint = 0;

  /*  1 to add point, 0 for nothing, -1 to lose point */
  walkStruct.reset = 0;

  /*  end of interval reset flag */
  walkStruct.aTimeUnroll = 0U;
  walkStruct.prevTime = 0;
  walkStruct.nWrap = 0;
  walkStruct.timerOverflow = 0;
  walkStruct.counterOverflow = 0;
  return walkStruct;
}

/* End of code generation (stepCounter_struct_init.c) */
