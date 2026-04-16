/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_data_model_compat.o -> cluster_list_add_shade_config_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t cluster_list_add_shade_config_cluster
                    (esp_zb_cluster_list_t *cluster_list,esp_zb_attribute_list_t *attr_list,
                    uint8_t role_mask)

{
  undefined4 uVar1;
  esp_err_t eVar2;
  undefined *puVar3;
  
  if (cluster_list != (esp_zb_cluster_list_t *)0x0) {
    cluster_list = cluster_list + -3;
  }
  uVar1 = 2;
  if ((attr_list != (esp_zb_attribute_list_t *)0x0) &&
     (cluster_list != (esp_zb_cluster_list_t *)0x0)) {
    *(uint8_t *)((int)&attr_list[-3].attr_list + 2) = role_mask;
    if ((role_mask & 1) == 0) {
      puVar3 = &ezb_zcl_shade_config_cluster_client_init;
    }
    else {
      puVar3 = &ezb_zcl_shade_config_cluster_server_init;
    }
    attr_list[-1].attr_list = puVar3;
    zcl_cluster_desc_add_revision_attr((zcl_cluster_desc_t *)(attr_list + -3),1);
    uVar1 = ezb_af_endpoint_add_cluster_desc(cluster_list,(zcl_cluster_desc_t *)(attr_list + -3));
  }
  eVar2 = esp_zigbee_err_to_esp(uVar1);
  return eVar2;
}

