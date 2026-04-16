/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_ep_list_add_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

esp_err_t esp_zb_ep_list_add_ep
                    (esp_zb_ep_list_t *ep_list,esp_zb_cluster_list_t *cluster_list,
                    esp_zb_endpoint_config_t endpoint_config)

{
  esp_err_t eVar1;
  undefined4 in_a2;
  undefined4 in_a3;
  undefined1 *puVar2;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined2 uStack_16;
  esp_zb_endpoint_config_t endpoint_config_local;
  
  if (cluster_list != (esp_zb_cluster_list_t *)0x0) {
    cluster_list = cluster_list + -3;
  }
  puVar2 = (undefined1 *)cluster_list[2].cluster_list;
  uStack_18 = (undefined1)in_a2;
  uStack_17 = (undefined1)((uint)in_a2 >> 8);
  uStack_16._0_1_ = (undefined1)((uint)in_a2 >> 0x10);
  uStack_16._1_1_ = (undefined1)((uint)in_a2 >> 0x18);
  endpoint_config_local.endpoint = (uint8_t)in_a3;
  endpoint_config_local._1_1_ = (undefined1)((uint)in_a3 >> 8);
  endpoint_config_local.app_profile_id._0_1_ = (undefined1)((uint)in_a3 >> 0x10);
  endpoint_config_local.app_profile_id._1_1_ = (undefined1)((uint)in_a3 >> 0x18);
  *puVar2 = uStack_18;
  puVar2[1] = uStack_17;
  puVar2[2] = (undefined1)uStack_16;
  puVar2[3] = uStack_16._1_1_;
  puVar2[4] = endpoint_config_local.endpoint;
  puVar2[5] = endpoint_config_local._1_1_;
  puVar2[6] = (undefined1)endpoint_config_local.app_profile_id;
  puVar2[7] = endpoint_config_local.app_profile_id._1_1_;
  *(undefined1 *)&cluster_list->cluster_list = uStack_18;
  uStack_16 = (undefined2)((uint)in_a2 >> 0x10);
  *(undefined2 *)((int)&cluster_list->cluster_list + 2) = uStack_16;
  cluster_list[6].cluster_list = (void *)0x0;
  ezb_af_device_add_endpoint_desc();
  eVar1 = esp_zigbee_err_to_esp();
  return eVar1;
}

