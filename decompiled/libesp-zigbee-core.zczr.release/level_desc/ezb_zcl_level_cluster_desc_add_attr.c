/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> level_desc.o -> ezb_zcl_level_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zcl_level_cluster_desc_add_attr(short *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == (short *)0x0) {
    return 2;
  }
  if (*param_1 != 8) {
    return 2;
  }
  uVar3 = (uint)*(byte *)(param_1 + 1);
  uVar1 = 1;
  if (1 < (uVar3 - 1 & 0xffff)) {
    uVar3 = 0;
    uVar1 = 0;
    param_2 = __assert_func(0,0,param_3);
  }
  if (uVar3 != uVar1) {
    return 6;
  }
  if (param_2 == 0xf) {
    uVar2 = 0x18;
    goto _L0;
  }
  if (param_2 < 0x10) {
    if (param_2 < 4) {
      if ((uVar3 < param_2) || (param_2 == 0)) goto _L0;
    }
    else if ((param_2 != 4) && (uVar3 < (param_2 - 5 & 0xffff))) {
      return 6;
    }
_L0:
    uVar2 = 0x21;
  }
  else {
    if (param_2 != 0x14) {
      if (param_2 < 0x15) {
        if (param_2 != 0x11) goto _L0;
      }
      else if (param_2 != 0x4000) {
        if (param_2 != 0xeff0) {
          return 6;
        }
        uVar2 = 0;
        goto _L0;
      }
    }
_L0:
    uVar2 = 0x20;
  }
_L0:
  uVar2 = ezb_zcl_cluster_desc_add_manuf_attr(uVar2,0);
  return uVar2;
}

