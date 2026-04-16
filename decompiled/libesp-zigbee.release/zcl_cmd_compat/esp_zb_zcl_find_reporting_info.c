/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_find_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_zcl_reporting_info_t *
esp_zb_zcl_find_reporting_info(esp_zb_zcl_attr_location_info_t *attr_info)

{
  undefined1 uVar1;
  undefined1 uVar2;
  esp_zb_zcl_reporting_info_t *peVar3;
  esp_zb_zcl_reporting_info_t *peVar4;
  
  peVar4 = (esp_zb_zcl_reporting_info_t *)
           ezb_zcl_reporting_info_find
                     (attr_info->endpoint_id,attr_info->cluster_id,attr_info->cluster_role,
                      attr_info->attr_id,attr_info->manuf_code);
  peVar3 = peVar4;
  if (peVar4 != (esp_zb_zcl_reporting_info_t *)0x0) {
    uVar1 = peVar4->direction;
    uVar2 = peVar4->ep;
    esp_zb_zcl_find_reporting_info::s_esp_zb_find_reporting_info_out.ep = uVar2;
    esp_zb_zcl_find_reporting_info::s_esp_zb_find_reporting_info_out.direction = uVar1;
    esp_zb_zcl_find_reporting_info::s_esp_zb_find_reporting_info_out.cluster_id =
         *(uint16_t *)&peVar4->cluster_role;
    esp_zb_zcl_find_reporting_info::s_esp_zb_find_reporting_info_out._5_1_ = 0;
    esp_zb_zcl_find_reporting_info::s_esp_zb_find_reporting_info_out.cluster_role = peVar4->flags;
    esp_zb_zcl_find_reporting_info::s_esp_zb_find_reporting_info_out.attr_id = peVar4->attr_id;
    esp_zb_zcl_find_reporting_info::s_esp_zb_find_reporting_info_out.manuf_code =
         (peVar4->u).send_info.def_min_interval;
    esp_zb_zcl_find_reporting_info::s_esp_zb_find_reporting_info_out.flags =
         (uint8_t)((uint)*(undefined4 *)&peVar4->flags >> 8);
    memcpy(&esp_zb_zcl_find_reporting_info::s_esp_zb_find_reporting_info_out,&peVar4->run_time,0x20)
    ;
    peVar3 = &esp_zb_zcl_find_reporting_info::s_esp_zb_find_reporting_info_out;
    esp_zb_zcl_find_reporting_info::s_esp_zb_find_reporting_info_out.info = peVar4;
  }
  return peVar3;
}

