/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_custom_cluster_add_custom_attr
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
  undefined4 uVar1;
  esp_err_t eVar2;
  undefined2 in_register_0000202e;
  undefined3 in_register_00002031;
  undefined3 in_register_00002035;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (attr_list == (esp_zb_attribute_list_t *)0x0) {
    ebreak();
    uStack_18 = 0;
    uStack_14 = 0;
    eVar2 = ezb_af_create_endpoint_desc(&uStack_18,uRam00000000);
    if (eVar2 != 0) {
      eVar2 = eVar2 + 4;
    }
    return eVar2;
  }
  uVar1 = ezb_zcl_create_attr_desc
                    (CONCAT22(in_register_0000202e,attr_id),CONCAT31(in_register_00002031,attr_type)
                     ,CONCAT31(in_register_00002035,attr_access),0,value_p);
  if (attr_list != (esp_zb_attribute_list_t *)0x0) {
    attr_list = attr_list + -3;
  }
  ezb_zcl_cluster_add_attr_desc(attr_list,uVar1);
  eVar2 = esp_zigbee_err_to_esp();
  return eVar2;
}

