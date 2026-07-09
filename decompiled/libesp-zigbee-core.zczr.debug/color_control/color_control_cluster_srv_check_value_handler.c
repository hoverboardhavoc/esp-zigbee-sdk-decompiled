/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
color_control_cluster_srv_check_value_handler(uint param_1,undefined4 param_2,ushort *param_3)

{
  undefined4 uVar1;
  ushort uStack_14;
  ushort auStack_12 [5];
  
  if (param_1 == 4) {
    if (*param_3 < 0xff00) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else if (param_1 < 5) {
    if (param_1 == 1) {
      if ((byte)*param_3 == 0xff) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else if (param_1 == 3) {
      if (*param_3 < 0xff00) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else if (param_1 == 0) {
      if ((byte)*param_3 == 0xff) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else if (param_1 == 8) {
    if ((byte)*param_3 < 3) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else if (param_1 == 0x400a) {
    if ((byte)*param_3 < 0x20) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else if (param_1 == 7) {
    uStack_14 = 0;
    auStack_12[0] = 0;
    color_control_get_color_temperature_range(param_2,&uStack_14,auStack_12);
    if (*param_3 < uStack_14) {
      uVar1 = 1;
    }
    else if (auStack_12[0] < *param_3) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

