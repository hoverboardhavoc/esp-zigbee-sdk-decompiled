/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mempool.o -> mempool_init_pool
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mempool_init_pool(mem_pool_t *pool)

{
  uint8_t *puVar1;
  bitmap_t *pbVar2;
  
  if (pool == (mem_pool_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/common/mempool.c",0x52,"mempool_init_pool",0x10000);
  }
  else if ((pool->blk_nr == 0) || (pool->blk_size == 0)) {
    pool->base_mem = (uint8_t *)0x0;
    pool->blk_busy_map = (bitmap_t *)0x0;
    return;
  }
  puVar1 = (uint8_t *)mm_calloc();
  pool->base_mem = puVar1;
  pbVar2 = (bitmap_t *)mm_calloc(pool->blk_nr + 7 >> 3,1);
  pool->blk_busy_map = pbVar2;
  return;
}

