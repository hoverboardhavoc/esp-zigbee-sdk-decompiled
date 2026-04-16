/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_group_table_restore(void)

{
  ushort blk_nr;
  bool bVar1;
  bool bVar2;
  uint16_t uVar3;
  int iVar4;
  int iVar5;
  undefined2 extraout_var;
  aps_group_t *__s;
  bitmap_t *blk_busy;
  undefined1 local_48 [4];
  ds_group_info_iterator_t itor;
  
  itor.data.ep_in_grp[0x1c] = '\0';
  itor.data.ep_in_grp[0x1d] = '\0';
  itor.data.ep_in_grp[0x1e] = '\0';
  ds_group_info_itor_read((ds_group_info_iterator_t *)local_48);
  bVar1 = false;
  do {
    if (itor.data.ep_in_grp[0x1e] != '\0') {
      bVar2 = false;
_L0:
      if ((bVar1) || (bVar2)) {
        aps_group_table_refresh_stored_groups();
      }
      return;
    }
    __s = group_table_find(local_48._0_2_);
    if (__s == (aps_group_t *)0x0) {
      iVar4 = core_globals_get();
      iVar4 = *(int *)(iVar4 + 0x95c);
      iVar5 = core_globals_get();
      blk_busy = *(bitmap_t **)(iVar5 + 0x960);
      iVar5 = core_globals_get();
      blk_nr = *(ushort *)(iVar5 + 0x964);
      uVar3 = mempool_alloc_idx(blk_busy,blk_nr);
      if ((uint)blk_nr <= CONCAT22(extraout_var,uVar3)) {
        bVar2 = true;
        goto _L0;
      }
      __s = (aps_group_t *)(iVar4 + CONCAT22(extraout_var,uVar3) * 0x22);
      if (__s == (aps_group_t *)0x0) {
        bVar2 = true;
        goto _L0;
      }
    }
    else {
      bVar1 = true;
    }
    memset(__s,0,0x22);
    __s->group_addr = local_48._0_2_;
    memcpy(__s->ep_in_grp,local_48 + 2,0x20);
    ds_group_info_next((ds_group_info_iterator_t *)local_48);
  } while( true );
}

