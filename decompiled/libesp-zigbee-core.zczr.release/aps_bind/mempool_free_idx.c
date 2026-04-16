/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> mempool_free_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mempool_free_idx(bitmap_t *blk_busy,uint16_t blk_nr,uint16_t blk_idx)

{
  _Bool _Var1;
  undefined3 extraout_var;
  undefined2 in_register_0000202e;
  undefined2 in_register_00002032;
  uint n;
  
  n = CONCAT22(in_register_00002032,blk_idx);
  if (n < CONCAT22(in_register_0000202e,blk_nr)) goto _L26;
  do {
    n = 0;
    blk_busy = (bitmap_t *)__assert_func(0,0,0,0);
_L26:
    _Var1 = test_and_clr_bitmap(n,blk_busy);
  } while (CONCAT31(extraout_var,_Var1) == 0);
  return;
}

