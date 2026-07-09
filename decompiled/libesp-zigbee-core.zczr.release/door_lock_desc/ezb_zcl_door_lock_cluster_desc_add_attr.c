/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> door_lock_desc.o -> ezb_zcl_door_lock_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zcl_door_lock_cluster_desc_add_attr(short *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == (short *)0x0) {
    return 2;
  }
  if (*param_1 != 0x101) {
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
  uVar2 = 0x21;
  if (param_2 == 0x21) {
    uVar2 = 0x42;
    goto _L0;
  }
  if (param_2 < 0x22) {
    if (param_2 < 6) {
      if (3 < param_2) {
_L0:
        uVar2 = 0x23;
        goto _L0;
      }
      if (param_2 != 2) goto _L0;
    }
    else {
      if (param_2 < 0x14) {
        if ((param_2 < 0x10) && (param_2 != 6)) {
          return 6;
        }
        goto _L0;
      }
      uVar2 = 0x20;
      if (param_2 < 0x1b) goto _L0;
      if (param_2 != 0x20) {
        return 6;
      }
    }
    goto _L0;
  }
  if (param_2 != 0x26) {
    if (param_2 < 0x27) {
      if (param_2 != 0x24) {
        if (param_2 == 0x25) goto _L0;
        if (param_2 != 0x22) goto _L0;
      }
_L0:
      uVar2 = 0x20;
      goto _L0;
    }
    if (param_2 < 0x34) {
      if (param_2 < 0x32) {
        if (param_2 == 0x27) goto _L0;
        if (0x2b < param_2) {
          if (1 < (param_2 - 0x30 & 0xffff)) {
            return 6;
          }
          goto _L0;
        }
      }
_L0:
      uVar2 = 0x10;
      goto _L0;
    }
    if (param_2 == 0x34) {
_L0:
      uVar2 = 0x30;
      goto _L0;
    }
    if (7 < (param_2 - 0x40 & 0xffff)) {
      return 6;
    }
  }
_L0:
  uVar2 = 0x19;
_L0:
  uVar2 = ezb_zcl_cluster_desc_add_manuf_attr(uVar2,0);
  return uVar2;
}

