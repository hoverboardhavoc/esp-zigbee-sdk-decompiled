/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_group_table_add(ezb_shortaddr_t group_addr,uint8_t endpoint)

{
  ushort blk_nr;
  uint uVar1;
  uint16_t uVar2;
  undefined2 in_register_0000202a;
  aps_group_t *group;
  int iVar3;
  int iVar4;
  undefined2 extraout_var;
  uint uVar5;
  undefined3 in_register_0000202d;
  bitmap_t *blk_busy;
  
  if (0xfd < (CONCAT31(in_register_0000202d,endpoint) - 1 & 0xff)) {
    return 2;
  }
  if (CONCAT22(in_register_0000202a,group_addr) == 0) {
    return 2;
  }
  group = group_table_find(group_addr);
  if (group == (aps_group_t *)0x0) {
    iVar3 = core_globals_get();
    iVar3 = *(int *)(iVar3 + 0x95c);
    iVar4 = core_globals_get();
    blk_busy = *(bitmap_t **)(iVar4 + 0x960);
    iVar4 = core_globals_get();
    blk_nr = *(ushort *)(iVar4 + 0x964);
    uVar2 = mempool_alloc_idx(blk_busy,blk_nr);
    if ((uint)blk_nr <= CONCAT22(extraout_var,uVar2)) {
      return 1;
    }
    group = (aps_group_t *)(iVar3 + CONCAT22(extraout_var,uVar2) * 0x22);
    if (group == (aps_group_t *)0x0) {
      return 1;
    }
    memset(group->ep_in_grp,0,0x20);
    group->group_addr = group_addr;
  }
  uVar1 = 1 << (endpoint & 7) & 0xff;
  uVar5 = __atomic_fetch_or_1(group->ep_in_grp + (CONCAT31(in_register_0000202d,endpoint) >> 3),
                              uVar1,5);
  if ((uVar1 & uVar5) == 0) {
    aps_group_table_store_group(group);
  }
  return 0;
}

