/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hardwareModel_Balance_1.c
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
#include "hardwareModel_Balance_1_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"
#include "hardwareModel_Balance_1_private.h"
#include <stddef.h>

/* Named constants for Chart: '<S1>/Chart' */
#define hardwareMo_IN_batteryNotCharged (2U)
#define hardwareMod_IN_imuNotCalibrated (2U)
#define hardwareModel_Balan_IN_standing (2U)
#define hardwareModel_Balance_IN_fallen (1U)
#define hardwareModel_IN_batteryCharged (1U)
#define hardwareModel_IN_disableControl (1U)
#define hardwareModel__IN_enableControl (2U)
#define hardwareModel__IN_imuCalibrated (1U)

/* Block signals (default storage) */
B_hardwareModel_Balance_1_T hardwareModel_Balance_1_B;

/* Block states (default storage) */
DW_hardwareModel_Balance_1_T hardwareModel_Balance_1_DW;

/* Real-time model */
static RT_MODEL_hardwareModel_Balanc_T hardwareModel_Balance_1_M_;
RT_MODEL_hardwareModel_Balanc_T *const hardwareModel_Balance_1_M =
  &hardwareModel_Balance_1_M_;

/* Forward declaration for local functions */
static void mkrmotorcarrier_ServoMotor_Serv(const
  motorcarrier_blocks_mkrmo_p0g_T *obj, int32_T value);
static void hardwareModel__SystemCore_setup(codertarget_arduinobase_inter_T *obj);
static void hardwareMode_SystemCore_setup_p(motorcarrier_blocks_mkrmoto_p_T *obj);
static void hardwareMod_SystemCore_setup_p0(motorcarrier_blocks_mkrmot_p0_T *obj);
static void hardwareMo_SystemCore_setup_p0g(motorcarrier_blocks_mkrmo_p0g_T *obj);
void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Hi;
  uint32_T in0Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  absIn1 = in1 < 0 ? ~(uint32_T)in1 + 1U : (uint32_T)in1;
  in0Hi = absIn0 >> 16U;
  in0Lo = absIn0 & 65535U;
  in1Hi = absIn1 >> 16U;
  absIn0 = absIn1 & 65535U;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0U;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1U;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    absIn1;
  if ((in0 != 0) && ((in1 != 0) && ((in0 > 0) != (in1 > 0)))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_sat(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  if (((int32_T)u32_chi > 0) || ((u32_chi == 0U) && (u32_clo >= 2147483648U))) {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1) || (((int32_T)u32_chi == -1) && (u32_clo <
               2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void mkrmotorcarrier_ServoMotor_Serv(const
  motorcarrier_blocks_mkrmo_p0g_T *obj, int32_T value)
{
  int32_T x;
  int32_T z;
  uint32_T q;
  uint32_T y;
  uint8_T data_uint8[4];
  x = mul_s32_sat(value, 21);
  if (x >= 0) {
    y = (uint32_T)x;
  } else if (x == MIN_int32_T) {
    y = 2147483648U;
  } else {
    y = (uint32_T)-x;
  }

  q = y / 180U;
  y -= q * 180U;
  if ((y > 0U) && (y >= 90U)) {
    q++;
  }

  z = (int32_T)q;
  if (x < 0) {
    z = -(int32_T)q;
  }

  x = z + 7;
  memcpy((void *)&data_uint8[0], (void *)&x, (size_t)4 * sizeof(uint8_T));
  hardwareModel_Balance_1_B.final_data_to_write[0] = 3U;
  hardwareModel_Balance_1_B.final_data_to_write[1] = 2U;
  hardwareModel_Balance_1_B.final_data_to_write[2] = data_uint8[0];
  hardwareModel_Balance_1_B.final_data_to_write[3] = data_uint8[1];
  hardwareModel_Balance_1_B.final_data_to_write[4] = data_uint8[2];
  hardwareModel_Balance_1_B.final_data_to_write[5] = data_uint8[3];
  memcpy((void *)&hardwareModel_Balance_1_B.SwappedDataBytes_f[0], (void *)
         &hardwareModel_Balance_1_B.final_data_to_write[0], (size_t)6 * sizeof
         (uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &hardwareModel_Balance_1_B.SwappedDataBytes_f[0], 6U, false,
                     false);
}

static void hardwareModel__SystemCore_setup(codertarget_arduinobase_inter_T *obj)
{
  MW_I2C_Mode_Type modename;
  uint32_T i2cname;
  i_codertarget_arduinobase_int_T *obj_0;
  uint32_T varargin_1;
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T CastedData;
  uint8_T SwappedDataBytes_0;
  uint8_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj_0 = &obj->i2cObj;
  modename = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, modename);
  obj->i2cObj.BusSpeed = 100000U;
  varargin_1 = obj->i2cObj.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  MW_delay_in_milliseconds(600U);
  status = 0U;
  memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
         (uint8_T));
  status = MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41U,
    &SwappedDataBytes_0, 1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41U, &status, 1U,
                      false, true);
    memcpy((void *)&CastedData, (void *)&status, (size_t)1 * sizeof(uint8_T));
  } else {
    CastedData = 0U;
  }

  obj->isBNOcorrect = (CastedData == 160);
  if (obj->isBNOcorrect) {
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 61U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41U,
                       &SwappedDataBytes[0], 2U, false, false);
    MW_delay_in_milliseconds(25U);
    CastedData = 32U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 63U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41U,
                       &SwappedDataBytes[0], 2U, false, false);
    status = 0U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41U,
      &SwappedDataBytes_0, 1U, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41U, &status, 1U,
                        false, true);
      memcpy((void *)&CastedData, (void *)&status, (size_t)1 * sizeof(uint8_T));
    } else {
      CastedData = 0U;
    }

    obj->isBNOcorrect = (CastedData == 160);
    while (!obj->isBNOcorrect) {
      MW_delay_in_milliseconds(10U);
      status = 0U;
      memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
             (uint8_T));
      status = MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41U,
        &SwappedDataBytes_0, 1U, true, false);
      if (status == 0) {
        MW_I2C_MasterRead(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41U, &status,
                          1U, false, true);
        memcpy((void *)&CastedData, (void *)&status, (size_t)1 * sizeof(uint8_T));
      } else {
        CastedData = 0U;
      }

      obj->isBNOcorrect = (CastedData == 160);
    }

    MW_delay_in_milliseconds(50U);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 62U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41U,
                       &SwappedDataBytes[0], 2U, false, false);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 63U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41U,
                       &SwappedDataBytes[0], 2U, false, false);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 7U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41U,
                       &SwappedDataBytes[0], 2U, false, false);
    MW_delay_in_milliseconds(10U);
    CastedData = 128U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 59U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41U,
                       &SwappedDataBytes[0], 2U, false, false);
    CastedData = 12U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 61U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41U,
                       &SwappedDataBytes[0], 2U, false, false);
    MW_delay_in_milliseconds(25U);
  }

  obj->isSetupComplete = true;
}

static void hardwareMode_SystemCore_setup_p(motorcarrier_blocks_mkrmoto_p_T *obj)
{
  f_codertarget_arduinobase_int_T *obj_0;
  int32_T x;
  uint32_T varargin_1;
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write[6];
  uint8_T data_uint8[4];
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj_0 = &obj->i2cObj;
  hardwareModel_Balance_1_B.modename_p = MW_I2C_MASTER;
  hardwareModel_Balance_1_B.i2cname_b = 0;
  obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
    (hardwareModel_Balance_1_B.i2cname_b, hardwareModel_Balance_1_B.modename_p);
  obj->i2cObj.BusSpeed = 100000U;
  varargin_1 = obj->i2cObj.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  x = 0;
  memcpy((void *)&data_uint8[0], (void *)&x, (size_t)4 * sizeof(uint8_T));
  final_data_to_write[0] = 8U;
  final_data_to_write[1] = 0U;
  final_data_to_write[2] = data_uint8[0];
  final_data_to_write[3] = data_uint8[1];
  final_data_to_write[4] = data_uint8[2];
  final_data_to_write[5] = data_uint8[3];
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         6 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &SwappedDataBytes[0], 6U, false, false);
  obj->isSetupComplete = true;
}

static void hardwareMod_SystemCore_setup_p0(motorcarrier_blocks_mkrmot_p0_T *obj)
{
  f_codertarget_arduinobase_int_T *obj_0;
  int32_T x;
  uint32_T varargin_1;
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write[6];
  uint8_T data_uint8[4];
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj_0 = &obj->i2cObj;
  hardwareModel_Balance_1_B.modename_cx = MW_I2C_MASTER;
  hardwareModel_Balance_1_B.i2cname_k = 0;
  obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
    (hardwareModel_Balance_1_B.i2cname_k, hardwareModel_Balance_1_B.modename_cx);
  obj->i2cObj.BusSpeed = 100000U;
  varargin_1 = obj->i2cObj.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  x = 100;
  memcpy((void *)&data_uint8[0], (void *)&x, (size_t)4 * sizeof(uint8_T));
  final_data_to_write[0] = 6U;
  final_data_to_write[1] = 1U;
  final_data_to_write[2] = data_uint8[0];
  final_data_to_write[3] = data_uint8[1];
  final_data_to_write[4] = data_uint8[2];
  final_data_to_write[5] = data_uint8[3];
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         6 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &SwappedDataBytes[0], 6U, false, false);
  obj->isSetupComplete = true;
}

static void hardwareMo_SystemCore_setup_p0g(motorcarrier_blocks_mkrmo_p0g_T *obj)
{
  f_codertarget_arduinobase_int_T *obj_0;
  int32_T x;
  uint32_T varargin_1;
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write[6];
  uint8_T data_uint8[4];
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj_0 = &obj->i2cObj;
  hardwareModel_Balance_1_B.modename_c = MW_I2C_MASTER;
  hardwareModel_Balance_1_B.i2cname_m = 0;
  obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
    (hardwareModel_Balance_1_B.i2cname_m, hardwareModel_Balance_1_B.modename_c);
  obj->i2cObj.BusSpeed = 100000U;
  varargin_1 = obj->i2cObj.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  x = 100;
  memcpy((void *)&data_uint8[0], (void *)&x, (size_t)4 * sizeof(uint8_T));
  final_data_to_write[0] = 4U;
  final_data_to_write[1] = 2U;
  final_data_to_write[2] = data_uint8[0];
  final_data_to_write[3] = data_uint8[1];
  final_data_to_write[4] = data_uint8[2];
  final_data_to_write[5] = data_uint8[3];
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         6 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &SwappedDataBytes[0], 6U, false, false);
  obj->isSetupComplete = true;
}

/* Model step function */
void hardwareModel_Balance_1_step(void)
{
  codertarget_arduinobase_int_p_T *obj_0;
  f_codertarget_arduinobase_int_T *obj;
  i_codertarget_arduinobase_int_T *obj_1;
  int16_T rtb_DataTypeConversion;
  int16_T rtb_Switch_idx_0;
  int8_T CalibStatus_data_idx_0;
  int8_T CalibStatus_data_idx_1;
  int8_T CalibStatus_data_idx_2;
  int8_T CalibStatus_data_idx_3;
  uint8_T data_uint8[4];
  uint8_T SwappedDataBytes[2];
  uint8_T final_data_to_write[2];
  uint8_T SwappedDataBytes_0;
  uint8_T b_RegisterValue;
  uint8_T status;

  /* Outputs for Atomic SubSystem: '<S2>/BNO055 IMU  Sensor' */
  /* Outputs for Atomic SubSystem: '<S2>/BNO055 IMU  Sensor' */
  /* MATLABSystem: '<S13>/Base sensor block' */
  if (hardwareModel_Balance_1_DW.obj.SampleTime !=
      hardwareModel_Balance_1_P.BNO055IMUSensor_SampleTime) {
    hardwareModel_Balance_1_DW.obj.SampleTime =
      hardwareModel_Balance_1_P.BNO055IMUSensor_SampleTime;
  }

  /* End of Outputs for SubSystem: '<S2>/BNO055 IMU  Sensor' */
  if (!hardwareModel_Balance_1_DW.obj.IsFirstStep) {
    MW_getCurrentTime_in_milliseconds();
    hardwareModel_Balance_1_DW.obj.IsFirstStep = true;
  }

  obj_1 = &hardwareModel_Balance_1_DW.obj.i2cObj;
  status = 20U;
  memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
         (uint8_T));
  status = MW_I2C_MasterWrite(obj_1->I2CDriverObj.MW_I2C_HANDLE, 41U,
    &SwappedDataBytes_0, 1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj_1->I2CDriverObj.MW_I2C_HANDLE, 41U,
                      &hardwareModel_Balance_1_B.output_raw[0], 6U, false, true);
    memcpy((void *)&hardwareModel_Balance_1_B.b_RegisterValue[0], (void *)
           &hardwareModel_Balance_1_B.output_raw[0], (size_t)3 * sizeof(int16_T));
  } else {
    hardwareModel_Balance_1_B.b_RegisterValue[1] = 0;
  }

  obj_1 = &hardwareModel_Balance_1_DW.obj.i2cObj;
  status = 26U;
  memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
         (uint8_T));
  status = MW_I2C_MasterWrite(obj_1->I2CDriverObj.MW_I2C_HANDLE, 41U,
    &SwappedDataBytes_0, 1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj_1->I2CDriverObj.MW_I2C_HANDLE, 41U,
                      &hardwareModel_Balance_1_B.output_raw[0], 6U, false, true);
    memcpy((void *)&hardwareModel_Balance_1_B.b_RegisterValue_c[0], (void *)
           &hardwareModel_Balance_1_B.output_raw[0], (size_t)3 * sizeof(int16_T));
  } else {
    hardwareModel_Balance_1_B.b_RegisterValue_c[1] = 0;
  }

  if (hardwareModel_Balance_1_DW.obj.isBNOcorrect) {
    obj_1 = &hardwareModel_Balance_1_DW.obj.i2cObj;
    status = 53U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj_1->I2CDriverObj.MW_I2C_HANDLE, 41U,
      &SwappedDataBytes_0, 1U, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj_1->I2CDriverObj.MW_I2C_HANDLE, 41U, &status, 1U,
                        false, true);
      memcpy((void *)&b_RegisterValue, (void *)&status, (size_t)1 * sizeof
             (uint8_T));
    } else {
      b_RegisterValue = 0U;
    }

    CalibStatus_data_idx_0 = (int8_T)((uint32_T)(b_RegisterValue & 192) >> 6);
    CalibStatus_data_idx_1 = (int8_T)((uint32_T)(b_RegisterValue & 48) >> 4);
    CalibStatus_data_idx_2 = (int8_T)((uint32_T)(b_RegisterValue & 12) >> 2);
    CalibStatus_data_idx_3 = (int8_T)(b_RegisterValue & 3);
  } else {
    CalibStatus_data_idx_0 = -1;
    CalibStatus_data_idx_1 = -1;
    CalibStatus_data_idx_2 = -1;
    CalibStatus_data_idx_3 = -1;
  }

  /* End of Outputs for SubSystem: '<S2>/BNO055 IMU  Sensor' */

  /* Constant: '<S1>/userEnable' */
  hardwareModel_Balance_1_B.userEnable =
    hardwareModel_Balance_1_P.userEnable_Value;

  /* Outputs for Atomic SubSystem: '<S2>/BNO055 IMU  Sensor' */
  /* Bias: '<S5>/Bias' incorporates:
   *  Gain: '<S5>/Gain2'
   *  Gain: '<S5>/deg2rad1'
   *  MATLABSystem: '<S13>/Base sensor block'
   */
  hardwareModel_Balance_1_B.theta = (real_T)
    hardwareModel_Balance_1_B.b_RegisterValue_c[1] / 16.0 *
    hardwareModel_Balance_1_P.Gain2_Gain *
    hardwareModel_Balance_1_P.deg2rad1_Gain +
    hardwareModel_Balance_1_P.Bias_Bias;

  /* End of Outputs for SubSystem: '<S2>/BNO055 IMU  Sensor' */

  /* MATLABSystem: '<S2>/Battery Read' */
  if (hardwareModel_Balance_1_DW.obj_j.SampleTime !=
      hardwareModel_Balance_1_P.Ts) {
    hardwareModel_Balance_1_DW.obj_j.SampleTime = hardwareModel_Balance_1_P.Ts;
  }

  obj = &hardwareModel_Balance_1_DW.obj_j.i2cObj;
  final_data_to_write[0] = 13U;
  final_data_to_write[1] = 0U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         2 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U, &SwappedDataBytes[0],
                     2U, false, false);
  obj = &hardwareModel_Balance_1_DW.obj_j.i2cObj;
  MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 102U,
                    &hardwareModel_Balance_1_B.output_raw_g[0], 5U, false, false);
  memcpy((void *)&hardwareModel_Balance_1_B.out_raw[0], (void *)
         &hardwareModel_Balance_1_B.output_raw_g[0], (size_t)5 * sizeof(uint8_T));
  memcpy((void *)&hardwareModel_Balance_1_B.out, (void *)
         &hardwareModel_Balance_1_B.out_raw[1], (size_t)1 * sizeof(uint32_T));
  if (hardwareModel_Balance_1_B.out > 65535U) {
    hardwareModel_Balance_1_B.out = 65535U;
  }

  /* Gain: '<S5>/Gain3' incorporates:
   *  DataTypeConversion: '<S5>/Cast1'
   *  MATLABSystem: '<S2>/Battery Read'
   */
  hardwareModel_Balance_1_B.batteryvoltage =
    hardwareModel_Balance_1_P.Gain3_Gain * (real_T)hardwareModel_Balance_1_B.out;

  /* Outputs for Atomic SubSystem: '<S2>/BNO055 IMU  Sensor' */
  /* Product: '<S5>/Product of Elements' incorporates:
   *  Constant: '<S6>/Constant'
   *  MATLABSystem: '<S13>/Base sensor block'
   *  RelationalOperator: '<S6>/Compare'
   */
  hardwareModel_Balance_1_B.IMUStatus = (uint16_T)(CalibStatus_data_idx_3 >=
    hardwareModel_Balance_1_P.CompareToConstant_const[3] ? (int32_T)(uint16_T)
    (CalibStatus_data_idx_2 >=
     hardwareModel_Balance_1_P.CompareToConstant_const[2] ? (int32_T)(uint16_T)
     (CalibStatus_data_idx_0 >=
      hardwareModel_Balance_1_P.CompareToConstant_const[0] ?
      CalibStatus_data_idx_1 >=
      hardwareModel_Balance_1_P.CompareToConstant_const[1] : 0) : 0) : 0);

  /* End of Outputs for SubSystem: '<S2>/BNO055 IMU  Sensor' */

  /* Chart: '<S1>/Chart' */
  if (hardwareModel_Balance_1_DW.is_active_c3_hardwareModel_Bala == 0U) {
    hardwareModel_Balance_1_DW.is_active_c3_hardwareModel_Bala = 1U;
    hardwareModel_Balance_1_DW.is_active_checkFallen = 1U;
    hardwareModel_Balance_1_DW.is_checkFallen = hardwareModel_Balance_IN_fallen;
    hardwareModel_Balance_1_DW.upright = false;
    hardwareModel_Balance_1_DW.is_active_checkIMUCalib = 1U;
    hardwareModel_Balance_1_DW.is_checkIMUCalib =
      hardwareMod_IN_imuNotCalibrated;
    hardwareModel_Balance_1_DW.IMUCalibrated = false;
    hardwareModel_Balance_1_DW.is_active_checkBattery = 1U;
    hardwareModel_Balance_1_DW.is_checkBattery = hardwareMo_IN_batteryNotCharged;
    hardwareModel_Balance_1_DW.batteryOK = false;
    hardwareModel_Balance_1_DW.is_active_calculateEnable = 1U;
    hardwareModel_Balance_1_DW.is_calculateEnable =
      hardwareModel_IN_disableControl;
    hardwareModel_Balance_1_B.enable = false;
  } else {
    if (hardwareModel_Balance_1_DW.is_checkFallen ==
        hardwareModel_Balance_IN_fallen) {
      if (fabs(hardwareModel_Balance_1_B.theta) < 0.20943951023931953) {
        hardwareModel_Balance_1_DW.is_checkFallen =
          hardwareModel_Balan_IN_standing;
        hardwareModel_Balance_1_DW.upright = true;
      }

      /* case IN_standing: */
    } else if (fabs(hardwareModel_Balance_1_B.theta) > 0.20943951023931953) {
      hardwareModel_Balance_1_DW.is_checkFallen =
        hardwareModel_Balance_IN_fallen;
      hardwareModel_Balance_1_DW.upright = false;
    }

    switch (hardwareModel_Balance_1_DW.is_checkIMUCalib) {
     case hardwareModel__IN_imuCalibrated:
      break;

     default:
      /* case IN_imuNotCalibrated: */
      if (hardwareModel_Balance_1_B.IMUStatus == 1) {
        hardwareModel_Balance_1_DW.is_checkIMUCalib =
          hardwareModel__IN_imuCalibrated;
        hardwareModel_Balance_1_DW.IMUCalibrated = true;
      }
      break;
    }

    if (hardwareModel_Balance_1_DW.is_checkBattery ==
        hardwareModel_IN_batteryCharged) {
      if (hardwareModel_Balance_1_B.batteryvoltage < 3.0) {
        hardwareModel_Balance_1_DW.is_checkBattery =
          hardwareMo_IN_batteryNotCharged;
        hardwareModel_Balance_1_DW.batteryOK = false;
      }

      /* case IN_batteryNotCharged: */
    } else if (hardwareModel_Balance_1_B.batteryvoltage >= 3.0) {
      hardwareModel_Balance_1_DW.is_checkBattery =
        hardwareModel_IN_batteryCharged;
      hardwareModel_Balance_1_DW.batteryOK = true;
    }

    if (hardwareModel_Balance_1_DW.is_calculateEnable ==
        hardwareModel_IN_disableControl) {
      hardwareModel_Balance_1_B.enable = false;
      if ((hardwareModel_Balance_1_B.userEnable != 0.0) &&
          hardwareModel_Balance_1_DW.batteryOK &&
          hardwareModel_Balance_1_DW.IMUCalibrated &&
          hardwareModel_Balance_1_DW.upright) {
        hardwareModel_Balance_1_DW.is_calculateEnable =
          hardwareModel__IN_enableControl;
        hardwareModel_Balance_1_B.enable = true;
      }
    } else {
      /* case IN_enableControl: */
      hardwareModel_Balance_1_B.enable = true;
      if ((!(hardwareModel_Balance_1_B.userEnable != 0.0)) ||
          (!hardwareModel_Balance_1_DW.batteryOK) ||
          (!hardwareModel_Balance_1_DW.IMUCalibrated) ||
          (!hardwareModel_Balance_1_DW.upright)) {
        hardwareModel_Balance_1_DW.is_calculateEnable =
          hardwareModel_IN_disableControl;
        hardwareModel_Balance_1_B.enable = false;
      }
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* Gain: '<S4>/Kp' */
  hardwareModel_Balance_1_B.pTerm = hardwareModel_Balance_1_P.Kp_Gain *
    hardwareModel_Balance_1_B.theta;

  /* Outputs for Atomic SubSystem: '<S2>/BNO055 IMU  Sensor' */
  /* Gain: '<S4>/Kd' incorporates:
   *  Gain: '<S5>/deg2rad'
   *  MATLABSystem: '<S13>/Base sensor block'
   */
  hardwareModel_Balance_1_B.dTerm = (real_T)
    hardwareModel_Balance_1_B.b_RegisterValue[1] / 16.0 *
    hardwareModel_Balance_1_P.deg2rad_Gain * hardwareModel_Balance_1_P.Kd_Gain;

  /* End of Outputs for SubSystem: '<S2>/BNO055 IMU  Sensor' */

  /* Gain: '<S8>/Minimum sampling to time constant ratio' */
  hardwareModel_Balance_1_B.Integrator =
    hardwareModel_Balance_1_P.FilteredDerivative1_minRatio *
    hardwareModel_Balance_1_B.Probe[0];

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Constant: '<S8>/Time constant'
   */
  if ((!(hardwareModel_Balance_1_B.Integrator >=
         hardwareModel_Balance_1_P.FilteredDerivative1_T)) && (!rtIsNaN
       (hardwareModel_Balance_1_P.FilteredDerivative1_T))) {
    hardwareModel_Balance_1_B.Integrator =
      hardwareModel_Balance_1_P.FilteredDerivative1_T;
  }

  /* End of MinMax: '<S8>/MinMax' */

  /* MATLABSystem: '<S2>/Iniertia Wheel' */
  final_data_to_write[0] = 7U;
  final_data_to_write[1] = 0U;
  obj = &hardwareModel_Balance_1_DW.obj_m.i2cObj;
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         2 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U, &SwappedDataBytes[0],
                     2U, false, false);
  obj = &hardwareModel_Balance_1_DW.obj_m.i2cObj;
  MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 102U,
                    &hardwareModel_Balance_1_B.output_raw_g[0], 5U, false, false);
  memcpy((void *)&hardwareModel_Balance_1_B.out_raw[0], (void *)
         &hardwareModel_Balance_1_B.output_raw_g[0], (size_t)5 * sizeof(uint8_T));
  memcpy((void *)&hardwareModel_Balance_1_B.count, (void *)
         &hardwareModel_Balance_1_B.out_raw[1], (size_t)1 * sizeof(int32_T));

  /* Gain: '<S5>/Gain4' incorporates:
   *  DataTypeConversion: '<S5>/Cast'
   *  Gain: '<S5>/Gain1'
   *  MATLABSystem: '<S2>/Iniertia Wheel'
   */
  hardwareModel_Balance_1_B.rads = hardwareModel_Balance_1_P.Gain1_Gain *
    (real_T)hardwareModel_Balance_1_B.count *
    hardwareModel_Balance_1_P.Gain4_Gain;

  /* DiscreteIntegrator: '<S12>/Integrator' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (hardwareModel_Balance_1_DW.Integrator_IC_LOADING != 0) {
    hardwareModel_Balance_1_DW.Integrator_DSTATE =
      hardwareModel_Balance_1_B.rads;
    if (hardwareModel_Balance_1_DW.Integrator_DSTATE >=
        hardwareModel_Balance_1_P.Integrator_UpperSat) {
      hardwareModel_Balance_1_DW.Integrator_DSTATE =
        hardwareModel_Balance_1_P.Integrator_UpperSat;
    } else if (hardwareModel_Balance_1_DW.Integrator_DSTATE <=
               hardwareModel_Balance_1_P.Integrator_LowerSat) {
      hardwareModel_Balance_1_DW.Integrator_DSTATE =
        hardwareModel_Balance_1_P.Integrator_LowerSat;
    }
  }

  if ((hardwareModel_Balance_1_P.Constant_Value != 0.0) ||
      (hardwareModel_Balance_1_DW.Integrator_PrevResetState != 0)) {
    hardwareModel_Balance_1_DW.Integrator_DSTATE =
      hardwareModel_Balance_1_B.rads;
    if (hardwareModel_Balance_1_DW.Integrator_DSTATE >=
        hardwareModel_Balance_1_P.Integrator_UpperSat) {
      hardwareModel_Balance_1_DW.Integrator_DSTATE =
        hardwareModel_Balance_1_P.Integrator_UpperSat;
    } else if (hardwareModel_Balance_1_DW.Integrator_DSTATE <=
               hardwareModel_Balance_1_P.Integrator_LowerSat) {
      hardwareModel_Balance_1_DW.Integrator_DSTATE =
        hardwareModel_Balance_1_P.Integrator_LowerSat;
    }
  }

  if (hardwareModel_Balance_1_DW.Integrator_DSTATE >=
      hardwareModel_Balance_1_P.Integrator_UpperSat) {
    hardwareModel_Balance_1_DW.Integrator_DSTATE =
      hardwareModel_Balance_1_P.Integrator_UpperSat;
  } else if (hardwareModel_Balance_1_DW.Integrator_DSTATE <=
             hardwareModel_Balance_1_P.Integrator_LowerSat) {
    hardwareModel_Balance_1_DW.Integrator_DSTATE =
      hardwareModel_Balance_1_P.Integrator_LowerSat;
  }

  /* Saturate: '<S12>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S12>/Integrator'
   */
  if (hardwareModel_Balance_1_DW.Integrator_DSTATE >
      hardwareModel_Balance_1_P.Saturation_UpperSat) {
    hardwareModel_Balance_1_B.Gain1 =
      hardwareModel_Balance_1_P.Saturation_UpperSat;
  } else if (hardwareModel_Balance_1_DW.Integrator_DSTATE <
             hardwareModel_Balance_1_P.Saturation_LowerSat) {
    hardwareModel_Balance_1_B.Gain1 =
      hardwareModel_Balance_1_P.Saturation_LowerSat;
  } else {
    hardwareModel_Balance_1_B.Gain1 =
      hardwareModel_Balance_1_DW.Integrator_DSTATE;
  }

  /* Product: '<S7>/1//T' incorporates:
   *  Fcn: '<S8>/Avoid Divide by Zero'
   *  Saturate: '<S12>/Saturation'
   *  Sum: '<S7>/Sum1'
   */
  hardwareModel_Balance_1_B.Integrator = 1.0 / ((real_T)
    (hardwareModel_Balance_1_B.Integrator == 0.0) * 2.2204460492503131e-16 +
    hardwareModel_Balance_1_B.Integrator) * (hardwareModel_Balance_1_B.rads -
    hardwareModel_Balance_1_B.Gain1);

  /* Gain: '<S7>/Gain' */
  hardwareModel_Balance_1_B.Gain1 =
    hardwareModel_Balance_1_P.FilteredDerivative1_K *
    hardwareModel_Balance_1_B.Integrator;

  /* Saturate: '<S7>/[A,B]' */
  if (hardwareModel_Balance_1_B.Gain1 >
      hardwareModel_Balance_1_P.FilteredDerivative1_B) {
    hardwareModel_Balance_1_B.Gain1 =
      hardwareModel_Balance_1_P.FilteredDerivative1_B;
  } else if (hardwareModel_Balance_1_B.Gain1 <
             hardwareModel_Balance_1_P.FilteredDerivative1_A) {
    hardwareModel_Balance_1_B.Gain1 =
      hardwareModel_Balance_1_P.FilteredDerivative1_A;
  }

  /* Gain: '<S4>/Kpw' incorporates:
   *  Saturate: '<S7>/[A,B]'
   */
  hardwareModel_Balance_1_B.pTermW = hardwareModel_Balance_1_P.Kpw_Gain *
    hardwareModel_Balance_1_B.Gain1;

  /* Sum: '<S4>/Add' */
  hardwareModel_Balance_1_B.Add = (hardwareModel_Balance_1_B.pTerm +
    hardwareModel_Balance_1_B.dTerm) + hardwareModel_Balance_1_B.pTermW;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/whenDisabled'
   */
  if (hardwareModel_Balance_1_B.enable) {
    hardwareModel_Balance_1_B.Gain1 = hardwareModel_Balance_1_B.Add;
  } else {
    hardwareModel_Balance_1_B.Gain1 =
      hardwareModel_Balance_1_P.whenDisabled_Value;
  }

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Switch: '<S1>/Switch'
   */
  if (hardwareModel_Balance_1_B.Gain1 >
      hardwareModel_Balance_1_P.Saturation_UpperSat_m) {
    hardwareModel_Balance_1_B.Gain1 =
      hardwareModel_Balance_1_P.Saturation_UpperSat_m;
  } else if (hardwareModel_Balance_1_B.Gain1 <
             hardwareModel_Balance_1_P.Saturation_LowerSat_h) {
    hardwareModel_Balance_1_B.Gain1 =
      hardwareModel_Balance_1_P.Saturation_LowerSat_h;
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion' incorporates:
   *  Gain: '<S2>/Gain'
   *  Saturate: '<S2>/Saturation'
   */
  hardwareModel_Balance_1_B.Gain1 = floor(hardwareModel_Balance_1_P.Gain_Gain *
    hardwareModel_Balance_1_B.Gain1);
  if (rtIsNaN(hardwareModel_Balance_1_B.Gain1) || rtIsInf
      (hardwareModel_Balance_1_B.Gain1)) {
    hardwareModel_Balance_1_B.Gain1 = 0.0;
  } else {
    hardwareModel_Balance_1_B.Gain1 = fmod(hardwareModel_Balance_1_B.Gain1,
      65536.0);
  }

  rtb_DataTypeConversion = (int16_T)(hardwareModel_Balance_1_B.Gain1 < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-hardwareModel_Balance_1_B.Gain1 :
    (int32_T)(int16_T)(uint16_T)hardwareModel_Balance_1_B.Gain1);

  /* End of DataTypeConversion: '<S14>/Data Type Conversion' */

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Constant1'
   */
  if (rtb_DataTypeConversion > hardwareModel_Balance_1_P.Switch_Threshold) {
    rtb_Switch_idx_0 = rtb_DataTypeConversion;
    rtb_DataTypeConversion = hardwareModel_Balance_1_P.Constant1_Value_c;
  } else {
    rtb_Switch_idx_0 = hardwareModel_Balance_1_P.Constant1_Value_c;

    /* Abs: '<S14>/Abs' incorporates:
     *  Constant: '<S14>/Constant1'
     */
    if (rtb_DataTypeConversion < 0) {
      rtb_DataTypeConversion = (int16_T)-rtb_DataTypeConversion;
    }

    /* End of Abs: '<S14>/Abs' */
  }

  /* End of Switch: '<S14>/Switch' */

  /* MATLABSystem: '<S14>/Forward PWM' */
  obj_0 = &hardwareModel_Balance_1_DW.obj_mh;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3U);
  if (rtb_Switch_idx_0 <= 255.0) {
    hardwareModel_Balance_1_B.Gain1 = rtb_Switch_idx_0;
  } else {
    hardwareModel_Balance_1_B.Gain1 = 255.0;
  }

  if (!(hardwareModel_Balance_1_B.Gain1 >= 0.0)) {
    hardwareModel_Balance_1_B.Gain1 = 0.0;
  }

  MW_PWM_SetDutyCycle
    (hardwareModel_Balance_1_DW.obj_mh.PWMDriverObj.MW_PWM_HANDLE,
     hardwareModel_Balance_1_B.Gain1);

  /* End of MATLABSystem: '<S14>/Forward PWM' */

  /* MATLABSystem: '<S14>/Reverse PWM' */
  obj_0 = &hardwareModel_Balance_1_DW.obj_i;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
  if (rtb_DataTypeConversion <= 255.0) {
    hardwareModel_Balance_1_B.Gain1 = rtb_DataTypeConversion;
  } else {
    hardwareModel_Balance_1_B.Gain1 = 255.0;
  }

  if (!(hardwareModel_Balance_1_B.Gain1 >= 0.0)) {
    hardwareModel_Balance_1_B.Gain1 = 0.0;
  }

  MW_PWM_SetDutyCycle
    (hardwareModel_Balance_1_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE,
     hardwareModel_Balance_1_B.Gain1);

  /* End of MATLABSystem: '<S14>/Reverse PWM' */
  /* Saturate: '<S2>/Saturation1' incorporates:
   *  Constant: '<S2>/Constant'
   */
  if (hardwareModel_Balance_1_P.Constant_Value_d >
      hardwareModel_Balance_1_P.Saturation1_UpperSat) {
    hardwareModel_Balance_1_B.Gain1 =
      hardwareModel_Balance_1_P.Saturation1_UpperSat;
  } else if (hardwareModel_Balance_1_P.Constant_Value_d <
             hardwareModel_Balance_1_P.Saturation1_LowerSat) {
    hardwareModel_Balance_1_B.Gain1 =
      hardwareModel_Balance_1_P.Saturation1_LowerSat;
  } else {
    hardwareModel_Balance_1_B.Gain1 = hardwareModel_Balance_1_P.Constant_Value_d;
  }

  /* Gain: '<S2>/Gain1' incorporates:
   *  Saturate: '<S2>/Saturation1'
   */
  hardwareModel_Balance_1_B.Gain1 *= hardwareModel_Balance_1_P.Gain1_Gain_g;

  /* MATLABSystem: '<S2>/M1 M2 DC Motors' */
  if (hardwareModel_Balance_1_B.Gain1 > 100.0) {
    hardwareModel_Balance_1_B.count = 100;
  } else if (hardwareModel_Balance_1_B.Gain1 < -100.0) {
    hardwareModel_Balance_1_B.count = -100;
  } else {
    hardwareModel_Balance_1_B.Gain1 = rt_roundd_snf
      (hardwareModel_Balance_1_B.Gain1);
    if (hardwareModel_Balance_1_B.Gain1 < 2.147483648E+9) {
      hardwareModel_Balance_1_B.count = (int32_T)hardwareModel_Balance_1_B.Gain1;
    } else {
      hardwareModel_Balance_1_B.count = MAX_int32_T;
    }
  }

  memcpy((void *)&data_uint8[0], (void *)&hardwareModel_Balance_1_B.count,
         (size_t)4 * sizeof(uint8_T));
  hardwareModel_Balance_1_B.output_raw[0] = 5U;
  hardwareModel_Balance_1_B.output_raw[1] = 1U;
  hardwareModel_Balance_1_B.output_raw[2] = data_uint8[0];
  hardwareModel_Balance_1_B.output_raw[3] = data_uint8[1];
  hardwareModel_Balance_1_B.output_raw[4] = data_uint8[2];
  hardwareModel_Balance_1_B.output_raw[5] = data_uint8[3];
  obj = &hardwareModel_Balance_1_DW.obj_d.i2cObj;
  memcpy((void *)&hardwareModel_Balance_1_B.SwappedDataBytes[0], (void *)
         &hardwareModel_Balance_1_B.output_raw[0], (size_t)6 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &hardwareModel_Balance_1_B.SwappedDataBytes[0], 6U, false,
                     false);

  /* End of MATLABSystem: '<S2>/M1 M2 DC Motors' */

  /* MATLABSystem: '<S2>/Servo Write' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  hardwareModel_Balance_1_B.Gain1 = rt_roundd_snf
    (hardwareModel_Balance_1_P.Constant1_Value);
  if (hardwareModel_Balance_1_B.Gain1 < 2.147483648E+9) {
    if (hardwareModel_Balance_1_B.Gain1 >= -2.147483648E+9) {
      hardwareModel_Balance_1_B.count = (int32_T)hardwareModel_Balance_1_B.Gain1;
    } else {
      hardwareModel_Balance_1_B.count = MIN_int32_T;
    }
  } else {
    hardwareModel_Balance_1_B.count = MAX_int32_T;
  }

  mkrmotorcarrier_ServoMotor_Serv(&hardwareModel_Balance_1_DW.obj_n,
    hardwareModel_Balance_1_B.count);

  /* End of MATLABSystem: '<S2>/Servo Write' */

  /* Update for DiscreteIntegrator: '<S12>/Integrator' incorporates:
   *  Constant: '<S7>/Constant'
   */
  hardwareModel_Balance_1_DW.Integrator_IC_LOADING = 0U;
  hardwareModel_Balance_1_DW.Integrator_DSTATE +=
    hardwareModel_Balance_1_P.Integrator_gainval *
    hardwareModel_Balance_1_B.Integrator;
  if (hardwareModel_Balance_1_DW.Integrator_DSTATE >=
      hardwareModel_Balance_1_P.Integrator_UpperSat) {
    hardwareModel_Balance_1_DW.Integrator_DSTATE =
      hardwareModel_Balance_1_P.Integrator_UpperSat;
  } else if (hardwareModel_Balance_1_DW.Integrator_DSTATE <=
             hardwareModel_Balance_1_P.Integrator_LowerSat) {
    hardwareModel_Balance_1_DW.Integrator_DSTATE =
      hardwareModel_Balance_1_P.Integrator_LowerSat;
  }

  if (hardwareModel_Balance_1_P.Constant_Value > 0.0) {
    hardwareModel_Balance_1_DW.Integrator_PrevResetState = 1;
  } else if (hardwareModel_Balance_1_P.Constant_Value < 0.0) {
    hardwareModel_Balance_1_DW.Integrator_PrevResetState = -1;
  } else if (hardwareModel_Balance_1_P.Constant_Value == 0.0) {
    hardwareModel_Balance_1_DW.Integrator_PrevResetState = 0;
  } else {
    hardwareModel_Balance_1_DW.Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S12>/Integrator' */
  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  hardwareModel_Balance_1_M->Timing.taskTime0 =
    ((time_T)(++hardwareModel_Balance_1_M->Timing.clockTick0)) *
    hardwareModel_Balance_1_M->Timing.stepSize0;
}

/* Model initialize function */
void hardwareModel_Balance_1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  hardwareModel_Balance_1_P.FilteredDerivative1_A = rtMinusInf;
  hardwareModel_Balance_1_P.FilteredDerivative1_B = rtInf;
  hardwareModel_Balance_1_P.Integrator_UpperSat = rtInf;
  hardwareModel_Balance_1_P.Integrator_LowerSat = rtMinusInf;
  hardwareModel_Balance_1_P.Saturation_UpperSat = rtInf;
  hardwareModel_Balance_1_P.Saturation_LowerSat = rtMinusInf;
  rtmSetTFinal(hardwareModel_Balance_1_M, -1);
  hardwareModel_Balance_1_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  hardwareModel_Balance_1_M->Sizes.checksums[0] = (1237671508U);
  hardwareModel_Balance_1_M->Sizes.checksums[1] = (3599868700U);
  hardwareModel_Balance_1_M->Sizes.checksums[2] = (3083792735U);
  hardwareModel_Balance_1_M->Sizes.checksums[3] = (100904194U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    hardwareModel_Balance_1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(hardwareModel_Balance_1_M->extModeInfo,
      &hardwareModel_Balance_1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(hardwareModel_Balance_1_M->extModeInfo,
                        hardwareModel_Balance_1_M->Sizes.checksums);
    rteiSetTPtr(hardwareModel_Balance_1_M->extModeInfo, rtmGetTPtr
                (hardwareModel_Balance_1_M));
  }

  {
    codertarget_arduinobase_int_p_T *obj_0;
    f_codertarget_arduinobase_int_T *obj;
    i_codertarget_arduinobase_int_T *obj_1;
    uint32_T varargin_1;

    /* Start for Probe: '<S8>/Probe' */
    hardwareModel_Balance_1_B.Probe[0] = 0.01;
    hardwareModel_Balance_1_B.Probe[1] = 0.0;

    /* Start for Constant: '<S1>/userEnable' */
    hardwareModel_Balance_1_B.userEnable =
      hardwareModel_Balance_1_P.userEnable_Value;

    /* InitializeConditions for DiscreteIntegrator: '<S12>/Integrator' */
    hardwareModel_Balance_1_DW.Integrator_IC_LOADING = 1U;

    /* SystemInitialize for Atomic SubSystem: '<S2>/BNO055 IMU  Sensor' */
    /* Start for MATLABSystem: '<S13>/Base sensor block' */
    hardwareModel_Balance_1_DW.obj.isInitialized = 0;
    hardwareModel_Balance_1_DW.obj.IsFirstStep = false;
    obj_1 = &hardwareModel_Balance_1_DW.obj.i2cObj;
    hardwareModel_Balance_1_DW.obj.i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
    hardwareModel_Balance_1_DW.obj.i2cObj.isInitialized = 0;
    obj_1->I2CDriverObj.MW_I2C_HANDLE = NULL;
    hardwareModel_Balance_1_DW.obj.i2cObj.matlabCodegenIsDeleted = false;
    hardwareModel_Balance_1_DW.obj.matlabCodegenIsDeleted = false;

    /* Start for Atomic SubSystem: '<S2>/BNO055 IMU  Sensor' */
    hardwareModel_Balance_1_DW.obj.SampleTime =
      hardwareModel_Balance_1_P.BNO055IMUSensor_SampleTime;

    /* End of Start for SubSystem: '<S2>/BNO055 IMU  Sensor' */
    hardwareModel__SystemCore_setup(&hardwareModel_Balance_1_DW.obj);

    /* End of SystemInitialize for SubSystem: '<S2>/BNO055 IMU  Sensor' */

    /* Start for MATLABSystem: '<S2>/Battery Read' */
    obj = &hardwareModel_Balance_1_DW.obj_j.i2cObj;
    hardwareModel_Balance_1_DW.obj_j.i2cObj.DefaultMaximumBusSpeedInHz =
      400000.0;
    hardwareModel_Balance_1_DW.obj_j.i2cObj.isInitialized = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    hardwareModel_Balance_1_DW.obj_j.i2cObj.matlabCodegenIsDeleted = false;
    hardwareModel_Balance_1_DW.obj_j.matlabCodegenIsDeleted = false;
    hardwareModel_Balance_1_DW.obj_j.SampleTime = hardwareModel_Balance_1_P.Ts;
    hardwareModel_Balance_1_DW.obj_j.isSetupComplete = false;
    hardwareModel_Balance_1_DW.obj_j.isInitialized = 1;
    obj = &hardwareModel_Balance_1_DW.obj_j.i2cObj;
    hardwareModel_Balance_1_B.modename = MW_I2C_MASTER;
    hardwareModel_Balance_1_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (hardwareModel_Balance_1_B.i2cname, hardwareModel_Balance_1_B.modename);
    hardwareModel_Balance_1_DW.obj_j.i2cObj.BusSpeed = 100000U;
    varargin_1 = hardwareModel_Balance_1_DW.obj_j.i2cObj.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    hardwareModel_Balance_1_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Iniertia Wheel' */
    hardwareModel_Balance_1_DW.obj_m.isInitialized = 0;
    obj = &hardwareModel_Balance_1_DW.obj_m.i2cObj;
    hardwareModel_Balance_1_DW.obj_m.i2cObj.DefaultMaximumBusSpeedInHz =
      400000.0;
    hardwareModel_Balance_1_DW.obj_m.i2cObj.isInitialized = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    hardwareModel_Balance_1_DW.obj_m.i2cObj.matlabCodegenIsDeleted = false;
    hardwareModel_Balance_1_DW.obj_m.matlabCodegenIsDeleted = false;
    hardwareMode_SystemCore_setup_p(&hardwareModel_Balance_1_DW.obj_m);

    /* Start for MATLABSystem: '<S14>/Forward PWM' */
    hardwareModel_Balance_1_DW.obj_mh.matlabCodegenIsDeleted = false;
    obj_0 = &hardwareModel_Balance_1_DW.obj_mh;
    hardwareModel_Balance_1_DW.obj_mh.isInitialized = 1;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(3U, 0.0, 0.0);
    hardwareModel_Balance_1_DW.obj_mh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S14>/Reverse PWM' */
    hardwareModel_Balance_1_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &hardwareModel_Balance_1_DW.obj_i;
    hardwareModel_Balance_1_DW.obj_i.isInitialized = 1;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(2U, 0.0, 0.0);
    hardwareModel_Balance_1_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/M1 M2 DC Motors' */
    hardwareModel_Balance_1_DW.obj_d.isInitialized = 0;
    obj = &hardwareModel_Balance_1_DW.obj_d.i2cObj;
    hardwareModel_Balance_1_DW.obj_d.i2cObj.DefaultMaximumBusSpeedInHz =
      400000.0;
    hardwareModel_Balance_1_DW.obj_d.i2cObj.isInitialized = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    hardwareModel_Balance_1_DW.obj_d.i2cObj.matlabCodegenIsDeleted = false;
    hardwareModel_Balance_1_DW.obj_d.matlabCodegenIsDeleted = false;
    hardwareMod_SystemCore_setup_p0(&hardwareModel_Balance_1_DW.obj_d);

    /* Start for MATLABSystem: '<S2>/Servo Write' */
    hardwareModel_Balance_1_DW.obj_n.isInitialized = 0;
    obj = &hardwareModel_Balance_1_DW.obj_n.i2cObj;
    hardwareModel_Balance_1_DW.obj_n.i2cObj.DefaultMaximumBusSpeedInHz =
      400000.0;
    hardwareModel_Balance_1_DW.obj_n.i2cObj.isInitialized = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    hardwareModel_Balance_1_DW.obj_n.i2cObj.matlabCodegenIsDeleted = false;
    hardwareModel_Balance_1_DW.obj_n.matlabCodegenIsDeleted = false;
    hardwareMo_SystemCore_setup_p0g(&hardwareModel_Balance_1_DW.obj_n);
  }
}

/* Model terminate function */
void hardwareModel_Balance_1_terminate(void)
{
  codertarget_arduinobase_int_p_T *obj_0;
  f_codertarget_arduinobase_int_T *obj;
  i_codertarget_arduinobase_int_T *obj_1;
  int32_T value;
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write[6];
  uint8_T data_uint8[4];

  /* Terminate for Atomic SubSystem: '<S2>/BNO055 IMU  Sensor' */
  /* Terminate for MATLABSystem: '<S13>/Base sensor block' */
  if (!hardwareModel_Balance_1_DW.obj.matlabCodegenIsDeleted) {
    hardwareModel_Balance_1_DW.obj.matlabCodegenIsDeleted = true;
    if ((hardwareModel_Balance_1_DW.obj.isInitialized == 1) &&
        hardwareModel_Balance_1_DW.obj.isSetupComplete) {
      obj_1 = &hardwareModel_Balance_1_DW.obj.i2cObj;
      MW_I2C_Close(obj_1->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj_1 = &hardwareModel_Balance_1_DW.obj.i2cObj;
  if (!obj_1->matlabCodegenIsDeleted) {
    obj_1->matlabCodegenIsDeleted = true;
    if (obj_1->isInitialized == 1) {
      obj_1->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/Base sensor block' */
  /* End of Terminate for SubSystem: '<S2>/BNO055 IMU  Sensor' */

  /* Terminate for MATLABSystem: '<S2>/Battery Read' */
  if (!hardwareModel_Balance_1_DW.obj_j.matlabCodegenIsDeleted) {
    hardwareModel_Balance_1_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((hardwareModel_Balance_1_DW.obj_j.isInitialized == 1) &&
        hardwareModel_Balance_1_DW.obj_j.isSetupComplete) {
      obj = &hardwareModel_Balance_1_DW.obj_j.i2cObj;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &hardwareModel_Balance_1_DW.obj_j.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Battery Read' */

  /* Terminate for MATLABSystem: '<S2>/Iniertia Wheel' */
  if (!hardwareModel_Balance_1_DW.obj_m.matlabCodegenIsDeleted) {
    hardwareModel_Balance_1_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((hardwareModel_Balance_1_DW.obj_m.isInitialized == 1) &&
        hardwareModel_Balance_1_DW.obj_m.isSetupComplete) {
      obj = &hardwareModel_Balance_1_DW.obj_m.i2cObj;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &hardwareModel_Balance_1_DW.obj_m.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Iniertia Wheel' */

  /* Terminate for MATLABSystem: '<S14>/Forward PWM' */
  obj_0 = &hardwareModel_Balance_1_DW.obj_mh;
  if (!hardwareModel_Balance_1_DW.obj_mh.matlabCodegenIsDeleted) {
    hardwareModel_Balance_1_DW.obj_mh.matlabCodegenIsDeleted = true;
    if ((hardwareModel_Balance_1_DW.obj_mh.isInitialized == 1) &&
        hardwareModel_Balance_1_DW.obj_mh.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3U);
      MW_PWM_SetDutyCycle
        (hardwareModel_Balance_1_DW.obj_mh.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3U);
      MW_PWM_Close(hardwareModel_Balance_1_DW.obj_mh.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S14>/Forward PWM' */

  /* Terminate for MATLABSystem: '<S14>/Reverse PWM' */
  obj_0 = &hardwareModel_Balance_1_DW.obj_i;
  if (!hardwareModel_Balance_1_DW.obj_i.matlabCodegenIsDeleted) {
    hardwareModel_Balance_1_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((hardwareModel_Balance_1_DW.obj_i.isInitialized == 1) &&
        hardwareModel_Balance_1_DW.obj_i.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_SetDutyCycle
        (hardwareModel_Balance_1_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_Close(hardwareModel_Balance_1_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S14>/Reverse PWM' */
  /* Terminate for MATLABSystem: '<S2>/M1 M2 DC Motors' */
  if (!hardwareModel_Balance_1_DW.obj_d.matlabCodegenIsDeleted) {
    hardwareModel_Balance_1_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((hardwareModel_Balance_1_DW.obj_d.isInitialized == 1) &&
        hardwareModel_Balance_1_DW.obj_d.isSetupComplete) {
      value = 0;
      memcpy((void *)&data_uint8[0], (void *)&value, (size_t)4 * sizeof(uint8_T));
      final_data_to_write[0] = 5U;
      final_data_to_write[1] = 1U;
      final_data_to_write[2] = data_uint8[0];
      final_data_to_write[3] = data_uint8[1];
      final_data_to_write[4] = data_uint8[2];
      final_data_to_write[5] = data_uint8[3];
      obj = &hardwareModel_Balance_1_DW.obj_d.i2cObj;
      memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0],
             (size_t)6 * sizeof(uint8_T));
      MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U,
                         &SwappedDataBytes[0], 6U, false, false);
    }
  }

  obj = &hardwareModel_Balance_1_DW.obj_d.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/M1 M2 DC Motors' */

  /* Terminate for MATLABSystem: '<S2>/Servo Write' */
  if (!hardwareModel_Balance_1_DW.obj_n.matlabCodegenIsDeleted) {
    hardwareModel_Balance_1_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((hardwareModel_Balance_1_DW.obj_n.isInitialized == 1) &&
        hardwareModel_Balance_1_DW.obj_n.isSetupComplete) {
      mkrmotorcarrier_ServoMotor_Serv(&hardwareModel_Balance_1_DW.obj_n, 0);
      obj = &hardwareModel_Balance_1_DW.obj_n.i2cObj;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &hardwareModel_Balance_1_DW.obj_n.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Servo Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
