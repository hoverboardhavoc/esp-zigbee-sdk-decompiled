/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_tx_window_move_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_tx_window_move_next(aps_trx_window_t *w)

{
  bool bVar1;
  uint uVar2;
  
  if (w->slot_done != 0xff) {
    w = (aps_trx_window_t *)__assert_func(0,0,0,0);
  }
  uVar2 = (uint)w->blk_start + (uint)w->slot_nr;
  bVar1 = uVar2 < w->blk_nr;
  if (bVar1) {
    w->blk_start = (uint8_t)uVar2;
    aps_tx_window_reset_slots(w,w->slot_nr);
  }
  return bVar1;
}

