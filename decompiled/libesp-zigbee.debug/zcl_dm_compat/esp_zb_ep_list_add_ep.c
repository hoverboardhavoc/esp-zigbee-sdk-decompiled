/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  undefined1 uStack_18;
  undefined2 uStack_16;
  esp_zb_endpoint_config_t endpoint_config_local;
  
  if (cluster_list != (esp_zb_cluster_list_t *)0x0) {
    cluster_list = cluster_list + -1;
  }
  uStack_18 = (undefined1)in_a2;
  *(undefined1 *)&cluster_list[3].cluster_list = uStack_18;
  uStack_16 = (undefined2)((uint)in_a2 >> 0x10);
  *(undefined2 *)((int)&cluster_list[3].cluster_list + 2) = uStack_16;
  endpoint_config_local._0_2_ = (undefined2)in_a3;
  *(undefined2 *)&cluster_list[4].cluster_list = endpoint_config_local._0_2_;
  *(byte *)((int)&cluster_list[4].cluster_list + 2) =
       *(byte *)((int)&cluster_list[4].cluster_list + 2) & 0xf0 | (byte)((uint)in_a3 >> 0x10) & 0xf;
  *(undefined1 *)&cluster_list->cluster_list = uStack_18;
  *(undefined2 *)((int)&cluster_list->cluster_list + 2) = uStack_16;
  cluster_list[7].cluster_list = (void *)0x0;
  ezb_af_device_add_endpoint_desc();
  eVar1 = esp_zigbee_err_to_esp();
  return eVar1;
}

