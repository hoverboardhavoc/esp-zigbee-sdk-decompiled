/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_cluster_add_manufacturer_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_cluster_add_manufacturer_attr
                    (esp_zb_attribute_list_t *attr_list,uint16_t cluster_id,uint16_t attr_id,
                    uint16_t manuf_code,uint8_t attr_type,uint8_t attr_access,void *value_p)

{
  undefined4 uVar1;
  esp_err_t eVar2;
  undefined2 in_register_00002032;
  undefined3 in_register_00002039;
  undefined3 in_register_0000203d;
  
  uVar1 = ezb_zcl_create_attr_desc
                    (CONCAT22(in_register_00002032,attr_id),CONCAT31(in_register_00002039,attr_type)
                     ,CONCAT31(in_register_0000203d,attr_access),value_p);
  if (attr_list != (esp_zb_attribute_list_t *)0x0) {
    attr_list = attr_list + -3;
  }
  ezb_zcl_cluster_add_attr_desc(attr_list,uVar1);
  eVar2 = esp_zigbee_err_to_esp();
  return eVar2;
}

