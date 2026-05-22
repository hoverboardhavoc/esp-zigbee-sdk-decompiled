/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mempool.o -> mempool_resize_pool
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mempool_resize_pool(mem_pool_t *pool,uint16_t size)

{
  uint8_t *puVar1;
  bitmap_t *pbVar2;
  mem_pool_t *pool_00;
  undefined2 in_register_0000202e;
  uint uVar3;
  uint uVar4;
  
  uVar3 = CONCAT22(in_register_0000202e,size);
  if (pool == (mem_pool_t *)0x0) {
    pool_00 = (mem_pool_t *)
              __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0x6e,
                            "mempool_resize_pool",0x10000);
  }
  else {
    pool_00 = pool;
    if (uVar3 != 0) {
      puVar1 = (uint8_t *)mm_realloc(pool->base_mem,pool->blk_size);
      pool->base_mem = puVar1;
      uVar4 = uVar3 + 7 >> 3;
      pbVar2 = (bitmap_t *)mm_realloc(pool->blk_busy_map,uVar4,1);
      pool->blk_busy_map = pbVar2;
      if (pool->blk_nr < uVar3) {
        uVar3 = pool->blk_nr + 7 >> 3;
        memset(pbVar2 + uVar3,0,uVar4 - uVar3);
      }
      goto _L0;
    }
  }
  mempool_deinit_pool(pool_00);
_L0:
  pool->blk_nr = size;
  return;
}

