/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hardwareModel_Balance_1_private.h
 *
 * Code generated for Simulink model 'hardwareModel_Balance_1'.
 *
 * Model version                  : 5.6
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Oct 18 20:57:06 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_hardwareModel_Balance_1_private_h_
#define RTW_HEADER_hardwareModel_Balance_1_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "hardwareModel_Balance_1_types.h"
#include "hardwareModel_Balance_1.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern int32_T mul_s32_sat(int32_T a, int32_T b);

#endif                       /* RTW_HEADER_hardwareModel_Balance_1_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
