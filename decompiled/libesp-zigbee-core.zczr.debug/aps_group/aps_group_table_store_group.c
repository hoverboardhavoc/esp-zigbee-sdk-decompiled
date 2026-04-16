/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_store_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_group_table_store_group(aps_group_t *group)

{
  ezb_err_t eVar1;
  undefined4 uStack_34;
  dataset_group_info_t group_info;
  
  uStack_34 = 0;
  group_info.group_addr = 0;
  group_info.ep_in_grp[0] = '\0';
  group_info.ep_in_grp[1] = '\0';
  group_info.ep_in_grp[2] = '\0';
  group_info.ep_in_grp[3] = '\0';
  group_info.ep_in_grp[4] = '\0';
  group_info.ep_in_grp[5] = '\0';
  group_info.ep_in_grp[6] = '\0';
  group_info.ep_in_grp[7] = '\0';
  group_info.ep_in_grp[8] = '\0';
  group_info.ep_in_grp[9] = '\0';
  group_info.ep_in_grp[10] = '\0';
  group_info.ep_in_grp[0xb] = '\0';
  group_info.ep_in_grp[0xc] = '\0';
  group_info.ep_in_grp[0xd] = '\0';
  group_info.ep_in_grp[0xe] = '\0';
  group_info.ep_in_grp[0xf] = '\0';
  group_info.ep_in_grp[0x10] = '\0';
  group_info.ep_in_grp[0x11] = '\0';
  group_info.ep_in_grp[0x12] = '\0';
  group_info.ep_in_grp[0x13] = '\0';
  group_info.ep_in_grp[0x14] = '\0';
  group_info.ep_in_grp[0x15] = '\0';
  group_info.ep_in_grp[0x16] = '\0';
  group_info.ep_in_grp[0x17] = '\0';
  group_info.ep_in_grp[0x18] = '\0';
  group_info.ep_in_grp[0x19] = '\0';
  group_info.ep_in_grp[0x1a] = '\0';
  group_info.ep_in_grp[0x1b] = '\0';
  aps_group_table_remove_stored_group(group);
  uStack_34 = CONCAT22(uStack_34._2_2_,group->group_addr);
  memcpy((void *)((int)&uStack_34 + 2),group->ep_in_grp,0x20);
  eVar1 = ds_internal_add_entry(5,&uStack_34,0x22);
  return eVar1;
}

