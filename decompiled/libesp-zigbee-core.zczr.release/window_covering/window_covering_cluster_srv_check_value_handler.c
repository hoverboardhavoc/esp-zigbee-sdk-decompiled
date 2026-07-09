/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> window_covering.o -> window_covering_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
window_covering_cluster_srv_check_value_handler(uint param_1,undefined4 param_2,ushort *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  ushort uVar4;
  ushort uVar5;
  
  if (param_1 == 7) {
    if (-1 < (char)(byte)*param_3) {
      return 0;
    }
    return 0x87;
  }
  if (param_1 < 8) {
    if (param_1 == 3) {
      iVar2 = window_covering_srv_get_attr_desc(param_2,0x10);
      uVar3 = 0x11;
    }
    else {
      if (param_1 != 4) {
        if (param_1 != 0) {
          return 0;
        }
        uVar4 = (ushort)(byte)*param_3;
        uVar5 = 9;
        goto _L44;
      }
      iVar2 = window_covering_srv_get_attr_desc(param_2,0x12);
      uVar3 = 0x13;
    }
    iVar1 = window_covering_srv_get_attr_desc(param_2,uVar3);
    if ((((iVar2 == 0) || (*(ushort **)(iVar2 + 8) == (ushort *)0x0)) || (iVar1 == 0)) ||
       (*(ushort **)(iVar1 + 8) == (ushort *)0x0)) {
      return 0x8b;
    }
    uVar5 = *param_3;
    if (**(ushort **)(iVar1 + 8) < uVar5) {
      return 0x87;
    }
    uVar4 = **(ushort **)(iVar2 + 8);
  }
  else {
    if (1 < (param_1 - 8 & 0xffff)) {
      return 0;
    }
    uVar4 = (ushort)(byte)*param_3;
    uVar5 = 100;
  }
_L44:
  if (uVar5 < uVar4) {
    return 0x87;
  }
  return 0;
}

