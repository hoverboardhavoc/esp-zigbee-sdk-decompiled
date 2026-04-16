/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> mempool_free_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void mempool_free_idx(bitmap_t *blk_busy,uint16_t blk_nr,uint16_t blk_idx)

{
  _Bool _Var1;
  undefined3 extraout_var;
  undefined2 in_register_0000202e;
  undefined2 in_register_00002032;
  
  if ((CONCAT22(in_register_00002032,blk_idx) < CONCAT22(in_register_0000202e,blk_nr)) &&
     (_Var1 = test_and_clr_bitmap(CONCAT22(in_register_00002032,blk_idx),blk_busy),
     CONCAT31(extraout_var,_Var1) != 0)) {
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/common/mempool.h",0x56,"mempool_free_idx",
                "(blk_idx < blk_nr) && test_and_clr_bitmap(blk_idx, blk_busy)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

