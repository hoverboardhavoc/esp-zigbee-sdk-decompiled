/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mempool.o -> mempool_resize
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mempool_resize(uint16_t size)

{
  mem_pool_t *pmVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  uint8_t *puVar3;
  bitmap_t *pbVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = CONCAT22(in_register_0000202a,size);
  pmVar1 = s_mem_pools;
  uVar6 = uVar2 + 7 >> 3;
  do {
    if (uVar2 == 0) {
      if (pmVar1->base_mem != (uint8_t *)0x0) {
        mm_free();
        pmVar1->base_mem = (uint8_t *)0x0;
      }
      if (pmVar1->blk_busy_map != (bitmap_t *)0x0) {
        mm_free();
        pmVar1->blk_busy_map = (bitmap_t *)0x0;
      }
    }
    else {
      puVar3 = (uint8_t *)mm_realloc(uVar2,pmVar1->blk_size);
      pmVar1->base_mem = puVar3;
      pbVar4 = (bitmap_t *)mm_realloc(pmVar1->blk_busy_map,uVar6,1);
      pmVar1->blk_busy_map = pbVar4;
      if (pmVar1->blk_nr < uVar2) {
        uVar5 = pmVar1->blk_nr + 7 >> 3;
        memset(pbVar4 + uVar5,0,uVar6 - uVar5);
      }
    }
    pmVar1->blk_nr = size;
    pmVar1 = pmVar1 + 1;
  } while (pmVar1 != (mem_pool_t *)0x10264);
  return;
}

