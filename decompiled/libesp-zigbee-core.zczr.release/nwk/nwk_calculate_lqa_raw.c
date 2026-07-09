/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_calculate_lqa_raw
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_calculate_lqa_raw(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1 & 0xff;
  if (param_1 < 7) {
    uVar1 = 7;
  }
  if (param_2 < -100) {
    param_2 = -100;
  }
  iVar2 = (int)(char)param_2;
  if (10 < uVar1) {
    uVar1 = 10;
  }
  if (8 < iVar2) {
    iVar2 = 8;
  }
  return (int)((uVar1 - 6) * ((iVar2 + 0x65) * 0x1000000 >> 0x18) * 0xff) / 0x1b4 & 0xff;
}

