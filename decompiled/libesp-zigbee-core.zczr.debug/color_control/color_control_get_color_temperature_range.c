/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_get_color_temperature_range
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
color_control_get_color_temperature_range
          (undefined4 param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  
  if (param_2 == (undefined2 *)0x0) {
    uVar3 = 0;
  }
  else if (param_3 == (undefined2 *)0x0) {
    uVar3 = 0;
  }
  else {
    iVar1 = color_control_srv_get_attr_desc(0x400b);
    iVar2 = color_control_srv_get_attr_desc(param_1,0x400c);
    if (iVar1 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = **(undefined2 **)(iVar1 + 8);
    }
    *param_2 = uVar4;
    if (iVar2 == 0) {
      uVar4 = 0xfeff;
    }
    else {
      uVar4 = **(undefined2 **)(iVar2 + 8);
    }
    *param_3 = uVar4;
    uVar3 = 1;
  }
  return uVar3;
}

