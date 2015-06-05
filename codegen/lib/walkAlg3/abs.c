/*
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "aTimeUnroll2.h"
#include "stepCounter_struct_init.h"
#include "walkAlg3.h"
#include "abs.h"

/* Function Declarations */
static unsigned int b_eml_scalar_abs(unsigned int x);
static float eml_scalar_abs(float x);

/* Function Definitions */
static unsigned int b_eml_scalar_abs(unsigned int x)
{
  return x;
}

static float eml_scalar_abs(float x)
{
  return (real32_T)fabs(x);
}

void b_abs(const float x[3], float y[3])
{
  int k;
  for (k = 0; k < 3; k++) {
    y[k] = eml_scalar_abs(x[k]);
  }
}

unsigned int c_abs(unsigned int x)
{
  return b_eml_scalar_abs(x);
}

/* End of code generation (abs.c) */
