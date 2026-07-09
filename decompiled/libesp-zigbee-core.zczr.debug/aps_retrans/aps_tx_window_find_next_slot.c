/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_tx_window_find_next_slot
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool aps_tx_window_find_next_slot(int param_1)

{
  byte bVar1;
  
  bVar1 = bitmap_find_next_zero_bit
                    (param_1 + 4,*(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 2));
  *(byte *)(param_1 + 2) = bVar1;
  return bVar1 < *(byte *)(param_1 + 3);
}

