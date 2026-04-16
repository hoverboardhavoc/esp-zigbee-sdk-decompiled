/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_refresh_stored_groups
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_group_table_refresh_stored_groups(void)

{
  int iVar1;
  ezb_err_t eVar2;
  uint uVar3;
  
  iVar1 = ds_internal_remove_entry(5,0xffffffff,0);
  if (iVar1 == 0) {
    iVar1 = core_globals_get();
    uVar3 = 0;
    while ((uVar3 = bitmap_find_next_bit
                              (*(undefined4 *)(iVar1 + 0x960),*(undefined2 *)(iVar1 + 0x964),uVar3),
           uVar3 < *(ushort *)(iVar1 + 0x964) &&
           (eVar2 = aps_group_table_store_group
                              ((aps_group_t *)(*(int *)(iVar1 + 0x95c) + uVar3 * 0x22)), eVar2 == 0)
           )) {
      uVar3 = uVar3 + 1 & 0xffff;
    }
  }
  return;
}

