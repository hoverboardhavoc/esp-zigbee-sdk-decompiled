/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_find_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_zcl_reporting_info_t *
esp_zb_zcl_find_reporting_info(esp_zb_zcl_attr_location_info_t *attr_info)

{
  esp_zb_zcl_reporting_info_t *src;
  
  src = (esp_zb_zcl_reporting_info_t *)
        ezb_zcl_reporting_info_find
                  (attr_info->endpoint_id,attr_info->cluster_id,attr_info->cluster_role,
                   attr_info->attr_id,attr_info->manuf_code);
  if (src != (esp_zb_zcl_reporting_info_t *)0x0) {
    convert_to_esp_zb_zcl_reporting_info
              (&esp_zb_zcl_find_reporting_info::s_esp_zb_find_reporting_info_out,
               (ezb_zcl_reporting_info_temp_t *)src);
    src = &esp_zb_zcl_find_reporting_info::s_esp_zb_find_reporting_info_out;
  }
  return src;
}

