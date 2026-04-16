/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_remove_stored_child
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_neighbor_table_remove_stored_child(nwk_neighbor_t *child)

{
  undefined1 local_30 [4];
  ezb_extaddr_t child_extaddr;
  ds_child_info_iterator_t itor;
  
  ds_child_info_itor_read((ds_child_info_iterator_t *)((int)&child_extaddr.field_0 + 4));
  while ((nwk_neighbor_get_extaddr(child,(ezb_extaddr_t *)local_30),
         (undefined1  [4])itor.data._0_4_ != local_30 ||
         (itor.data.extaddr.field_0.u64._0_4_ != child_extaddr.field_0.u64._0_4_))) {
    ds_child_info_next((ds_child_info_iterator_t *)((int)&child_extaddr.field_0 + 4));
  }
  ds_child_info_delete((ds_child_info_iterator_t *)((int)&child_extaddr.field_0 + 4));
  return;
}

