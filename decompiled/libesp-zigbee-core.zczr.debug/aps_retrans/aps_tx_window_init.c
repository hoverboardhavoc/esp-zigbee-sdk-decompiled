/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_tx_window_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void aps_tx_window_init(aps_trx_window_t *w,uint8_t blk_nr,uint8_t w_sz)

{
  undefined1 *puVar1;
  undefined3 in_register_0000202d;
  uint extraout_a1;
  undefined3 in_register_00002031;
  uint uVar2;
  
  uVar2 = CONCAT31(in_register_00002031,w_sz);
  if ((uVar2 - 1 & 0xff) < 8) {
    w->blk_nr = blk_nr;
    w->blk_start = '\0';
    w->slot_i = '\0';
    if ((int)CONCAT31(in_register_0000202d,blk_nr) < (int)uVar2) {
      uVar2 = CONCAT31(in_register_0000202d,blk_nr);
    }
    w->slot_nr = (uint8_t)uVar2;
    w->slot_done = -(char)(1 << (uVar2 & 0x1f));
    return;
  }
  puVar1 = (undefined1 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x46,
                         "aps_tx_window_init","0 < w_sz && w_sz <= 8");
  if ((extraout_a1 - 1 & 0xff) < 8) {
    *puVar1 = 0xff;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = (char)extraout_a1;
    puVar1[4] = -(char)(1 << (extraout_a1 & 0x1f));
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x17d,
                "aps_rx_window_init","0 < w_sz && w_sz <= 8");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

