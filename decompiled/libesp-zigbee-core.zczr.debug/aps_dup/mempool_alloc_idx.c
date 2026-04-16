/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> mempool_alloc_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t mempool_alloc_idx(bitmap_t *blk_busy,uint16_t blk_nr)

{
  _Bool _Var1;
  uint n;
  undefined3 extraout_var;
  undefined2 in_register_0000202e;
  
  do {
    n = bitmap_find_first_zero_bit(blk_busy,CONCAT22(in_register_0000202e,blk_nr));
    if (CONCAT22(in_register_0000202e,blk_nr) <= n) break;
    _Var1 = test_and_set_bitmap(n,blk_busy);
  } while (CONCAT31(extraout_var,_Var1) != 0);
  return (uint16_t)n;
}

