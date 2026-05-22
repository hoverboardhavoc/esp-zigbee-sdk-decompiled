/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_rx_window_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void aps_rx_window_init(aps_trx_window_t *w,uint8_t w_sz)

{
  if ((byte)(w_sz - 1) < 8) {
    w->blk_nr = 0xff;
    w->blk_start = '\0';
    w->slot_i = '\0';
    w->slot_nr = w_sz;
    w->slot_done = -(char)(1 << (w_sz & 0x1f));
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x17d,
                "aps_rx_window_init","0 < w_sz && w_sz <= 8");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

