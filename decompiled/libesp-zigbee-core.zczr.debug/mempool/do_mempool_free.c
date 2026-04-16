/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    __assert_func("//build/esp-zigbee/src/core/common/mempool.c",0xab,"do_mempool_free",&_LC2);
  }
  else if (iVar2 % (int)uVar3 == 0) {
    _Var1 = test_and_clr_bitmap(iVar2 / (int)uVar3 & 0xffff,pool->blk_busy_map);
    if (CONCAT31(extraout_var,_Var1) != 0) {
      return;
    }
    goto _L0;
  }
  __assert_func("//build/esp-zigbee/src/core/common/mempool.c",0xac,"do_mempool_free",&_LC2);
_L0:
  __assert_func("//build/esp-zigbee/src/core/common/mempool.c",0xae,"do_mempool_free",
                "test_and_clr_bitmap(blk_idx, pool->blk_busy_map)");
  for (uVar3 = 0; uVar3 < 3; uVar3 = uVar3 + 1 & 0xffff) {
    mempool_init_pool(s_mem_pools + uVar3);
  }
  return;
}

