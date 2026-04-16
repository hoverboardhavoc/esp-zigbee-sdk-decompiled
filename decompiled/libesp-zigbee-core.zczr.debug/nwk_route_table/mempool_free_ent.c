/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> mempool_free_ent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void mempool_free_ent(void *blk_base,bitmap_t *blk_busy,uint16_t blk_size,uint16_t blk_nr,void *obj)

{
  undefined2 in_register_00002032;
  
  if (blk_base <= obj) {
    mempool_free_idx(blk_busy,blk_nr,
                     (uint16_t)
                     (((int)obj - (int)blk_base) / CONCAT22(in_register_00002032,blk_size)));
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/common/mempool.h",0x69,"mempool_free_ent",0x1030c);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

