/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> zone_table_refresh_stored_zones
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: itor */
/* WARNING: Unknown calling convention */

void zone_table_refresh_stored_zones(uint8_t ep_id)

{
  int iVar1;
  undefined3 in_register_00002029;
  int *piVar2;
  ezb_zcl_ias_ace_zone_table_ent_t *entry;
  undefined1 auStack_34 [4];
  ds_ias_zone_info_iterator_t itor;
  
  itor.data.zone_label[0xd] = '\0';
  itor.data.zone_label[0xe] = '\0';
  itor.data.zone_label[0xf] = '\0';
  ds_ias_zone_info_itor_read((ds_ias_zone_info_iterator_t *)auStack_34);
  while (itor.data.zone_label[0xf] == '\0') {
    if ((uint)auStack_34[0] == CONCAT31(in_register_00002029,ep_id)) {
      ds_ias_zone_info_delete((ds_ias_zone_info_iterator_t *)auStack_34);
      ds_ias_zone_info_itor_read((ds_ias_zone_info_iterator_t *)auStack_34);
    }
    else {
      ds_ias_zone_info_next((ds_ias_zone_info_iterator_t *)auStack_34);
    }
  }
  piVar2 = (int *)ezb_zcl_ias_ace_get_zone_table(ep_id);
  iVar1 = 0;
  while ((iVar1 < (int)(uint)*(byte *)(piVar2 + 1) &&
         (entry = (ezb_zcl_ias_ace_zone_table_ent_t *)(*piVar2 + iVar1 * 0x1e),
         entry->zone_type != 0xffff))) {
    zone_table_store_zone(ep_id,entry);
    iVar1 = iVar1 + 1;
  }
  return;
}

