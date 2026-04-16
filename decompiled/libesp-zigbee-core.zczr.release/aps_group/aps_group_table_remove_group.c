/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_remove_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_group_table_remove_group(ezb_shortaddr_t group_addr)

{
  _Bool _Var1;
  undefined3 extraout_var;
  aps_group_t *group;
  int iVar2;
  bitmap_t *blk_busy;
  uint16_t in_a2;
  bitmap_t *n;
  uint16_t in_a3;
  void *in_a4;
  aps_group_t *paVar3;
  bitmap_t *p;
  
  group = group_table_find(group_addr);
  if (group == (aps_group_t *)0x0) {
    return;
  }
  aps_group_table_remove_stored_group(group);
  iVar2 = core_globals_get();
  paVar3 = *(aps_group_t **)(iVar2 + 0x95c);
  iVar2 = core_globals_get();
  p = *(bitmap_t **)(iVar2 + 0x960);
  iVar2 = core_globals_get();
  blk_busy = (bitmap_t *)(uint)*(ushort *)(iVar2 + 0x964);
  if (group < paVar3) {
    mempool_free_ent((void *)(iVar2 + 0x1000),blk_busy,in_a2,in_a3,in_a4);
  }
  n = (bitmap_t *)(((int)group - (int)paVar3) / 0x22 & 0xffff);
  if (n < blk_busy) goto _L18;
  do {
    n = (bitmap_t *)0x0;
    p = (bitmap_t *)__assert_func(0,0,0);
_L18:
    _Var1 = test_and_clr_bitmap((uint)n,p);
  } while (CONCAT31(extraout_var,_Var1) == 0);
  return;
}

