/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hardwareModel_Balance_1_types.h
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

#ifndef RTW_HEADER_hardwareModel_Balance_1_types_h_
#define RTW_HEADER_hardwareModel_Balance_1_types_h_
#include "MW_SVD.h"
#include "rtwtypes.h"

/* Custom Type definition for MATLABSystem: '<S2>/Servo Write' */
#include "MW_SVD.h"
#ifndef struct_tag_jbIFaTBEZATkkvPSmnoPa
#define struct_tag_jbIFaTBEZATkkvPSmnoPa

struct tag_jbIFaTBEZATkkvPSmnoPa
{
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_jbIFaTBEZATkkvPSmnoPa */

#ifndef typedef_c_arduinodriver_ArduinoI2C_ha_T
#define typedef_c_arduinodriver_ArduinoI2C_ha_T

typedef struct tag_jbIFaTBEZATkkvPSmnoPa c_arduinodriver_ArduinoI2C_ha_T;

#endif                             /* typedef_c_arduinodriver_ArduinoI2C_ha_T */

#ifndef struct_tag_9AnIRoZpmWNSR76ytV7oUG
#define struct_tag_9AnIRoZpmWNSR76ytV7oUG

struct tag_9AnIRoZpmWNSR76ytV7oUG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  c_arduinodriver_ArduinoI2C_ha_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
};

#endif                                 /* struct_tag_9AnIRoZpmWNSR76ytV7oUG */

#ifndef typedef_i_codertarget_arduinobase_int_T
#define typedef_i_codertarget_arduinobase_int_T

typedef struct tag_9AnIRoZpmWNSR76ytV7oUG i_codertarget_arduinobase_int_T;

#endif                             /* typedef_i_codertarget_arduinobase_int_T */

#ifndef struct_tag_TyJSH6R1I3sZx6CTdR9Tw
#define struct_tag_TyJSH6R1I3sZx6CTdR9Tw

struct tag_TyJSH6R1I3sZx6CTdR9Tw
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  boolean_T IsFirstStep;
  boolean_T isBNOcorrect;
  i_codertarget_arduinobase_int_T i2cObj;
};

#endif                                 /* struct_tag_TyJSH6R1I3sZx6CTdR9Tw */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_TyJSH6R1I3sZx6CTdR9Tw codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_9AnIRoZpmWNSR76ytV7oUG
#define struct_tag_9AnIRoZpmWNSR76ytV7oUG

struct tag_9AnIRoZpmWNSR76ytV7oUG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  c_arduinodriver_ArduinoI2C_ha_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
};

#endif                                 /* struct_tag_9AnIRoZpmWNSR76ytV7oUG */

#ifndef typedef_f_codertarget_arduinobase_int_T
#define typedef_f_codertarget_arduinobase_int_T

typedef struct tag_9AnIRoZpmWNSR76ytV7oUG f_codertarget_arduinobase_int_T;

#endif                             /* typedef_f_codertarget_arduinobase_int_T */

#ifndef struct_tag_EmKWWlznjKlEpXleb4tCkH
#define struct_tag_EmKWWlznjKlEpXleb4tCkH

struct tag_EmKWWlznjKlEpXleb4tCkH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_codertarget_arduinobase_int_T i2cObj;
  real_T SampleTime;
};

#endif                                 /* struct_tag_EmKWWlznjKlEpXleb4tCkH */

#ifndef typedef_motorcarrier_blocks_mkrmotorc_T
#define typedef_motorcarrier_blocks_mkrmotorc_T

typedef struct tag_EmKWWlznjKlEpXleb4tCkH motorcarrier_blocks_mkrmotorc_T;

#endif                             /* typedef_motorcarrier_blocks_mkrmotorc_T */

#ifndef struct_tag_7gi4MQy35pU3EJY2pB6u1G
#define struct_tag_7gi4MQy35pU3EJY2pB6u1G

struct tag_7gi4MQy35pU3EJY2pB6u1G
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_codertarget_arduinobase_int_T i2cObj;
};

#endif                                 /* struct_tag_7gi4MQy35pU3EJY2pB6u1G */

#ifndef typedef_motorcarrier_blocks_mkrmoto_p_T
#define typedef_motorcarrier_blocks_mkrmoto_p_T

typedef struct tag_7gi4MQy35pU3EJY2pB6u1G motorcarrier_blocks_mkrmoto_p_T;

#endif                             /* typedef_motorcarrier_blocks_mkrmoto_p_T */

#ifndef struct_tag_b5s9DWaQUh2sFO58PNDokH
#define struct_tag_b5s9DWaQUh2sFO58PNDokH

struct tag_b5s9DWaQUh2sFO58PNDokH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_codertarget_arduinobase_int_T i2cObj;
};

#endif                                 /* struct_tag_b5s9DWaQUh2sFO58PNDokH */

#ifndef typedef_motorcarrier_blocks_mkrmot_p0_T
#define typedef_motorcarrier_blocks_mkrmot_p0_T

typedef struct tag_b5s9DWaQUh2sFO58PNDokH motorcarrier_blocks_mkrmot_p0_T;

#endif                             /* typedef_motorcarrier_blocks_mkrmot_p0_T */

#ifndef struct_tag_g1WX34VPn8QzVKQriB4HN
#define struct_tag_g1WX34VPn8QzVKQriB4HN

struct tag_g1WX34VPn8QzVKQriB4HN
{
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_g1WX34VPn8QzVKQriB4HN */

#ifndef typedef_g_matlabshared_ioclient_perip_T
#define typedef_g_matlabshared_ioclient_perip_T

typedef struct tag_g1WX34VPn8QzVKQriB4HN g_matlabshared_ioclient_perip_T;

#endif                             /* typedef_g_matlabshared_ioclient_perip_T */

#ifndef struct_tag_4eDVzK5FiryyCjvjjvrZGB
#define struct_tag_4eDVzK5FiryyCjvjjvrZGB

struct tag_4eDVzK5FiryyCjvjjvrZGB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  g_matlabshared_ioclient_perip_T PWMDriverObj;
};

#endif                                 /* struct_tag_4eDVzK5FiryyCjvjjvrZGB */

#ifndef typedef_codertarget_arduinobase_int_p_T
#define typedef_codertarget_arduinobase_int_p_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_int_p_T;

#endif                             /* typedef_codertarget_arduinobase_int_p_T */

#ifndef struct_tag_Mv9GUUZtpzLk5JKfq427VD
#define struct_tag_Mv9GUUZtpzLk5JKfq427VD

struct tag_Mv9GUUZtpzLk5JKfq427VD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_codertarget_arduinobase_int_T i2cObj;
};

#endif                                 /* struct_tag_Mv9GUUZtpzLk5JKfq427VD */

#ifndef typedef_motorcarrier_blocks_mkrmo_p0g_T
#define typedef_motorcarrier_blocks_mkrmo_p0g_T

typedef struct tag_Mv9GUUZtpzLk5JKfq427VD motorcarrier_blocks_mkrmo_p0g_T;

#endif                             /* typedef_motorcarrier_blocks_mkrmo_p0g_T */

/* Parameters (default storage) */
typedef struct P_hardwareModel_Balance_1_T_ P_hardwareModel_Balance_1_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_hardwareModel_Balance_T RT_MODEL_hardwareModel_Balanc_T;

#endif                         /* RTW_HEADER_hardwareModel_Balance_1_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
