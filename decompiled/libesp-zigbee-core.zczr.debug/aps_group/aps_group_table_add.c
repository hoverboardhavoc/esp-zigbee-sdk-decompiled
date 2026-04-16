/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_group_table_add(ezb_shortaddr_t group_addr,uint8_t endpoint)

{
  ushort blk_nr;
  uint16_t uVar1;
  undefined2 in_register_0000202a;
  aps_group_t *group;
  ezb_err_t eVar2;
  int iVar3;
  int iVar4;
  undefined2 extraout_var;
  bitmap_t *blk_busy;
  
  if ((byte)(endpoint - 1) < 0xfe) {
    if (CONCAT22(in_register_0000202a,group_addr) == 0) {
      eVar2 = 2;
    }
    else {
      group = group_table_find(group_addr);
      if (group == (aps_group_t *)0x0) {
        iVar3 = core_globals_get();
        iVar3 = *(int *)(iVar3 + 0x95c);
        iVar4 = core_globals_get();
        blk_busy = *(bitmap_t **)(iVar4 + 0x960);
        iVar4 = core_globals_get();
        blk_nr = *(ushort *)(iVar4 + 0x964);
        uVar1 = mempool_alloc_idx(blk_busy,blk_nr);
        if ((uint)blk_nr <= CONCAT22(extraout_var,uVar1)) {
          return 1;
        }
        group = (aps_group_t *)(iVar3 + CONCAT22(extraout_var,uVar1) * 0x22);
        if (group == (aps_group_t *)0x0) {
          return 1;
        }
        memset(group,0,0x22);
        group->group_addr = group_addr;
      }
      group_add_endpoint(group,endpoint);
      eVar2 = 0;
    }
  }
  else {
    eVar2 = 2;
  }
  return eVar2;
}

