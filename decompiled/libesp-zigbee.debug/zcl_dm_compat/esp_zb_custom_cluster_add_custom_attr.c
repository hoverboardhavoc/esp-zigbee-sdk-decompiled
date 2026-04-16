/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_custom_cluster_add_custom_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_custom_cluster_add_custom_attr
                    (esp_zb_attribute_list_t *attr_list,uint16_t attr_id,uint8_t attr_type,
                    uint8_t attr_access,void *value_p)

{
  esp_err_t eVar1;
  esp_zb_attribute_list_t *peVar2;
  
  if (attr_list == (esp_zb_attribute_list_t *)0x0) {
    peVar2 = (esp_zb_attribute_list_t *)0x0;
  }
  else {
    peVar2 = attr_list + -3;
  }
  eVar1 = esp_zb_cluster_add_manufacturer_attr
                    (attr_list,*(uint16_t *)&peVar2->attr_list,attr_id,0,attr_type,attr_access,
                     value_p);
  return eVar1;
}

