/*
 * abs.h
 *
 * Code generation for function 'abs'
 *
 */

#ifndef __ABS_H__
#define __ABS_H__

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "walkAlg3_types.h"

/* Function Declarations */
extern void b_abs(const float x[3], float y[3]);
extern unsigned int c_abs(unsigned int x);

#endif

/* End of code generation (abs.h) */
