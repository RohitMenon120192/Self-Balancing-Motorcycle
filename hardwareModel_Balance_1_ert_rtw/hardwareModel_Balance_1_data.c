/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hardwareModel_Balance_1_data.c
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

#include "hardwareModel_Balance_1.h"

/* Block parameters (default storage) */
P_hardwareModel_Balance_1_T hardwareModel_Balance_1_P = {
  /* Variable: Ts
   * Referenced by: '<S2>/Battery Read'
   */
  0.01,

  /* Mask Parameter: FilteredDerivative1_A
   * Referenced by: '<S7>/[A,B]'
   */
  0.0,

  /* Mask Parameter: FilteredDerivative1_B
   * Referenced by: '<S7>/[A,B]'
   */
  0.0,

  /* Mask Parameter: FilteredDerivative1_K
   * Referenced by: '<S7>/Gain'
   */
  1.0,

  /* Mask Parameter: BNO055IMUSensor_SampleTime
   * Referenced by: '<S13>/Base sensor block'
   */
  0.01,

  /* Mask Parameter: FilteredDerivative1_T
   * Referenced by: '<S8>/Time constant'
   */
  0.1,

  /* Mask Parameter: FilteredDerivative1_minRatio
   * Referenced by: '<S8>/Minimum sampling to time constant ratio'
   */
  10.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S6>/Constant'
   */
  { 0, 0, 0, 3 },

  /* Expression: 0
   * Referenced by: '<S1>/userEnable'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S5>/Gain2'
   */
  -1.0,

  /* Expression: pi/180
   * Referenced by: '<S5>/deg2rad1'
   */
  0.017453292519943295,

  /* Expression: 0.00005*180*2/pi
   * Referenced by: '<S5>/Bias'
   */
  0.0057295779513082332,

  /* Expression: 1/236
   * Referenced by: '<S5>/Gain3'
   */
  0.00423728813559322,

  /* Expression: 65
   * Referenced by: '<S4>/Kp'
   */
  65.0,

  /* Expression: pi/180
   * Referenced by: '<S5>/deg2rad'
   */
  0.017453292519943295,

  /* Expression: 12
   * Referenced by: '<S4>/Kd'
   */
  12.0,

  /* Expression: -1/48
   * Referenced by: '<S5>/Gain1'
   */
  -0.020833333333333332,

  /* Expression: 2*pi
   * Referenced by: '<S5>/Gain4'
   */
  6.2831853071795862,

  /* Expression: 0
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S12>/Integrator'
   */
  0.01,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S12>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S12>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S12>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S12>/Saturation'
   */
  0.0,

  /* Expression: 0.0015
   * Referenced by: '<S4>/Kpw'
   */
  0.0015,

  /* Expression: 0
   * Referenced by: '<S1>/whenDisabled'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S2>/Saturation'
   */
  -1.0,

  /* Expression: 255
   * Referenced by: '<S2>/Gain'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Saturation1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S2>/Saturation1'
   */
  -1.0,

  /* Expression: 100
   * Referenced by: '<S2>/Gain1'
   */
  100.0,

  /* Expression: 70
   * Referenced by: '<S2>/Constant1'
   */
  70.0,

  /* Computed Parameter: Constant1_Value_c
   * Referenced by: '<S14>/Constant1'
   */
  0,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S14>/Switch'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
