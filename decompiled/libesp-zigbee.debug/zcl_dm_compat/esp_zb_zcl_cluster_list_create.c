/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_zcl_cluster_list_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_cluster_list_t * esp_zb_zcl_cluster_list_create(void)

{
  esp_zb_cluster_list_t *peVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = 0;
  uStack_14 = 0;
  peVar1 = (esp_zb_cluster_list_t *)ezb_af_create_endpoint_desc(&uStack_18);
  if (peVar1 != (esp_zb_cluster_list_t *)0x0) {
    peVar1 = peVar1 + 1;
  }
  return peVar1;
}

