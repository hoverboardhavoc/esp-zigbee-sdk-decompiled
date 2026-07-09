/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_tx_window_reset_slots
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_tx_window_reset_slots(byte *param_1,uint param_2)

{
  uint uVar1;
  
  param_1[2] = 0;
  uVar1 = (uint)*param_1 - (uint)param_1[1];
  if ((int)param_2 < (int)((uint)*param_1 - (uint)param_1[1])) {
    uVar1 = param_2;
  }
  param_1[3] = (byte)uVar1;
  param_1[4] = -(char)(1 << (uVar1 & 0x1f));
  return;
}

