/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> analog_output_desc.o -> ezb_zcl_analog_output_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
ezb_zcl_analog_output_cluster_desc_add_attr(short *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == (short *)0x0) {
    return 2;
  }
  if (*param_1 != 0xd) {
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
  if (param_2 == 0x67) {
    uVar2 = 0x30;
    goto _L0;
  }
  if (param_2 < 0x68) {
    if (param_2 == 0x51) {
      uVar2 = 0x10;
      goto _L0;
    }
    if (param_2 < 0x52) {
      uVar2 = 0x42;
      if (param_2 == 0x1c) goto _L0;
      if (param_2 < 0x1c) {
        return 6;
      }
      param_2 = param_2 & 0xfffffffb;
      uVar1 = 0x41;
      goto _L28;
    }
    if (param_2 != 0x55) {
      if (param_2 != 0x57) {
        return 6;
      }
      uVar2 = 0x48;
      goto _L0;
    }
  }
  else {
    if (param_2 == 0x75) {
      uVar2 = 0x31;
      goto _L0;
    }
    if (0x75 < param_2) {
      if (param_2 != 0x100) {
        return 6;
      }
      uVar2 = 0x23;
      goto _L0;
    }
    if (param_2 == 0x6f) {
      uVar2 = 0x18;
      goto _L0;
    }
    if (0x6f < param_2) {
      return 6;
    }
    param_2 = param_2 & 0xfffffffd;
    uVar1 = 0x68;
_L28:
    if (param_2 != uVar1) {
      return 6;
    }
  }
  uVar2 = 0x39;
_L0:
  uVar2 = ezb_zcl_cluster_desc_add_manuf_attr(uVar2,0);
  return uVar2;
}

