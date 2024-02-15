/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hardwareModel_Balance_1.h
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

#ifndef RTW_HEADER_hardwareModel_Balance_1_h_
#define RTW_HEADER_hardwareModel_Balance_1_h_
#ifndef hardwareModel_Balance_1_COMMON_INCLUDES_
#define hardwareModel_Balance_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_I2C.h"
#include "io_wrappers.h"
#include "MW_PWM.h"
#endif                            /* hardwareModel_Balance_1_COMMON_INCLUDES_ */

#include "hardwareModel_Balance_1_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Probe[2];                     /* '<S8>/Probe' */
  uint32_T i2cname;
  MW_I2C_Mode_Type modename;
  uint32_T i2cname_m;
  MW_I2C_Mode_Type modename_c;
  uint32_T i2cname_k;
  MW_I2C_Mode_Type modename_cx;
  uint32_T i2cname_b;
  MW_I2C_Mode_Type modename_p;
  real_T userEnable;                   /* '<S1>/userEnable' */
  real_T theta;                        /* '<S5>/Bias' */
  real_T batteryvoltage;               /* '<S5>/Gain3' */
  real_T pTerm;                        /* '<S4>/Kp' */
  real_T dTerm;                        /* '<S4>/Kd' */
  real_T pTermW;                       /* '<S4>/Kpw' */
  real_T Add;                          /* '<S4>/Add' */
  real_T Integrator;                   /* '<S12>/Integrator' */
  real_T rads;                         /* '<S5>/Gain4' */
  real_T Gain1;                        /* '<S2>/Gain1' */
  uint8_T SwappedDataBytes[6];
  int16_T b_RegisterValue[3];
  int16_T b_RegisterValue_c[3];
  uint8_T output_raw[6];
  uint8_T final_data_to_write[6];
  uint8_T SwappedDataBytes_f[6];
  uint8_T out_raw[5];
  uint8_T output_raw_g[5];
  int32_T count;
  uint32_T out;
  uint16_T IMUStatus;                  /* '<S5>/Product of Elements' */
  boolean_T enable;                    /* '<S1>/Chart' */
} B_hardwareModel_Balance_1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S13>/Base sensor block' */
  motorcarrier_blocks_mkrmotorc_T obj_j;/* '<S2>/Battery Read' */
  motorcarrier_blocks_mkrmoto_p_T obj_m;/* '<S2>/Iniertia Wheel' */
  motorcarrier_blocks_mkrmot_p0_T obj_d;/* '<S2>/M1 M2 DC Motors' */
  motorcarrier_blocks_mkrmo_p0g_T obj_n;/* '<S2>/Servo Write' */
  codertarget_arduinobase_int_p_T obj_i;/* '<S14>/Reverse PWM' */
  codertarget_arduinobase_int_p_T obj_mh;/* '<S14>/Forward PWM' */
  real_T Integrator_DSTATE;            /* '<S12>/Integrator' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S5>/Scope' */

  uint32_T is_checkFallen;             /* '<S1>/Chart' */
  uint32_T is_checkIMUCalib;           /* '<S1>/Chart' */
  uint32_T is_checkBattery;            /* '<S1>/Chart' */
  uint32_T is_calculateEnable;         /* '<S1>/Chart' */
  int8_T Integrator_PrevResetState;    /* '<S12>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S12>/Integrator' */
  uint8_T is_active_c3_hardwareModel_Bala;/* '<S1>/Chart' */
  uint8_T is_active_checkFallen;       /* '<S1>/Chart' */
  uint8_T is_active_checkIMUCalib;     /* '<S1>/Chart' */
  uint8_T is_active_checkBattery;      /* '<S1>/Chart' */
  uint8_T is_active_calculateEnable;   /* '<S1>/Chart' */
  boolean_T upright;                   /* '<S1>/Chart' */
  boolean_T IMUCalibrated;             /* '<S1>/Chart' */
  boolean_T batteryOK;                 /* '<S1>/Chart' */
} DW_hardwareModel_Balance_1_T;

/* Parameters (default storage) */
struct P_hardwareModel_Balance_1_T_ {
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by: '<S2>/Battery Read'
                                        */
  real_T FilteredDerivative1_A;        /* Mask Parameter: FilteredDerivative1_A
                                        * Referenced by: '<S7>/[A,B]'
                                        */
  real_T FilteredDerivative1_B;        /* Mask Parameter: FilteredDerivative1_B
                                        * Referenced by: '<S7>/[A,B]'
                                        */
  real_T FilteredDerivative1_K;        /* Mask Parameter: FilteredDerivative1_K
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T BNO055IMUSensor_SampleTime;
                                   /* Mask Parameter: BNO055IMUSensor_SampleTime
                                    * Referenced by: '<S13>/Base sensor block'
                                    */
  real_T FilteredDerivative1_T;        /* Mask Parameter: FilteredDerivative1_T
                                        * Referenced by: '<S8>/Time constant'
                                        */
  real_T FilteredDerivative1_minRatio;
                                 /* Mask Parameter: FilteredDerivative1_minRatio
                                  * Referenced by: '<S8>/Minimum sampling to time constant ratio'
                                  */
  int8_T CompareToConstant_const[4];  /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S6>/Constant'
                                       */
  real_T userEnable_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/userEnable'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T deg2rad1_Gain;                /* Expression: pi/180
                                        * Referenced by: '<S5>/deg2rad1'
                                        */
  real_T Bias_Bias;                    /* Expression: 0.00005*180*2/pi
                                        * Referenced by: '<S5>/Bias'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/236
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T Kp_Gain;                      /* Expression: 65
                                        * Referenced by: '<S4>/Kp'
                                        */
  real_T deg2rad_Gain;                 /* Expression: pi/180
                                        * Referenced by: '<S5>/deg2rad'
                                        */
  real_T Kd_Gain;                      /* Expression: 12
                                        * Referenced by: '<S4>/Kd'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1/48
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 2*pi
                                        * Referenced by: '<S5>/Gain4'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: windupUpperLimit
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: windupLowerLimit
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Kpw_Gain;                     /* Expression: 0.0015
                                        * Referenced by: '<S4>/Kpw'
                                        */
  real_T whenDisabled_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/whenDisabled'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: 1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: -1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 255
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 100
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Constant1_Value;              /* Expression: 70
                                        * Referenced by: '<S2>/Constant1'
                                        */
  int16_T Constant1_Value_c;           /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S14>/Constant1'
                                        */
  int16_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S14>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_hardwareModel_Balance_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_hardwareModel_Balance_1_T hardwareModel_Balance_1_P;

/* Block signals (default storage) */
extern B_hardwareModel_Balance_1_T hardwareModel_Balance_1_B;

/* Block states (default storage) */
extern DW_hardwareModel_Balance_1_T hardwareModel_Balance_1_DW;

/* Model entry point functions */
extern void hardwareModel_Balance_1_initialize(void);
extern void hardwareModel_Balance_1_step(void);
extern void hardwareModel_Balance_1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_hardwareModel_Balanc_T *const hardwareModel_Balance_1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S5>/Signal Conversion1' : Eliminate redundant signal conversion block
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'hardwareModel_Balance_1'
 * '<S1>'   : 'hardwareModel_Balance_1/digital controller'
 * '<S2>'   : 'hardwareModel_Balance_1/motorcycle'
 * '<S3>'   : 'hardwareModel_Balance_1/digital controller/Chart'
 * '<S4>'   : 'hardwareModel_Balance_1/digital controller/controller'
 * '<S5>'   : 'hardwareModel_Balance_1/digital controller/sensor preporcessing'
 * '<S6>'   : 'hardwareModel_Balance_1/digital controller/sensor preporcessing/Compare To Constant'
 * '<S7>'   : 'hardwareModel_Balance_1/digital controller/sensor preporcessing/Filtered Derivative 1'
 * '<S8>'   : 'hardwareModel_Balance_1/digital controller/sensor preporcessing/Filtered Derivative 1/Enable//disable time constant'
 * '<S9>'   : 'hardwareModel_Balance_1/digital controller/sensor preporcessing/Filtered Derivative 1/Initialization'
 * '<S10>'  : 'hardwareModel_Balance_1/digital controller/sensor preporcessing/Filtered Derivative 1/Integrator (Discrete or Continuous)'
 * '<S11>'  : 'hardwareModel_Balance_1/digital controller/sensor preporcessing/Filtered Derivative 1/Initialization/Init_u'
 * '<S12>'  : 'hardwareModel_Balance_1/digital controller/sensor preporcessing/Filtered Derivative 1/Integrator (Discrete or Continuous)/Discrete'
 * '<S13>'  : 'hardwareModel_Balance_1/motorcycle/BNO055 IMU  Sensor'
 * '<S14>'  : 'hardwareModel_Balance_1/motorcycle/M3M4DCMotors'
 */
#endif                               /* RTW_HEADER_hardwareModel_Balance_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
