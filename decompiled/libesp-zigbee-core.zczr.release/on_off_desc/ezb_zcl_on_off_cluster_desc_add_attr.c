/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> on_off_desc.o -> ezb_zcl_on_off_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint ezb_zcl_on_off_cluster_desc_add_attr(ushort *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 == (ushort *)0x0) {
    uVar4 = 2;
  }
  else {
    uVar5 = (uint)*param_1;
    uVar4 = 2;
    if (uVar5 == 6) {
      uVar3 = (uint)(byte)param_1[1];
      uVar1 = 1;
      uVar4 = uVar5;
      if (1 < (uVar3 - 1 & 0xffff)) {
        uVar3 = 0;
        uVar1 = 0;
        param_2 = __assert_func(0,0,param_3);
        uVar4 = uVar5;
      }
      if (uVar3 == uVar1) {
        if (param_2 < 0x4003) {
          if (param_2 < 0x4001) {
            if ((param_2 != 0) && (param_2 != 0x4000)) {
              return uVar4;
            }
            uVar2 = 0x10;
          }
          else {
            uVar2 = 0x21;
          }
        }
        else if (param_2 == 0x4003) {
          uVar2 = 0x30;
        }
        else {
          if (param_2 != 0xeff0) {
            return uVar4;
          }
          uVar2 = 0;
        }
        uVar4 = ezb_zcl_cluster_desc_add_manuf_attr(uVar2,0);
        return uVar4;
      }
    }
  }
  return uVar4;
}

