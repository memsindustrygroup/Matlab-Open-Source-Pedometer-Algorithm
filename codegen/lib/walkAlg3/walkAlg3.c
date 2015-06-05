/*
 * walkAlg3.c
 *
 * Code generation for function 'walkAlg3'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "aTimeUnroll2.h"
#include "stepCounter_struct_init.h"
#include "walkAlg3.h"
#include "isnan.h"
#include "abs.h"

/* Function Declarations */
static float eml_extremum(const float x[3]);

/* Function Definitions */
static float eml_extremum(const float x[3])
{
  float extremum;
  int ixstart;
  int ix;
  boolean_T exitg1;
  ixstart = 1;
  extremum = x[0];
  if (b_isnan(x[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 4)) {
      ixstart = ix;
      if (!b_isnan(x[ix - 1])) {
        extremum = x[ix - 1];
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 3) {
    while (ixstart + 1 < 4) {
      if (x[ixstart] > extremum) {
        extremum = x[ixstart];
      }

      ixstart++;
    }
  }

  return extremum;
}

void walkAlg3(struct0_T *walkStruct, const float accDataIn[3], const float
              aRMSin[3], unsigned int tDataIn, float whichThr)
{
  float LIth;
  float HIth;
  float b_accDataIn[3];
  int i1;
  float fv0[3];
  unsigned int q0;
  unsigned int qY;
  float b_walkStruct[3];
  float fv1[3];
  float fv2[3];
  float fv3[3];
  float fv4[3];
  float fv5[3];
  float fv6[3];
  float fv7[3];

  /* %% walking algorithm.  */
  /*  Performs step counting primarily targeted for the wrist mounting, uses */
  /*  maximum observed value for each. Could also be used for accel radii. */
  /*  Inputs:  */
  /*  walkStruct = holds all persistent varibles as well as thresholds, see */
  /*  stepCounter_struct_init for definitions. */
  /*  accDataIn = accel data inputs, x, y, z; can be lowpass filtered */
  /*  if desired. */
  /*  aRMSin = moving average or rms data, subtracted from data. Can input */
  /*  zeros, or input RMS data as desired, will require different thresholds. */
  /*  tDataIn = time data, in milliseconds, relative timing between points is */
  /*  all that matters, but must be unwrapped before input to this function. */
  /*  whichThr = allows user to store two sets of thresholds and switch with */
  /*  this value. Example, could use different thresholds for 0 aRMSin vs moving */
  /*  standard deviation for aRMSin and switch depending on if data available. */
  /*  */
  /*  */
  /*  choose a thershold setting  */
  /*  two threshold settings per to denote high acceleration or low */
  /*  acceleration amplitudes */
  if (whichThr == 2.0F) {
    LIth = walkStruct->LIthrA;
    HIth = walkStruct->HIthrA;
  } else {
    LIth = walkStruct->LIthrW;
    HIth = walkStruct->HIthrW;
  }

  walkStruct->addPoint = 0;
  for (i1 = 0; i1 < 3; i1++) {
    b_accDataIn[i1] = accDataIn[i1] - aRMSin[i1];
  }

  b_abs(b_accDataIn, fv0);
  if (eml_extremum(fv0) > LIth) {
    /*  check if data has crossed minimum threshold */
    if (!(walkStruct->crossed != 0)) {
      /*  when it crosses a threshold incremement steps */
      q0 = walkStruct->HLI;
      qY = q0 + 1U;
      if (qY < q0) {
        qY = MAX_uint32_T;
      }

      walkStruct->HLI = qY;

      /*  step count */
      walkStruct->crossed = 1;
    }

    /*  if newest point is highest current point for this crossing, save */
    /*  it as the current peak data point */
    for (i1 = 0; i1 < 3; i1++) {
      b_accDataIn[i1] = accDataIn[i1] - aRMSin[i1];
    }

    for (i1 = 0; i1 < 3; i1++) {
      b_walkStruct[i1] = walkStruct->Acur[i1] - walkStruct->AcurRMS[i1];
    }

    b_abs(b_accDataIn, fv1);
    b_abs(b_walkStruct, fv2);
    if (eml_extremum(fv1) > eml_extremum(fv2)) {
      for (i1 = 0; i1 < 3; i1++) {
        walkStruct->Acur[i1] = accDataIn[i1];
      }

      for (i1 = 0; i1 < 3; i1++) {
        walkStruct->AcurRMS[i1] = aRMSin[i1];
      }

      walkStruct->Acurt = tDataIn;

      /*  time and value */
    }
  } else {
    if (walkStruct->crossed != 0) {
      /*  once data crosses back under threshold, perform calculations and determine step type */
      walkStruct->addPoint = 1;
      for (i1 = 0; i1 < 3; i1++) {
        b_walkStruct[i1] = walkStruct->Acur[i1] - walkStruct->AcurRMS[i1];
      }

      b_abs(b_walkStruct, fv3);
      if (eml_extremum(fv3) > HIth) {
        /*  high impact point classification */
        q0 = walkStruct->HIcnt;
        qY = q0 + 1U;
        if (qY < q0) {
          qY = MAX_uint32_T;
        }

        walkStruct->HIcnt = qY;
        q0 = walkStruct->HIt;
        qY = q0 + 1U;
        if (qY < q0) {
          qY = MAX_uint32_T;
        }

        walkStruct->HIt = qY;
      } else {
        /*  low impact point classification */
        q0 = walkStruct->LIcnt;
        qY = q0 + 1U;
        if (qY < q0) {
          qY = MAX_uint32_T;
        }

        walkStruct->LIcnt = qY;
        q0 = walkStruct->LIt;
        qY = q0 + 1U;
        if (qY < q0) {
          qY = MAX_uint32_T;
        }

        walkStruct->LIt = qY;
      }

      if (walkStruct->HLI > 1U) {
        /*  remove data points that are too close together in time */
        q0 = walkStruct->Acurt;
        qY = q0 - walkStruct->Aprevt;
        if (qY > q0) {
          qY = 0U;
        }

        if ((double)c_abs(qY) < walkStruct->timeThr) {
          q0 = walkStruct->HLI;
          qY = q0 - 1U;
          if (qY > q0) {
            qY = 0U;
          }

          walkStruct->HLI = qY;
          walkStruct->addPoint = -1;
          for (i1 = 0; i1 < 3; i1++) {
            b_walkStruct[i1] = walkStruct->Aprev[i1] - walkStruct->AprevRMS[i1];
          }

          for (i1 = 0; i1 < 3; i1++) {
            b_accDataIn[i1] = walkStruct->Acur[i1] - walkStruct->AcurRMS[i1];
          }

          b_abs(b_walkStruct, fv4);
          b_abs(b_accDataIn, fv5);
          if (eml_extremum(fv4) > eml_extremum(fv5)) {
            for (i1 = 0; i1 < 3; i1++) {
              b_walkStruct[i1] = walkStruct->Acur[i1] - walkStruct->AcurRMS[i1];
            }

            b_abs(b_walkStruct, fv6);
            if (eml_extremum(fv6) > HIth) {
              q0 = walkStruct->HIcnt;
              qY = q0 - 1U;
              if (qY > q0) {
                qY = 0U;
              }

              walkStruct->HIcnt = qY;
              q0 = walkStruct->HIt;
              qY = q0 - 1U;
              if (qY > q0) {
                qY = 0U;
              }

              walkStruct->HIt = qY;
            } else {
              q0 = walkStruct->LIcnt;
              qY = q0 - 1U;
              if (qY > q0) {
                qY = 0U;
              }

              walkStruct->LIcnt = qY;
              q0 = walkStruct->LIt;
              qY = q0 - 1U;
              if (qY > q0) {
                qY = 0U;
              }

              walkStruct->LIt = qY;
            }

            for (i1 = 0; i1 < 3; i1++) {
              walkStruct->Acur[i1] = walkStruct->Aprev[i1];
            }

            for (i1 = 0; i1 < 3; i1++) {
              walkStruct->AcurRMS[i1] = walkStruct->AprevRMS[i1];
            }

            walkStruct->Acurt = walkStruct->Aprevt;
          } else {
            for (i1 = 0; i1 < 3; i1++) {
              b_walkStruct[i1] = walkStruct->Aprev[i1] - walkStruct->AprevRMS[i1];
            }

            b_abs(b_walkStruct, fv7);
            if (eml_extremum(fv7) > HIth) {
              q0 = walkStruct->HIcnt;
              qY = q0 - 1U;
              if (qY > q0) {
                qY = 0U;
              }

              walkStruct->HIcnt = qY;
              q0 = walkStruct->HIt;
              qY = q0 - 1U;
              if (qY > q0) {
                qY = 0U;
              }

              walkStruct->HIt = qY;
            } else {
              q0 = walkStruct->LIcnt;
              qY = q0 - 1U;
              if (qY > q0) {
                qY = 0U;
              }

              walkStruct->LIcnt = qY;
              q0 = walkStruct->LIt;
              qY = q0 - 1U;
              if (qY > q0) {
                qY = 0U;
              }

              walkStruct->LIt = qY;
            }
          }
        }
      }

      /*  set the current point as the previous point, and reset the */
      /*  current point for new steps. */
      for (i1 = 0; i1 < 3; i1++) {
        walkStruct->Aprev[i1] = walkStruct->Acur[i1];
      }

      for (i1 = 0; i1 < 3; i1++) {
        walkStruct->AprevRMS[i1] = walkStruct->AcurRMS[i1];
      }

      walkStruct->Aprevt = walkStruct->Acurt;
      for (i1 = 0; i1 < 3; i1++) {
        walkStruct->Acur[i1] = 0.0F;
      }

      for (i1 = 0; i1 < 3; i1++) {
        walkStruct->AcurRMS[i1] = 0.0F;
      }

      walkStruct->Acurt = 0U;
      walkStruct->crossed = 0;
    }
  }

  /*  end */
}

/* End of code generation (walkAlg3.c) */
