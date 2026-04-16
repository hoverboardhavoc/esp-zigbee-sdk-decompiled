/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_ep_list_add_ep
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
  undefined4 uStack_18;
  esp_zb_endpoint_config_t endpoint_config_local;
  
  if (cluster_list == (esp_zb_cluster_list_t *)0x0) {
    ebreak();
  }
  uStack_18 = in_a2;
  memcpy(cluster_list[-1].cluster_list,&uStack_18,8);
  cluster_list[3].cluster_list = (void *)0x0;
  *(undefined1 *)&cluster_list[-3].cluster_list = (undefined1)uStack_18;
  *(undefined2 *)((int)&cluster_list[-3].cluster_list + 2) = uStack_18._2_2_;
  ezb_af_device_add_endpoint_desc(ep_list,cluster_list + -3);
  eVar1 = esp_zigbee_err_to_esp();
  return eVar1;
}

