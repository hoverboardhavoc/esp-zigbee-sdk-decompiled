/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_zcl_get_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_get_cluster(undefined4 param_1,undefined4 param_2)

{
  zb_af_get_endpoint_desc();
  get_cluster_desc(param_1,param_2);
  return;
}

