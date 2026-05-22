/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_tx_window_move_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_tx_window_move_next(aps_trx_window_t *w)

{
  uint uVar1;
  uint uVar2;
  
  if (w->slot_done == 0xff) {
    uVar2 = (uint)w->slot_nr;
    uVar1 = w->blk_start + uVar2;
    if (uVar1 < w->blk_nr) {
      w->blk_start = (uint8_t)uVar1;
      w->slot_i = '\0';
      uVar1 = (uint)w->blk_nr - (uVar1 & 0xff);
      if ((int)uVar1 < (int)uVar2) {
        uVar2 = uVar1;
      }
      w->slot_nr = (uint8_t)uVar2;
      w->slot_done = -(char)(1 << (uVar2 & 0x1f));
      return true;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",99,
                  "aps_tx_window_move_next",
                  "w->slot_done == (((1 << ((8) % (sizeof(unsigned long) * 8))) - 1) << (0))");
  }
  return false;
}

