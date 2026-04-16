/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_tx_window_reset_slots
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_tx_window_reset_slots(aps_trx_window_t *w,uint8_t w_sz)

{
  undefined3 in_register_0000202d;
  uint uVar1;
  
  w->slot_i = '\0';
  uVar1 = (uint)w->blk_nr - (uint)w->blk_start;
  if ((int)CONCAT31(in_register_0000202d,w_sz) < (int)uVar1) {
    uVar1 = CONCAT31(in_register_0000202d,w_sz);
  }
  w->slot_nr = (uint8_t)uVar1;
  w->slot_done = -(char)(1 << (uVar1 & 0x1f));
  return;
}

