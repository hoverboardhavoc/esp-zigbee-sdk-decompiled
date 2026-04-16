/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    peVar1 = peVar1 + 3;
  }
  return peVar1;
}

