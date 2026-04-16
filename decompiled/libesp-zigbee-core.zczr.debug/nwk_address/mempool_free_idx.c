/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> mempool_free_idx
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
  int iVar2;
  int iVar3;
  undefined2 in_register_0000202e;
  undefined2 in_register_00002032;
  uint uVar4;
  int iVar5;
  
  if ((CONCAT22(in_register_00002032,blk_idx) < CONCAT22(in_register_0000202e,blk_nr)) &&
     (_Var1 = test_and_clr_bitmap(CONCAT22(in_register_00002032,blk_idx),blk_busy),
     CONCAT31(extraout_var,_Var1) != 0)) {
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/common/mempool.h",0x56,"mempool_free_idx",
                "(blk_idx < blk_nr) && test_and_clr_bitmap(blk_idx, blk_busy)");
  iVar2 = core_globals_get();
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar2 + 0xcaa) = 0;
  *(undefined1 *)(iVar2 + 0xcab) = 0;
  *(undefined1 *)(iVar2 + 0xcac) = 0;
  *(undefined1 *)(iVar2 + 0xcad) = 0;
  uVar4 = 0;
  while (uVar4 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar3 + 0xcb0),*(undefined2 *)(iVar3 + 0xcb8),uVar4),
        uVar4 < *(ushort *)(iVar3 + 0xcb8)) {
    iVar5 = *(int *)(iVar3 + 0xcb4) + uVar4 * 0x10;
    if ((*(ushort *)(iVar5 + 0xe) >> 10 & 1) == 0) {
      test_and_set_bitmap((uint)*(byte *)(iVar5 + 5),(bitmap_t *)(iVar2 + 0xcaa));
    }
    uVar4 = uVar4 + 1 & 0xffff;
  }
  return;
}

