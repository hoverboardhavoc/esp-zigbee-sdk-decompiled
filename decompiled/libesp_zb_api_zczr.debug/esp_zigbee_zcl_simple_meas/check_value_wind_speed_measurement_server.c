/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_simple_meas.o -> check_value_wind_speed_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void check_value_wind_speed_measurement_server
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  check_value_simple_u16_meas_server(0x40b,param_1,param_2,param_3,&WIND_SPEED_meas_limits_0);
  return;
}

