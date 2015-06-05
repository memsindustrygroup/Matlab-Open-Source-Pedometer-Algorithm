/*
 * _coder_walkAlg3_mex.c
 *
 * Code generation for function 'walkAlg3'
 *
 */

/* Include files */
#include "mex.h"
#include "_coder_walkAlg3_api.h"

/* Function Declarations */
static void aTimeUnroll2_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);
static void stepCounter_struct_init_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);
static void walkAlg3_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "walkAlg3", NULL, false, {2045744189U,2170104910U,2743257031U,4284093946U}, NULL };
void *emlrtRootTLSGlobal = NULL;
emlrtEntryPoint emlrtEntryPoints[3] = {
  { "aTimeUnroll2", aTimeUnroll2_mexFunction },
  { "stepCounter_struct_init", stepCounter_struct_init_mexFunction },
  { "walkAlg3", walkAlg3_mexFunction },
};

/* Function Definitions */
static void walkAlg3_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  const mxArray *outputs[1];
  const mxArray *inputs[5];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  int nInputs = nrhs;
  emlrtStack st = { NULL, NULL, NULL };
  /* Module initialization. */
  walkAlg3_initialize(&emlrtContextGlobal);
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, mxINT32_CLASS, 5, mxCHAR_CLASS, 8, "walkAlg3");
  } else if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, mxCHAR_CLASS, 8, "walkAlg3");
  }
  /* Temporary copy for mex inputs. */
  for (n = 0; n < nInputs; ++n) {
    inputs[n] = prhs[n];
  }
  /* Call the function. */
  walkAlg3_api(inputs, outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  walkAlg3_terminate();
}
static void stepCounter_struct_init_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  const mxArray *outputs[1];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  emlrtStack st = { NULL, NULL, NULL };
  /* Module initialization. */
  walkAlg3_initialize(&emlrtContextGlobal);
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, mxINT32_CLASS, 0, mxCHAR_CLASS, 23, "stepCounter_struct_init");
  } else if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, mxCHAR_CLASS, 23, "stepCounter_struct_init");
  }
  /* Call the function. */
  stepCounter_struct_init_api(outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  walkAlg3_terminate();
}
static void aTimeUnroll2_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  const mxArray *outputs[1];
  const mxArray *inputs[3];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  int nInputs = nrhs;
  emlrtStack st = { NULL, NULL, NULL };
  /* Module initialization. */
  walkAlg3_initialize(&emlrtContextGlobal);
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, mxINT32_CLASS, 3, mxCHAR_CLASS, 12, "aTimeUnroll2");
  } else if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, mxCHAR_CLASS, 12, "aTimeUnroll2");
  }
  /* Temporary copy for mex inputs. */
  for (n = 0; n < nInputs; ++n) {
    inputs[n] = prhs[n];
  }
  /* Call the function. */
  aTimeUnroll2_api(inputs, outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  walkAlg3_terminate();
}

void walkAlg3_atexit_wrapper(void)
{
   walkAlg3_atexit();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  emlrtMexFunction method;
  method = emlrtGetMethod(nrhs, prhs, emlrtEntryPoints, 3);
  /* Initialize the memory manager. */
  mexAtExit(walkAlg3_atexit_wrapper);
  /* Dispatch the entry-point. */
  method(nlhs, plhs, nrhs-1, prhs+1);
}
/* End of code generation (_coder_walkAlg3_mex.c) */
