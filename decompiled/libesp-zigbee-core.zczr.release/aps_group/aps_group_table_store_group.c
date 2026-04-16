/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_store_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_group_table_store_group(aps_group_t *group)

{
  ezb_err_t eVar1;
  ezb_shortaddr_t eStack_34;
  undefined1 auStack_32 [2];
  dataset_group_info_t group_info;
  
  memset(&eStack_34,0,0x22);
  aps_group_table_remove_stored_group(group);
  eStack_34 = group->group_addr;
  memcpy(auStack_32,group->ep_in_grp,0x20);
  eVar1 = ds_internal_add_entry(5,&eStack_34,0x22);
  return eVar1;
}

