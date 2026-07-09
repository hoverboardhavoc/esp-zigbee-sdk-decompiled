/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mempool.o -> do_mempool_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void do_mempool_free(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  param_2 = param_2 - *(int *)(param_1 + 0xc);
  uVar2 = (uint)*(ushort *)(param_1 + 2);
  if ((param_2 < 0) || ((int)(uVar2 * *(ushort *)(param_1 + 4)) <= param_2)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0xab,
                  "do_mempool_free",&_L0);
  }
  else if (param_2 % (int)uVar2 == 0) {
    iVar1 = test_and_clr_bitmap(param_2 / (int)uVar2 & 0xffff,*(undefined4 *)(param_1 + 8));
    if (iVar1 != 0) {
      return;
    }
    goto _L0;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0xac,"do_mempool_free"
                ,&_L0);
_L0:
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0xae,"do_mempool_free"
                ,"test_and_clr_bitmap(blk_idx, pool->blk_busy_map)");
  for (uVar2 = 0; uVar2 < 3; uVar2 = uVar2 + 1 & 0xffff) {
    mempool_init_pool(s_mem_pools + uVar2 * 0x10);
  }
  return;
}

