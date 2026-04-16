/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> zone_table_remove_stored_zone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zone_table_remove_stored_zone(uint8_t ep_id,uint8_t zone_id)

{
  undefined3 in_register_00002029;
  ezb_err_t eVar1;
  undefined3 in_register_0000202d;
  undefined1 auStack_34 [4];
  ds_ias_zone_info_iterator_t itor;
  
  itor.data.zone_label[0xd] = '\0';
  itor.data.zone_label[0xe] = '\0';
  itor.data.zone_label[0xf] = '\0';
  ds_ias_zone_info_itor_read((ds_ias_zone_info_iterator_t *)auStack_34);
  while( true ) {
    if (itor.data.zone_label[0xf] != '\0') {
      return 5;
    }
    if (((uint)auStack_34[0] == CONCAT31(in_register_00002029,ep_id)) &&
       ((uint)auStack_34[1] == CONCAT31(in_register_0000202d,zone_id))) break;
    ds_ias_zone_info_next((ds_ias_zone_info_iterator_t *)auStack_34);
  }
  eVar1 = ds_ias_zone_info_delete((ds_ias_zone_info_iterator_t *)auStack_34);
  return eVar1;
}

