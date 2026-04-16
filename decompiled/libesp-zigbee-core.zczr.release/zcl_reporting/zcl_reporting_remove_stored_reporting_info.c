/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_remove_stored_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_reporting_remove_stored_reporting_info(zcl_reporting_info_t *info)

{
  undefined1 auStack_30 [4];
  ds_zcl_reporting_info_iterator_t itor;
  
  itor.data.field_7.send_info.delta._5_2_ = 0;
  itor.data.field_7.send_info.delta._7_1_ = 0;
  while( true ) {
    ds_zcl_reporting_info_itor_read((ds_zcl_reporting_info_iterator_t *)auStack_30);
    if (itor.data.field_7.send_info.delta._7_1_ != '\0') {
      return;
    }
    if ((((auStack_30[1] == info->ep_id) && (itor.data._0_2_ == info->cluster_id)) &&
        ((uint8_t)itor.data.profile_id == info->cluster_role)) &&
       (((uint)info->attr_id == ((itor.data._4_4_ & 0xff) << 8 | (uint)itor.data.profile_id._1_1_)
        && ((uint)info->manuf_code == ((uint)itor.data._4_4_ >> 8 & 0xffff))))) break;
    itor.data.field_7.send_info.delta._5_2_ = itor.data.field_7.send_info.delta._5_2_ + 1;
  }
  ds_internal_remove_entry(10,auStack_30);
  return;
}

