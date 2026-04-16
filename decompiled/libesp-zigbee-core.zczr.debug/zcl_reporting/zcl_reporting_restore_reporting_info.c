/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_restore_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_restore_reporting_info(uint8_t ep_id)

{
  undefined3 in_register_00002029;
  ezb_err_t eVar1;
  zcl_reporting_info_t *info;
  undefined1 local_30 [4];
  ds_zcl_reporting_info_iterator_t itor;
  
  local_30[0] = '\0';
  local_30[1] = '\0';
  local_30._2_2_ = 0;
  itor.data.direction = '\0';
  itor.data.ep_id = '\0';
  itor.data.profile_id = 0;
  itor.data._4_4_ = 0;
  itor.data.attr_id._1_1_ = 0;
  itor.data.manuf_code = 0;
  itor.data.field_7.send_info.min_interval._0_1_ = 0;
  itor.data.field_7.send_info.min_interval._1_1_ = 0;
  itor.data.field_7.send_info.max_interval = 0;
  itor.data.field_7.send_info.def_min_interval._0_1_ = 0;
  itor.data.field_7._5_4_ = 0;
  itor.data.field_7.send_info.delta._1_4_ = 0;
  itor._24_4_ = 0;
  ds_zcl_reporting_info_itor_read((ds_zcl_reporting_info_iterator_t *)local_30);
  do {
    if (itor.data.field_7.send_info.delta._7_1_ != '\0') {
      return 0;
    }
    if ((uint)local_30[1] == CONCAT31(in_register_00002029,ep_id)) {
      info = zcl_reporting_info_create
                       (local_30[1],local_30._2_2_,local_30[0] != '\0',itor.data._0_2_,
                        (uint8_t)itor.data.profile_id,
                        (ushort)itor.data.profile_id._1_1_ | (ushort)((itor.data._4_4_ & 0xff) << 8)
                        ,SUB42(itor.data._4_4_,1));
      if (info == (zcl_reporting_info_t *)0x0) {
        eVar1 = 1;
_L0:
        zcl_reporting_refresh_stored_reporting_info();
        return eVar1;
      }
      if (local_30[0] == '\0') {
        (info->u).send_info.min_interval =
             CONCAT11(itor.data.attr_id._1_1_,(undefined1)itor.data.attr_id);
        (info->u).send_info.max_interval = itor.data.manuf_code;
        (info->u).send_info.def_min_interval =
             CONCAT11(itor.data.field_7.send_info.min_interval._1_1_,
                      itor.data.field_7.send_info.min_interval._0_1_);
        (info->u).send_info.def_max_interval = itor.data.field_7.send_info.max_interval;
        *(undefined1 *)((int)&info->u + 8) = itor.data.field_7.send_info.def_min_interval._0_1_;
        *(undefined1 *)((int)&info->u + 9) = itor.data.field_7.send_info.def_min_interval._1_1_;
        *(undefined1 *)((int)&info->u + 10) = itor.data.field_7.send_info.def_max_interval._0_1_;
        *(undefined1 *)((int)&info->u + 0xb) = itor.data.field_7.send_info.def_max_interval._1_1_;
        *(undefined1 *)((int)&info->u + 0xc) = itor.data.field_7.send_info.delta._0_1_;
        *(undefined1 *)((int)&info->u + 0xd) = itor.data.field_7.send_info.delta._1_1_;
        *(undefined1 *)((int)&info->u + 0xe) = itor.data.field_7.send_info.delta._2_1_;
        *(undefined1 *)((int)&info->u + 0xf) = itor.data.field_7.send_info.delta._3_1_;
      }
      else {
        (info->u).send_info.min_interval =
             CONCAT11(itor.data.attr_id._1_1_,(undefined1)itor.data.attr_id);
      }
      eVar1 = zcl_reporting_info_add(info);
      if (eVar1 != 0) {
        eVar1 = -1;
        goto _L0;
      }
    }
    ds_zcl_reporting_info_next((ds_zcl_reporting_info_iterator_t *)local_30);
  } while( true );
}

