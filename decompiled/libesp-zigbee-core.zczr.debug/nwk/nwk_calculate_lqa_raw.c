/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_calculate_lqa_raw
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_calculate_lqa_raw(uint param_1,int param_2)

{
  char cVar1;
  
  if (param_1 < 7) {
    param_1 = 7;
  }
  if (10 < (param_1 & 0xff)) {
    param_1 = 10;
  }
  if (param_2 < -100) {
    param_2 = -100;
  }
  cVar1 = (char)param_2;
  if ('\b' < cVar1) {
    cVar1 = '\b';
  }
  return (int)(((param_1 & 0xff) - 6) * (cVar1 + 0x65) * 0xff) / 0x1b4 & 0xff;
}

