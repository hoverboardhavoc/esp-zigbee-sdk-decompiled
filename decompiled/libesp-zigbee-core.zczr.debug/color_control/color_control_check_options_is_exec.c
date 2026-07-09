/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_check_options_is_exec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 color_control_check_options_is_exec(undefined4 param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  
  iVar1 = color_control_srv_get_attr_desc(0xf);
  if (iVar1 == 0) {
    bVar3 = 0;
  }
  else {
    bVar3 = **(byte **)(iVar1 + 8);
    if ((param_2 & 1) != 0) {
      if ((param_3 & 1) == 0) {
        bVar3 = 0;
      }
      else {
        bVar3 = bVar3 | 1;
      }
    }
  }
  iVar1 = zcl_get_cluster_desc(param_1,6,1);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    iVar1 = ezb_zcl_get_attr_desc(param_1,6,1,0,0);
    if (iVar1 == 0) {
      uVar2 = 1;
    }
    else if (**(char **)(iVar1 + 8) == '\0') {
      if ((bVar3 & 1) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}

