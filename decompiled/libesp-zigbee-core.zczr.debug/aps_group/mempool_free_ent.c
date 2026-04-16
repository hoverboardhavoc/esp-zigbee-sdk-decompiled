/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> mempool_free_ent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mempool_free_ent(void *blk_base,bitmap_t *blk_busy,uint16_t blk_size,uint16_t blk_nr,void *obj)

{
  _Bool _Var1;
  aps_group_t *group;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  uint n;
  undefined2 in_register_00002032;
  void *blk_base_00;
  bitmap_t *blk_busy_00;
  
  if (blk_base <= obj) {
    mempool_free_idx(blk_busy,blk_nr,
                     (uint16_t)
                     (((int)obj - (int)blk_base) / CONCAT22(in_register_00002032,blk_size)));
    return;
  }
  group = (aps_group_t *)
          __assert_func("//build/esp-zigbee/src/core/common/mempool.h",0x69,"mempool_free_ent",
                        0x103d0);
  _Var1 = test_and_clr_bitmap(n,group->ep_in_grp);
  if (CONCAT31(extraout_var,_Var1) != 0) {
    _Var1 = group_is_empty(group);
    if (CONCAT31(extraout_var_00,_Var1) == 0) {
      aps_group_table_store_group(group);
    }
    else {
      aps_group_table_remove_stored_group(group);
      iVar2 = core_globals_get();
      blk_base_00 = *(void **)(iVar2 + 0x95c);
      iVar2 = core_globals_get();
      blk_busy_00 = *(bitmap_t **)(iVar2 + 0x960);
      iVar2 = core_globals_get();
      mempool_free_ent(blk_base_00,blk_busy_00,0x22,*(uint16_t *)(iVar2 + 0x964),group);
    }
  }
  return;
}

