/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> window_covering.o -> window_covering_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
window_covering_cluster_srv_check_value_handler(uint param_1,undefined4 param_2,ushort *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 7) {
    if ((char)(byte)*param_3 < '\0') {
      uVar1 = 0x87;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (param_1 < 8) {
    if (param_1 == 3) {
      iVar2 = window_covering_srv_get_attr_desc(param_2,0x10);
      iVar3 = window_covering_srv_get_attr_desc(param_2,0x11);
      if (iVar2 == 0) {
        uVar1 = 0x8b;
      }
      else if (*(ushort **)(iVar2 + 8) == (ushort *)0x0) {
        uVar1 = 0x8b;
      }
      else if (iVar3 == 0) {
        uVar1 = 0x8b;
      }
      else if (*(ushort **)(iVar3 + 8) == (ushort *)0x0) {
        uVar1 = 0x8b;
      }
      else if (**(ushort **)(iVar3 + 8) < *param_3) {
        uVar1 = 0x87;
      }
      else if (*param_3 < **(ushort **)(iVar2 + 8)) {
        uVar1 = 0x87;
      }
      else {
        uVar1 = 0;
      }
    }
    else if (param_1 == 4) {
      iVar2 = window_covering_srv_get_attr_desc(param_2,0x12);
      iVar3 = window_covering_srv_get_attr_desc(param_2,0x13);
      if (iVar2 == 0) {
        uVar1 = 0x8b;
      }
      else if (*(ushort **)(iVar2 + 8) == (ushort *)0x0) {
        uVar1 = 0x8b;
      }
      else if (iVar3 == 0) {
        uVar1 = 0x8b;
      }
      else if (*(ushort **)(iVar3 + 8) == (ushort *)0x0) {
        uVar1 = 0x8b;
      }
      else if (**(ushort **)(iVar3 + 8) < *param_3) {
        uVar1 = 0x87;
      }
      else if (*param_3 < **(ushort **)(iVar2 + 8)) {
        uVar1 = 0x87;
      }
      else {
        uVar1 = 0;
      }
    }
    else if (param_1 == 0) {
      if ((byte)*param_3 < 10) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0x87;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else if (param_1 == 8) {
    if ((byte)*param_3 < 0x65) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x87;
    }
  }
  else if (param_1 == 9) {
    if ((byte)*param_3 < 0x65) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x87;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

