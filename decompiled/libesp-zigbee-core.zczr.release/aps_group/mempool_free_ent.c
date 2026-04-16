/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> mempool_free_ent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_free_ent(void *blk_base,bitmap_t *blk_busy,uint16_t blk_size,uint16_t blk_nr,void *obj)

{
  ezb_shortaddr_t *peVar1;
  ds_group_info_iterator_t dStack_48;
  
  peVar1 = (ezb_shortaddr_t *)__assert_func(0,0,0,0);
  dStack_48.index = 0;
  dStack_48.is_done = false;
  while( true ) {
    ds_group_info_itor_read(&dStack_48);
    if (dStack_48.is_done != false) {
      return;
    }
    if (dStack_48.data.group_addr == *peVar1) break;
    dStack_48.index = dStack_48.index + 1;
  }
  ds_internal_remove_entry(5,&dStack_48);
  return;
}

