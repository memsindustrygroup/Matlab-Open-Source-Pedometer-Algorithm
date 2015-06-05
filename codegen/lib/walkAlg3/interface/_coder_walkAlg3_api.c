/*
 * _coder_walkAlg3_api.c
 *
 * Code generation for function 'walkAlg3'
 *
 */

/* Include files */
#include "_coder_walkAlg3_api.h"

/* Function Declarations */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *walkStruct,
  const char *identifier, struct0_T *y);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static float c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static unsigned int d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, float y[3]);
static unsigned char f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static signed char g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static unsigned short h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static float (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *accDataIn,
  const char *identifier))[3];
static float (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static unsigned int k_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tDataIn, const char *identifier);
static float l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *whichThr,
  const char *identifier);
static const mxArray *emlrt_marshallOut(const struct0_T *u);
static const mxArray *b_emlrt_marshallOut(const float u);
static const mxArray *c_emlrt_marshallOut(const unsigned int u);
static const mxArray *d_emlrt_marshallOut(const float u[3]);
static const mxArray *e_emlrt_marshallOut(const unsigned char u);
static const mxArray *f_emlrt_marshallOut(const signed char u);
static const mxArray *g_emlrt_marshallOut(const unsigned short u);
static unsigned short m_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *atime, const char *identifier);
static float n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static unsigned int o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, float ret[3]);
static unsigned char q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static signed char r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static unsigned short s_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *src, const emlrtMsgIdentifier *msgId);
static float (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];

/* Function Definitions */
void walkAlg3_initialize(emlrtContext *aContext)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void walkAlg3_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void walkAlg3_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  walkAlg3_xil_terminate();
}

void walkAlg3_api(const mxArray *prhs[5], const mxArray *plhs[1])
{
  struct0_T walkStruct;
  float (*accDataIn)[3];
  float (*aRMSin)[3];
  unsigned int tDataIn;
  float whichThr;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  prhs[1] = emlrtProtectR2012b(prhs[1], 1, false, -1);
  prhs[2] = emlrtProtectR2012b(prhs[2], 2, false, -1);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "walkStruct", &walkStruct);
  accDataIn = i_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "accDataIn");
  aRMSin = i_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "aRMSin");
  tDataIn = k_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "tDataIn");
  whichThr = l_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "whichThr");

  /* Invoke the target function */
  walkAlg3(&walkStruct, *accDataIn, *aRMSin, tDataIn, whichThr);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&walkStruct);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *walkStruct,
  const char *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(sp, emlrtAlias(walkStruct), &thisId, y);
  emlrtDestroyArray(&walkStruct);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[24] = { "HIthrA", "LIthrA", "HIthrW", "LIthrW",
    "timeThr", "HLI", "HIt", "LIt", "HIcnt", "LIcnt", "Acur", "AcurRMS", "Aprev",
    "AprevRMS", "Acurt", "Aprevt", "crossed", "addPoint", "reset", "aTimeUnroll",
    "prevTime", "nWrap", "timerOverflow", "counterOverflow" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 24, fieldNames, 0U, 0);
  thisId.fIdentifier = "HIthrA";
  y->HIthrA = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "HIthrA")), &thisId);
  thisId.fIdentifier = "LIthrA";
  y->LIthrA = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "LIthrA")), &thisId);
  thisId.fIdentifier = "HIthrW";
  y->HIthrW = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "HIthrW")), &thisId);
  thisId.fIdentifier = "LIthrW";
  y->LIthrW = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "LIthrW")), &thisId);
  thisId.fIdentifier = "timeThr";
  y->timeThr = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "timeThr")), &thisId);
  thisId.fIdentifier = "HLI";
  y->HLI = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "HLI")),
    &thisId);
  thisId.fIdentifier = "HIt";
  y->HIt = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "HIt")),
    &thisId);
  thisId.fIdentifier = "LIt";
  y->LIt = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "LIt")),
    &thisId);
  thisId.fIdentifier = "HIcnt";
  y->HIcnt = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "HIcnt")), &thisId);
  thisId.fIdentifier = "LIcnt";
  y->LIcnt = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "LIcnt")), &thisId);
  thisId.fIdentifier = "Acur";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "Acur")),
                     &thisId, y->Acur);
  thisId.fIdentifier = "AcurRMS";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "AcurRMS")),
                     &thisId, y->AcurRMS);
  thisId.fIdentifier = "Aprev";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "Aprev")),
                     &thisId, y->Aprev);
  thisId.fIdentifier = "AprevRMS";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "AprevRMS")),
                     &thisId, y->AprevRMS);
  thisId.fIdentifier = "Acurt";
  y->Acurt = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Acurt")), &thisId);
  thisId.fIdentifier = "Aprevt";
  y->Aprevt = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "Aprevt")), &thisId);
  thisId.fIdentifier = "crossed";
  y->crossed = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "crossed")), &thisId);
  thisId.fIdentifier = "addPoint";
  y->addPoint = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "addPoint")), &thisId);
  thisId.fIdentifier = "reset";
  y->reset = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "reset")), &thisId);
  thisId.fIdentifier = "aTimeUnroll";
  y->aTimeUnroll = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "aTimeUnroll")), &thisId);
  thisId.fIdentifier = "prevTime";
  y->prevTime = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "prevTime")), &thisId);
  thisId.fIdentifier = "nWrap";
  y->nWrap = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "nWrap")), &thisId);
  thisId.fIdentifier = "timerOverflow";
  y->timerOverflow = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "timerOverflow")), &thisId);
  thisId.fIdentifier = "counterOverflow";
  y->counterOverflow = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "counterOverflow")), &thisId);
  emlrtDestroyArray(&u);
}

static float c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  float y;
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static unsigned int d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  unsigned int y;
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, float y[3])
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static unsigned char f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  unsigned char y;
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static signed char g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  signed char y;
  y = r_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static unsigned short h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  unsigned short y;
  y = s_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static float (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *accDataIn,
  const char *identifier))[3]
{
  float (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = j_emlrt_marshallIn(sp, emlrtAlias(accDataIn), &thisId);
  emlrtDestroyArray(&accDataIn);
  return y;
}
  static float (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[3]
{
  float (*y)[3];
  y = t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static unsigned int k_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tDataIn, const char *identifier)
{
  unsigned int y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(sp, emlrtAlias(tDataIn), &thisId);
  emlrtDestroyArray(&tDataIn);
  return y;
}

static float l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *whichThr,
  const char *identifier)
{
  float y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = c_emlrt_marshallIn(sp, emlrtAlias(whichThr), &thisId);
  emlrtDestroyArray(&whichThr);
  return y;
}

static const mxArray *emlrt_marshallOut(const struct0_T *u)
{
  const mxArray *y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  emlrtAddField(y, b_emlrt_marshallOut(u->HIthrA), "HIthrA", 0);
  emlrtAddField(y, b_emlrt_marshallOut(u->LIthrA), "LIthrA", 0);
  emlrtAddField(y, b_emlrt_marshallOut(u->HIthrW), "HIthrW", 0);
  emlrtAddField(y, b_emlrt_marshallOut(u->LIthrW), "LIthrW", 0);
  emlrtAddField(y, b_emlrt_marshallOut(u->timeThr), "timeThr", 0);
  emlrtAddField(y, c_emlrt_marshallOut(u->HLI), "HLI", 0);
  emlrtAddField(y, c_emlrt_marshallOut(u->HIt), "HIt", 0);
  emlrtAddField(y, c_emlrt_marshallOut(u->LIt), "LIt", 0);
  emlrtAddField(y, c_emlrt_marshallOut(u->HIcnt), "HIcnt", 0);
  emlrtAddField(y, c_emlrt_marshallOut(u->LIcnt), "LIcnt", 0);
  emlrtAddField(y, d_emlrt_marshallOut(u->Acur), "Acur", 0);
  emlrtAddField(y, d_emlrt_marshallOut(u->AcurRMS), "AcurRMS", 0);
  emlrtAddField(y, d_emlrt_marshallOut(u->Aprev), "Aprev", 0);
  emlrtAddField(y, d_emlrt_marshallOut(u->AprevRMS), "AprevRMS", 0);
  emlrtAddField(y, c_emlrt_marshallOut(u->Acurt), "Acurt", 0);
  emlrtAddField(y, c_emlrt_marshallOut(u->Aprevt), "Aprevt", 0);
  emlrtAddField(y, e_emlrt_marshallOut(u->crossed), "crossed", 0);
  emlrtAddField(y, f_emlrt_marshallOut(u->addPoint), "addPoint", 0);
  emlrtAddField(y, e_emlrt_marshallOut(u->reset), "reset", 0);
  emlrtAddField(y, c_emlrt_marshallOut(u->aTimeUnroll), "aTimeUnroll", 0);
  emlrtAddField(y, g_emlrt_marshallOut(u->prevTime), "prevTime", 0);
  emlrtAddField(y, g_emlrt_marshallOut(u->nWrap), "nWrap", 0);
  emlrtAddField(y, e_emlrt_marshallOut(u->timerOverflow), "timerOverflow", 0);
  emlrtAddField(y, e_emlrt_marshallOut(u->counterOverflow), "counterOverflow", 0);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const float u)
{
  const mxArray *y;
  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
  *(float *)mxGetData(m0) = u;
  emlrtAssign(&y, m0);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const unsigned int u)
{
  const mxArray *y;
  const mxArray *m1;
  y = NULL;
  m1 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(unsigned int *)mxGetData(m1) = u;
  emlrtAssign(&y, m1);
  return y;
}

static const mxArray *d_emlrt_marshallOut(const float u[3])
{
  const mxArray *y;
  static const int iv0[2] = { 1, 3 };

  const mxArray *m2;
  float *pData;
  int i;
  y = NULL;
  m2 = emlrtCreateNumericArray(2, iv0, mxSINGLE_CLASS, mxREAL);
  pData = (float *)mxGetData(m2);
  for (i = 0; i < 3; i++) {
    pData[i] = u[i];
  }

  emlrtAssign(&y, m2);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const unsigned char u)
{
  const mxArray *y;
  const mxArray *m3;
  y = NULL;
  m3 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(unsigned char *)mxGetData(m3) = u;
  emlrtAssign(&y, m3);
  return y;
}

static const mxArray *f_emlrt_marshallOut(const signed char u)
{
  const mxArray *y;
  const mxArray *m4;
  y = NULL;
  m4 = emlrtCreateNumericMatrix(1, 1, mxINT8_CLASS, mxREAL);
  *(signed char *)mxGetData(m4) = u;
  emlrtAssign(&y, m4);
  return y;
}

static const mxArray *g_emlrt_marshallOut(const unsigned short u)
{
  const mxArray *y;
  const mxArray *m5;
  y = NULL;
  m5 = emlrtCreateNumericMatrix(1, 1, mxUINT16_CLASS, mxREAL);
  *(unsigned short *)mxGetData(m5) = u;
  emlrtAssign(&y, m5);
  return y;
}

void stepCounter_struct_init_api(const mxArray *plhs[1])
{
  struct0_T walkStruct;

  /* Invoke the target function */
  walkStruct = stepCounter_struct_init();

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&walkStruct);
}

void aTimeUnroll2_api(const mxArray * const prhs[3], const mxArray *plhs[1])
{
  unsigned short atime;
  float resolution;
  struct0_T walkStruct;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  atime = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "atime");
  resolution = l_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "resolution");
  emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "walkStruct", &walkStruct);

  /* Invoke the target function */
  aTimeUnroll2(atime, resolution, &walkStruct);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&walkStruct);
}

static unsigned short m_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *atime, const char *identifier)
{
  unsigned short y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = h_emlrt_marshallIn(sp, emlrtAlias(atime), &thisId);
  emlrtDestroyArray(&atime);
  return y;
}

static float n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  float ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "single", false, 0U, 0);
  ret = *(float *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static unsigned int o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  unsigned int ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint32", false, 0U, 0);
  ret = *(unsigned int *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, float ret[3])
{
  int iv1[2];
  int i0;
  for (i0 = 0; i0 < 2; i0++) {
    iv1[i0] = 1 + (i0 << 1);
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "single", false, 2U, iv1);
  for (i0 = 0; i0 < 3; i0++) {
    ret[i0] = (*(float (*)[3])mxGetData(src))[i0];
  }

  emlrtDestroyArray(&src);
}

static unsigned char q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  unsigned char ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 0U, 0);
  ret = *(unsigned char *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static signed char r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  signed char ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "int8", false, 0U, 0);
  ret = *(signed char *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static unsigned short s_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *src, const emlrtMsgIdentifier *msgId)
{
  unsigned short ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint16", false, 0U, 0);
  ret = *(unsigned short *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static float (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  float (*ret)[3];
  int iv2[2];
  int i1;
  for (i1 = 0; i1 < 2; i1++) {
    iv2[i1] = 1 + (i1 << 1);
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "single", false, 2U, iv2);
  ret = (float (*)[3])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/* End of code generation (_coder_walkAlg3_api.c) */
