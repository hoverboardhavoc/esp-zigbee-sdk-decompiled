/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_store_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_store_reporting_info(zcl_reporting_info_t *info)

{
  uint16_t uVar1;
  uint16_t uVar2;
  ezb_err_t eVar3;
  undefined4 uStack_2c;
  dataset_zcl_reporting_info_t report_info;
  
  uStack_2c = 0;
  report_info.direction = '\0';
  report_info.ep_id = '\0';
  report_info.profile_id = 0;
  report_info._4_4_ = 0;
  report_info._8_4_ = 0;
  report_info.field_7._1_4_ = 0;
  report_info.field_7._5_4_ = 0;
  report_info.field_7.send_info.delta._1_2_ = 0;
  report_info.field_7.send_info.delta._3_1_ = 0;
  zcl_reporting_remove_stored_reporting_info(info);
  uStack_2c._0_1_ = info->direction;
  uStack_2c._1_1_ = info->ep_id;
  uStack_2c._2_2_ = info->profile_id;
  report_info.profile_id._0_1_ = info->cluster_role;
  report_info._0_2_ = info->cluster_id;
  report_info.profile_id._1_1_ = (char)info->attr_id;
  report_info.cluster_id._1_1_ = (char)info->manuf_code;
  report_info.cluster_id._0_1_ = (char)(info->attr_id >> 8);
  report_info.cluster_role = (uint8_t)(info->manuf_code >> 8);
  if (info->direction == '\0') {
    uVar1 = (info->u).send_info.min_interval;
    report_info.attr_id._0_1_ = (undefined1)uVar1;
    uVar2 = (info->u).send_info.max_interval;
    report_info.manuf_code._0_1_ = (char)uVar2;
    report_info.attr_id._1_1_ = (char)(uVar1 >> 8);
    report_info.manuf_code._1_1_ = (char)(uVar2 >> 8);
    uVar1 = (info->u).send_info.def_min_interval;
    report_info.field_7.send_info.min_interval._0_1_ = (char)uVar1;
    uVar2 = (info->u).send_info.def_max_interval;
    report_info.field_7.send_info.max_interval._0_1_ = (char)uVar2;
    report_info.field_7.send_info.min_interval._1_1_ = (char)(uVar1 >> 8);
    report_info.field_7.send_info.max_interval._1_1_ = (char)(uVar2 >> 8);
    report_info.field_7._5_4_ = *(undefined4 *)((int)&info->u + 9);
    report_info.field_7.send_info.delta._1_2_ = *(undefined2 *)((int)&info->u + 0xd);
    report_info.field_7.send_info.delta._3_1_ = *(undefined1 *)((int)&info->u + 0xf);
    report_info.field_7.send_info.def_min_interval._0_1_ = *(undefined1 *)((int)&info->u + 8);
  }
  else {
    uVar1 = (info->u).send_info.min_interval;
    report_info.attr_id._0_1_ = (undefined1)uVar1;
    report_info.attr_id._1_1_ = (char)(uVar1 >> 8);
  }
  eVar3 = ds_internal_add_entry(10,&uStack_2c,0x1b);
  return eVar3;
}

