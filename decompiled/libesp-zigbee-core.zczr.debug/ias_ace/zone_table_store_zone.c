/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> zone_table_store_zone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zone_table_store_zone(uint8_t ep_id,ezb_zcl_ias_ace_zone_table_ent_t *entry)

{
  ezb_err_t eVar1;
  uint8_t local_30;
  undefined3 uStack_2f;
  dataset_ias_zone_info_t info;
  
  info._12_1_ = 0;
  info.zone_label[0] = '\0';
  info.zone_label[1] = '\0';
  info.zone_label[2] = '\0';
  info.zone_label[3] = '\0';
  info.zone_label[4] = '\0';
  info.zone_label[5] = '\0';
  info.zone_label[6] = '\0';
  info.zone_label[7] = '\0';
  info.zone_label[8] = '\0';
  info.zone_label[9] = '\0';
  info.zone_label[10] = '\0';
  info.zone_label[0xb] = '\0';
  info.zone_label[0xc] = '\0';
  uStack_2f = CONCAT21(entry->zone_type,entry->zone_id);
  local_30 = '\0';
  info._0_4_ = *(undefined4 *)&(entry->zone_address).field_0;
  info.zone_address.field_0.u64._0_4_ = *(undefined4 *)((int)&(entry->zone_address).field_0 + 4);
  info.zone_address.field_0.u64._4_4_ = (byte)*(undefined2 *)&entry->field_0xc & 0xffffff01;
  memcpy((void *)((int)&info.zone_address.field_0 + 5),entry->zone_label,0x11);
  _local_30 = CONCAT31(uStack_2f,ep_id);
  eVar1 = ds_internal_add_entry(0xd,&local_30,0x1e);
  return eVar1;
}

