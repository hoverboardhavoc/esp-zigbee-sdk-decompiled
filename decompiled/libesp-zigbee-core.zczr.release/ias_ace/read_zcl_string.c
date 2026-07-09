/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> read_zcl_string
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 read_zcl_string(int param_1,int param_2,byte *param_3,uint param_4)

{
  byte *unaff_s0;
  undefined4 uVar1;
  int unaff_s2;
  
  if (((param_1 == 0) || (unaff_s2 = param_2, param_2 == 0)) ||
     (unaff_s0 = param_3, param_3 == (byte *)0x0)) {
    param_4 = 0;
    param_1 = __assert_func(0,0,0);
  }
  af_read_le8();
  uVar1 = 0x87;
  if (*unaff_s0 < param_4) {
    af_read_bytes_isra_0(param_1,unaff_s2,unaff_s0 + 1);
    uVar1 = 0;
  }
  return uVar1;
}

