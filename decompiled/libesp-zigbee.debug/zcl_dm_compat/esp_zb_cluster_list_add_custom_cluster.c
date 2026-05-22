/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_cluster_list_add_custom_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_cluster_list_add_custom_cluster
                    (esp_zb_cluster_list_t *cluster_list,esp_zb_attribute_list_t *attr_list,
                    uint8_t role_mask)

{
  undefined4 uVar1;
  esp_err_t eVar2;
  
  if (cluster_list != (esp_zb_cluster_list_t *)0x0) {
    cluster_list = cluster_list + -1;
  }
  if (attr_list != (esp_zb_attribute_list_t *)0x0) {
    attr_list = attr_list + -3;
  }
  if (cluster_list == (esp_zb_cluster_list_t *)0x0) {
    uVar1 = 2;
  }
  else if (attr_list == (esp_zb_attribute_list_t *)0x0) {
    uVar1 = 2;
  }
  else {
    *(uint8_t *)((int)&attr_list->attr_list + 2) = role_mask;
    attr_list[2].attr_list = zb_zcl_custom_cluster_init;
    uVar1 = ezb_af_endpoint_add_cluster_desc();
  }
  eVar2 = esp_zigbee_err_to_esp(uVar1);
  return eVar2;
}

