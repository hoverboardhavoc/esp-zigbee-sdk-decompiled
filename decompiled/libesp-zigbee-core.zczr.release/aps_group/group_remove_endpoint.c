/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> group_remove_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool group_remove_endpoint(aps_group_t *group,uint8_t endpoint)

{
  aps_group_t *paVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  uint uVar3;
  int iVar4;
  ushort blk_nr;
  undefined3 in_register_0000202d;
  bitmap_t *blk_busy;
  uint16_t in_a2;
  uint16_t in_a3;
  void *in_a4;
  bitmap_t *blk_busy_00;
  
  _Var2 = test_and_clr_bitmap(CONCAT31(in_register_0000202d,endpoint),group->ep_in_grp);
  if (CONCAT31(extraout_var,_Var2) != 0) {
    uVar3 = bitmap_find_first_bit(group->ep_in_grp,0xff);
    if (uVar3 < 0xff) {
      aps_group_table_store_group(group);
    }
    else {
      aps_group_table_remove_stored_group(group);
      iVar4 = core_globals_get();
      paVar1 = *(aps_group_t **)(iVar4 + 0x95c);
      iVar4 = core_globals_get();
      blk_busy_00 = *(bitmap_t **)(iVar4 + 0x960);
      iVar4 = core_globals_get();
      blk_nr = *(ushort *)(iVar4 + 0x964);
      blk_busy = (bitmap_t *)(uint)blk_nr;
      if (group < paVar1) {
        mempool_free_ent((void *)(iVar4 + 0x1000),blk_busy,in_a2,in_a3,in_a4);
        blk_nr = (ushort)blk_busy;
      }
      mempool_free_idx(blk_busy_00,blk_nr,(uint16_t)(((int)group - (int)paVar1) / 0x22));
    }
  }
  return _Var2;
}

