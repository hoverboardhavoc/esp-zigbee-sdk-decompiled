/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> cvc_enhanced_hue_output_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cvc_enhanced_hue_output_handler
               (undefined4 param_1,int param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 auStack_12 [5];
  
  param_2 = param_2 % 0x10000;
  if (param_2 < 0) {
    param_2 = param_2 + 0x10000;
  }
  auStack_12[0] = (undefined2)param_2;
  zcl_message_set_color_control_attr_value_isra_0(param_4,auStack_12);
  color_control_set_remaining_time(param_1,param_3);
  return;
}

