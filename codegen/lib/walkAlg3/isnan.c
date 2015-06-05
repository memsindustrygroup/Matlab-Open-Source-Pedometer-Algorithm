/*
 * isnan.c
 *
 * Code generation for function 'isnan'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "aTimeUnroll2.h"
#include "stepCounter_struct_init.h"
#include "walkAlg3.h"
#include "isnan.h"

/* Function Definitions */
boolean_T b_isnan(float x)
{
  return rtIsNaNF(x);
}

/* End of code generation (isnan.c) */
