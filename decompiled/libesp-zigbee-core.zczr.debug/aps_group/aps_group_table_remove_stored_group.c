/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_remove_stored_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_group_table_remove_stored_group(aps_group_t *group)

{
  undefined1 auStack_38 [4];
  ds_group_info_iterator_t itor;
  
  itor.data.ep_in_grp[0x1c] = '\0';
  itor.data.ep_in_grp[0x1d] = '\0';
  itor.data.ep_in_grp[0x1e] = '\0';
  ds_group_info_itor_read((ds_group_info_iterator_t *)auStack_38);
  while( true ) {
    if (itor.data.ep_in_grp[0x1e] != '\0') {
      return;
    }
    if (auStack_38._0_2_ == group->group_addr) break;
    ds_group_info_next((ds_group_info_iterator_t *)auStack_38);
  }
  ds_group_info_delete((ds_group_info_iterator_t *)auStack_38);
  return;
}

