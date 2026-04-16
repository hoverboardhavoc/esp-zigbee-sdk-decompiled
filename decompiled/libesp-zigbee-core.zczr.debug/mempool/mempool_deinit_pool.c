/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mempool.o -> mempool_deinit_pool
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mempool_deinit_pool(mem_pool_t *pool)

{
  mem_pool_t *pmVar1;
  uint8_t *puVar2;
  bitmap_t *pbVar3;
  mem_pool_t *pool_00;
  uint extraout_a1;
  uint uVar4;
  uint uVar5;
  
  if (pool != (mem_pool_t *)0x0) {
    if (pool->base_mem != (uint8_t *)0x0) {
      mm_free();
      pool->base_mem = (uint8_t *)0x0;
    }
    if (pool->blk_busy_map != (bitmap_t *)0x0) {
      mm_free();
      pool->blk_busy_map = (bitmap_t *)0x0;
    }
    return;
  }
  pmVar1 = (mem_pool_t *)
           __assert_func("//build/esp-zigbee/src/core/common/mempool.c",0x5f,"mempool_deinit_pool",
                         0x10000);
  if (pmVar1 == (mem_pool_t *)0x0) {
    pool_00 = (mem_pool_t *)
              __assert_func("//build/esp-zigbee/src/core/common/mempool.c",0x6e,
                            "mempool_resize_pool",0x10000);
  }
  else {
    pool_00 = pmVar1;
    if (extraout_a1 != 0) {
      puVar2 = (uint8_t *)mm_realloc(pmVar1->base_mem,pmVar1->blk_size);
      pmVar1->base_mem = puVar2;
      uVar5 = extraout_a1 + 7 >> 3;
      pbVar3 = (bitmap_t *)mm_realloc(pmVar1->blk_busy_map,uVar5,1);
      pmVar1->blk_busy_map = pbVar3;
      if (pmVar1->blk_nr < extraout_a1) {
        uVar4 = pmVar1->blk_nr + 7 >> 3;
        memset(pbVar3 + uVar4,0,uVar5 - uVar4);
      }
      goto _L0;
    }
  }
  mempool_deinit_pool(pool_00);
_L0:
  pmVar1->blk_nr = (uint16_t)extraout_a1;
  return;
}

