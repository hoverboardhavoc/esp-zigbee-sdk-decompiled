/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_remove_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_group_table_remove_group(ezb_shortaddr_t group_addr)

{
  aps_group_t *group;
  int iVar1;
  void *blk_base;
  bitmap_t *blk_busy;
  
  group = group_table_find(group_addr);
  if (group != (aps_group_t *)0x0) {
    aps_group_table_remove_stored_group(group);
    iVar1 = core_globals_get();
    blk_base = *(void **)(iVar1 + 0x95c);
    iVar1 = core_globals_get();
    blk_busy = *(bitmap_t **)(iVar1 + 0x960);
    iVar1 = core_globals_get();
    mempool_free_ent(blk_base,blk_busy,0x22,*(uint16_t *)(iVar1 + 0x964),group);
  }
  return;
}

