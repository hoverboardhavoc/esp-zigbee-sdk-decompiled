/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_tx_window_find_next_slot
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_tx_window_find_next_slot(aps_trx_window_t *w)

{
  byte bVar1;
  
  bVar1 = bitmap_find_next_zero_bit(&w->slot_done,w->slot_nr,w->slot_i);
  w->slot_i = bVar1;
  return bVar1 < w->slot_nr;
}

