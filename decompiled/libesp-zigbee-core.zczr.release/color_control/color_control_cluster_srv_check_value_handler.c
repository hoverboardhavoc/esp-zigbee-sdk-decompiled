/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> color_control_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool color_control_cluster_srv_check_value_handler(uint param_1,undefined4 param_2,ushort *param_3)

{
  bool bVar1;
  ushort uStack_14;
  ushort auStack_12 [5];
  
  if (param_1 < 5) {
    if (param_1 < 3) {
      bVar1 = false;
      if (param_1 != 2) {
        bVar1 = (byte)*param_3 == 0xff;
      }
    }
    else {
      bVar1 = 0xfeff < *param_3;
    }
  }
  else {
    if (param_1 == 8) {
      bVar1 = (byte)*param_3 < 3;
    }
    else {
      if (param_1 != 0x400a) {
        if (param_1 != 7) {
          return false;
        }
        color_control_get_color_temperature_range_part_0(param_2,&uStack_14,auStack_12);
        if (*param_3 < uStack_14) {
          return true;
        }
        return auStack_12[0] < *param_3;
      }
      bVar1 = (byte)*param_3 < 0x20;
    }
    bVar1 = (bool)(bVar1 ^ 1);
  }
  return bVar1;
}

