/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> zone_table_store_zone
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
  uint8_t uStack_2f;
  uint16_t uStack_2e;
  dataset_ias_zone_info_t info;
  
  uStack_2f = entry->zone_id;
  uStack_2e = entry->zone_type;
  info._0_4_ = *(undefined4 *)&(entry->zone_address).field_0;
  info.zone_address.field_0.u64._0_4_ = *(undefined4 *)((int)&(entry->zone_address).field_0 + 4);
  info.zone_address.field_0.u8[4] = (byte)*(undefined2 *)&entry->field_0xc & 1;
  memcpy((void *)((int)&info.zone_address.field_0 + 5),entry->zone_label,0x11);
  local_30 = ep_id;
  eVar1 = ds_internal_add_entry(0xd,&local_30,0x1e);
  return eVar1;
}

