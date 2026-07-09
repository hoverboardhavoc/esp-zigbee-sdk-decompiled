/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_write_s48
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_write_s48(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined1 uStack_4;
  byte bStack_3;
  byte bStack_1;
  
  uStack_8 = (undefined1)param_2;
  uStack_7 = (undefined1)((uint)param_2 >> 8);
  uStack_6 = (undefined1)((uint)param_2 >> 0x10);
  uStack_5 = (undefined1)((uint)param_2 >> 0x18);
  uStack_4 = (undefined1)param_3;
  bStack_3 = (byte)((uint)param_3 >> 8);
  *param_1 = uStack_8;
  param_1[1] = uStack_7;
  param_1[2] = uStack_6;
  param_1[3] = uStack_5;
  param_1[4] = uStack_4;
  param_1[5] = bStack_3;
  bStack_1 = (byte)((uint)param_3 >> 0x18);
  param_1[5] = bStack_3 | bStack_1 & 0x80;
  return;
}

