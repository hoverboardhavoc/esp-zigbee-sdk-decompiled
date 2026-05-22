/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mempool.o -> do_mempool_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void do_mempool_free(mem_pool_t *pool,void *obj)

{
  _Bool _Var1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  
  iVar2 = (int)obj - (int)pool->base_mem;
  uVar3 = (uint)pool->blk_size;
  if ((iVar2 < 0) || ((int)(uVar3 * pool->blk_nr) <= iVar2)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0xab,
                  "do_mempool_free",&_L0);
  }
  else if (iVar2 % (int)uVar3 == 0) {
    _Var1 = test_and_clr_bitmap(iVar2 / (int)uVar3 & 0xffff,pool->blk_busy_map);
    if (CONCAT31(extraout_var,_Var1) != 0) {
      return;
    }
    goto _L0;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0xac,"do_mempool_free"
                ,&_L0);
_L0:
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0xae,"do_mempool_free"
                ,"test_and_clr_bitmap(blk_idx, pool->blk_busy_map)");
  for (uVar3 = 0; uVar3 < 3; uVar3 = uVar3 + 1 & 0xffff) {
    mempool_init_pool(s_mem_pools + uVar3);
  }
  return;
}

