/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_tx_window_move_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool aps_tx_window_move_next(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  
  if (param_1[4] != 0xff) {
    param_1 = (byte *)__assert_func(0,0,0,0);
  }
  bVar1 = *param_1;
  uVar2 = (uint)param_1[1] + (uint)param_1[3];
  if (uVar2 < bVar1) {
    param_1[1] = (byte)uVar2;
    aps_tx_window_reset_slots();
  }
  return uVar2 < bVar1;
}

