/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> color_control_check_options_is_exec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte color_control_check_options_is_exec(undefined4 param_1,uint param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = color_control_srv_get_attr_desc(0xf);
  bVar1 = 0;
  if ((iVar2 != 0) && (bVar1 = **(byte **)(iVar2 + 8), (param_2 & 1) != 0)) {
    if ((param_3 & 1) == 0) {
      bVar1 = 0;
    }
    else {
      bVar1 = bVar1 | 1;
    }
  }
  iVar2 = zcl_get_cluster_desc(param_1,6,1);
  if ((iVar2 == 0) || (iVar2 = ezb_zcl_get_attr_desc(param_1,6,1,0,0), iVar2 == 0)) {
    bVar1 = 1;
  }
  else {
    bVar1 = **(char **)(iVar2 + 8) != '\0' | bVar1 & 1;
  }
  return bVar1;
}

